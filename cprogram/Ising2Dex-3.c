// Simple C example program that performs a Metropolis Monte Carlo Simulation with "Glauer" dynamics of 2 dimensional Ising model on a square lattice with periodic boundary conditions.
// Version 3: Includes a magnetic field in the simulation and measurment for MI(Mutual information).
// by Kevin E Bassler, originally written 11/2021, after modified by Yi-Kai May. 23, 2023
//
// Program uses Numerical Recipies (NR) arrays, random numbers, 
// and uses simple graphics to show the evolution of the lattice.
//
// Parameters:
// L - linear extent of the lattice. (N = L*L total spins)
// T - temperature (real number)
// h - magnetic field (real number)
// seed - random number seed (should be a [large] negative integer)
//
//

#include <stdio.h>	  // standard io library
#include <stdlib.h>	  // standard library with lots of functions
#include <math.h>	  // standard math library
#define NRANSI		  // needed for NR
#include "my_nrutil.h"    // include NR header files

long L, N;
double T, h;
long seed;
int **A;		// dimension pointer to pointer to int (needed for NR imatrix subroutine)
double *Boltz, *hBoltz;


double calc_E();
double calc_M();
double calc_S();
double calc_jS();
double calc_mi();
void initA();
void plotA();
int MCmove(int i, int j);
float ran2(long *idum);	  // typecast ran2

int main(int argc, char *argv[]){   // argc and argv used for command line input
  int rint, i, j;
  int accepted, show;
  long t, tmax;
  double E,M,S,jS,mi; // variables in the system

  FILE *outfile;	// pointer to filename

  if (argc == 7){		// require argc be equal to number of command line entries
    L = atol(argv[1]);		// read long variable from command line spot 1
    T = atof(argv[2]);		// read double variable
    h = atof(argv[3]);		// read double variable
    seed = atol(argv[4]);
    tmax = atol(argv[5]);
    show = atol(argv[6]);
  } else {			// error in value of argc 
    fprintf(stderr,"\n Initialization error:\n");
    fprintf(stderr,"Usage: Ising2D.x L T h seed tmax show\n");  // correct input syntax
    
    return 1;
  }
  
  N = L*L;					// number of total nodes
  A = imatrix(0,L-1,0,L-1);			// use NR subroutine to allocate memory for the array A[i][j], where i and j in range [0, N-1]
  initA();					// initialize lattice A

  Boltz = dvector(-2,2);
  for (i=-2; i<=2; ++i) Boltz[i] = exp(-4.0*i/T);
  hBoltz = dvector(-1,1);
  for (i=-1; i<=1; ++i) hBoltz[i] = exp(-h*i/T);
  if( show == 1 ){
    E = calc_E();
    M = calc_M();
    S = calc_S();
    jS = calc_jS();
    mi = calc_mi();
    printf("Initial configuration: \n");
    plotA();
    printf("E:%lf\tM:%lf\tS:%lf\tjS:%lf\tmi:%lf \n", E, M, S, jS, mi);
    getchar();
  }

  for (t=1; t<=tmax; ++t){
    rint = N*ran2(&seed);
    i = rint/L;
    j = rint%L;

    accepted = MCmove(i,j);
  }
  
  if (show == 1) {plotA();}
  E = calc_E();
  M = calc_M();
  S = calc_S();
  jS = calc_jS();
  mi = calc_mi();
  printf("%lf\t%lf\t%lf\t%lf\t%lf \n", E, M, S, jS, mi);
  free_imatrix(A,0,L-1,0,L-1);			// NR subroutine to free allocated memory 
  free_dvector(Boltz,-2,2);
  free_dvector(hBoltz,-1,1);

  return 0;
}

// calculate the energy of the lattice
double calc_E() {
  int i, j;
  int ip,im,jp,jm;
  double energy = 0;
 
  for (i = 0; i < L; i++) {
    for (j = 0; j < L; j++) {
      ip = (i+1)%L;
      im = (i-1+L)%L;
      jp = (j+1)%L;
      jm = (j-1+L)%L;
      energy -= (A[ip][j] + A[i][jp] + A[im][j] + A[i][jm])*A[i][j];
    }
  }
  return energy / 2.00 ;
}

// calculate the magnetization of the lattice
double calc_M() {
  int i, j;
  double magnetization = 0;
  for (i = 0; i < L; i++) {
    for (j = 0; j < L; j++) {magnetization += A[i][j];}
  }
  return magnetization ;
}

