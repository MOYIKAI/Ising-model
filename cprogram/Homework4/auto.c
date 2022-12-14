// Simple C example program that performs autocorrelation
// by Yi-Kai Mo, originally written 9/2022
//
// Program uses Numerical Recipies (NR) arrays, random numbers, 
// and uses simple graphics to show the evolution of the lattice.
//
// Parameters:
// inputfile - input file should one column which has the form "%f\n"
// outfile   - output file correlation function

#include <stdio.h>	  // standard io library
#include <string.h>   // standard string library
#include <stdlib.h>	  // standard library with lots of functions
#include <math.h>	    // standard math library
#define NRANSI		    // needed for NR
#include "my_nrutil.h"    // include NR header files

int main(int argc, char *argv[]){
  long L; // lattice size
  int t, tp, tmax;   // data relate to time sequence
  double dummy;         // dummy variable
  double ft, st, tt;  // First term, second term, third term of discrete autocorrelation function
  double autot, normalized; // auto correlation function at time t, normalized auto correlation at time t

  double *d;   // array of data
  double *a;  // array of autocorrelation function

  FILE *infile;   // pointer to inputfile
  FILE *outfile;	// pointer to outputfile

  if (argc == 4){
    L = atol(argv[1]);		// read long variable from command line spot 1
  }
  else {			// error in value of argc 
    fprintf(stderr,"\n Initialization error:\n");
    fprintf(stderr,"Usage: autocorr2.x L(lattice size) infile outfile\n");  // correct input syntax 
    return 1;
  }

  if (infile = fopen(argv[2],"r"))
  {
    // initialize parameters
    t = 0;
    tp = 0;
    tmax = 0;
    ft = 0;
    st = 0;
    tt = 0;
    autot = 0;

    d = dvector(0,100000000); 

    // Read all lines in the file and save into num array
    while (fscanf(infile, "%lf", &dummy) != EOF )
    {
      d[tmax] = dummy/(L*L); // normalize the data from the lattice size
      tmax++;
    }
    fclose(infile);

    a = dvector(0,tmax); // use NR subroutine to allocate memory for the array a[]

    // Get autocorrelation function truncate at autocorrelation coefficient lesser than 0
    while (t < tmax && autot >= 0 )
    {
      for (tp=0; tp<tmax-t; ++tp)
      {
        ft = ft + d[tp]*d[tp+t];
        st = st + d[tp];
        tt = tt + d[tp+t];
        
      }
      ft = ft/(tmax -t);
      st = st/(tmax -t);
      tt = tt/(tmax -t);
      autot =  ft - st*tt;
      a[t] = autot;
      ft = 0;
      st = 0;
      tt = 0;
      t = t+1;
      
    }

    // save the autocorrelation function
    t=0;
    outfile = fopen(argv[3],"w");
    while ( t < tmax && a[t] >= 0 )
    {
      normalized = a[t]/a[0];
      fprintf(outfile, "%d, %f\n", t, normalized);
      t++;
    }
    fclose(outfile);

    free_dvector(a,0,tmax);
    free_dvector(d,0,100000000);

  }
  else{ fprintf(stderr,"No such input file \n"); return 1;}

  return 0;
}