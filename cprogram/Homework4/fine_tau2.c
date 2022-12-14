// Simple C example program that performs historgram binning
// by Yi-Kai Mo, originally written 8/2022
//
// Program uses Numerical Recipies (NR) arrays, random numbers, 
//
// Parameters:
// inputfile - data Magnetization per sweep
// outfile   - data need to be saved L T t Xl x y

#include <stdio.h>	  // standard io library
#include <string.h>   // standard string library
#include <stdlib.h>	  // standard library with lots of functions
#include <math.h>	    // standard math library
#define NRANSI		    // needed for NR
#include "my_nrutil.h"    // include NR header files


int main(int argc, char *argv[]){ 
  double *nums; // array for data
  double dummy; // dummy variable
  double mQ, mQQ, Q, QQ;
  double v, r, T, Tc, t, Xl, x, y; // parameter for
  double L, N;
  int i, j, lnum, tau;
  

  FILE *infile;   // pointer to inputfile
  FILE *outfile;	// pointer to outputfile
  FILE *tfile;  // correlation time

  if (argc == 9){
    //fprintf(stderr,"\n Good Initializtion:\n");
    L  = atof(argv[1]);
    T  = atof(argv[2]);
    Tc = atof(argv[3]);
    v  = atof(argv[4]);
    r  = atof(argv[5]);
  }
  else {			// error in value of argc 
    fprintf(stderr,"\n Initialization error:\n");
    fprintf(stderr,"Usage: fine_tau.x L T Tc v r infile outfile tfile \n");  // correct input syntax 
    return 1;
  }

  if ( (infile = fopen(argv[6],"r")) && (tfile = fopen(argv[8],"r"))) // check if both tau file and infile exist.
  {
    fscanf(tfile, "%lf", &dummy); // read the only line in taufile
    tau = (int)(dummy+1);
    N = L*L;
    t = (T-Tc)/Tc;
    i = 0;
    j = 0;
    Q = 0;  // sum of Q
    QQ = 0; // sum of Q^2
    lnum = 0; // numbers of element in num array
    nums = dvector(0,100000000);
    fscanf(tfile, "%lf", &tau);

    // Read all lines in the file and save into num array
    while (fscanf(infile, "%lf", &dummy) != EOF )
    {
      nums[lnum] = dummy/(L*L);
      lnum++;
    }
    fclose(infile);

    for (i = 0; i < lnum; i=i+tau)
    {
      j = j+1;
      if  ( nums[i] > 0){Q = Q + nums[i];}
      else{ Q = Q - nums[i];}
      
      QQ = QQ + nums[i]*nums[i];
    }

    mQ  = Q/j;
    mQQ = QQ/j;
    Xl  = ((mQQ - mQ*mQ)*N)/T;
    x = pow(L, (1/v))*t;
    y = pow(L, (-r/v))*Xl;

    // printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", x, y, L, T, t, Xl, mQ, mQQ);

    // Print t*L^(1/v), L^(-r/v)*Xl, L, T, t, Xl 
    outfile = fopen(argv[7],"w");
    fprintf(outfile, "%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", x, y, L, T, t, Xl, mQ, mQQ);
    fclose(outfile);

    free_dvector(nums,0,100000000);
  }
  else{ fprintf(stderr,"No such input file \n"); return 1;}

  return 0;
}