// calculate the entropy of the system
double calc_S() {
  int i, j, n;
  double entropy = 0;
  double p[2] = {0}; // probability distribution

  for (i = 0; i < L; i++) {
    for (j = 0; j < L; j++) {
      n = A[i][j] > 0 ? 1 : 0; // convert spin value to 0 or 1
      p[n]++;
    }
  }

  for (i = 0; i < 2; i++) {
    if (p[i] > 0) {
      p[i] /= (L * L); // normalize probabilities
      entropy -= p[i] * log2(p[i]); // calculate contribution to entropy
    }
  }

  return entropy;
}

// Function to calculate the joint entropy of the lattice
double calc_jS() {
  int i,j;
  int count[2][2] = {0};
  double joint_entropy = 0.0;

  // Count occurrences of spin pairs
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < L; j++) {
      int x = (A[i][j] == 1) ? 1 : 0;
      int y = (A[(i + 1) % L][j] == 1) ? 1 : 0;
      count[x][y]++;
      }
  }

  // Calculate joint entropy
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      double p = (double)count[i][j] / N;
      if (p > 0.0) {joint_entropy -= p * log2(p);}
      }
  }

  return joint_entropy;
}

// Function to calculate the mutual information between two variables
double calc_mi() {
  double mi = 0.0;
  int x_count[2] = {0}, y_count[2] = {0}, xy_count[2][2] = {0};
  int i, j, x, y;

  // Count occurrences of x and y and their combinations
  for (i = 0; i < L; i++) {
    for (j = 0; j < L; j++) {
      x = (A[i][j] == 1) ? 1 : 0;
      y = (A[(i + 1) % L][j] == 1) ? 1 : 0;
      x_count[x]++;
      y_count[y]++;
      xy_count[x][y]++;
    }
  }
  // Calculate mutual information
  for (x = 0; x < 2; x++) {
    for (y = 0; y < 2; y++) {
      double p_xy = (double)xy_count[x][y] / N;
      double p_x = (double)x_count[x] / N;
      double p_y = (double)y_count[y] / N;
      if (p_xy > 0.0) {mi += p_xy * log2(p_xy / (p_x * p_y));}
    }
  }

  return mi;
}

// simulation by "Glauer" dynamics
int MCmove(int i, int j){
  double roll;
  int ip,im,jp,jm;
  int nsum;

  ip = (i+1)%L;
  im = (i-1+L)%L;
  jp = (j+1)%L;
  jm = (j-1+L)%L;
  nsum = (A[ip][j] + A[i][jp] + A[im][j] + A[i][jm])*A[i][j];

  roll = ran2(&seed);
  if (roll < Boltz[nsum/2]*hBoltz[A[i][j]]) {
    A[i][j] *= -1;
    return 1;
  } else return 0;
}

// intialize the lattice
void initA(){
  long i,j;
  float roll;
  for (i=0; i<L; ++i){
    for (j=0; j<L; ++j){
      roll = ran2(&seed);
      if (roll < 0.5){
        A[i][j] = 1;
      } else {
        A[i][j] = -1;
      }
    }
  }
  return;
}

// plot lattice information
void plotA(){
  long i,j;
  for (i=0; i<L; ++i){
    for (j=0; j<L; ++j){
      if (A[i][j] == -1) fprintf(stderr,"- ");
      else fprintf(stderr,"+ ");
    }
    fprintf(stderr,"\n");
  }
  fprintf(stderr,"\n\n");

  return;
}

// below is a NR random number generator. It generated float numbers evenly over range [0,1)
#define IM1 2147483563
#define IM2 2147483399
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

float ran2(long *idum)
{
	int j;
	long k;
	static long idum2=123456789;
	static long iy=0;
	static long iv[NTAB];
	float temp;

	if (*idum <= 0) {
		if (-(*idum) < 1) *idum=1;
		else *idum = -(*idum);
		idum2=(*idum);
		for (j=NTAB+7;j>=0;j--) {
			k=(*idum)/IQ1;
			*idum=IA1*(*idum-k*IQ1)-k*IR1;
			if (*idum < 0) *idum += IM1;
			if (j < NTAB) iv[j] = *idum;
		}
		iy=iv[0];
	}
	k=(*idum)/IQ1;
	*idum=IA1*(*idum-k*IQ1)-k*IR1;
	if (*idum < 0) *idum += IM1;
	k=idum2/IQ2;
	idum2=IA2*(idum2-k*IQ2)-k*IR2;
	if (idum2 < 0) idum2 += IM2;
	j=iy/NDIV;
	iy=iv[j]-idum2;
	iv[j] = *idum;
	if (iy < 1) iy += IMM1;
	if ((temp=AM*iy) > RNMX) return RNMX;
	else return temp;
}
#undef IM1
#undef IM2
#undef AM
#undef IMM1
#undef IA1
#undef IA2
#undef IQ1
#undef IQ2
#undef IR1
#undef IR2
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX
/* (C) Copr. 1986-92 Numerical Recipes Software *1(.|a. */
