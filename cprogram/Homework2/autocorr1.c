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
#define MAX_LINES 1500000

int main(int argc, char *argv[]){
  float nums[MAX_LINES]; // create an float array with max line 1500000
  int i;
  int t, tp, tmax;   // data relate to time sequence
  float ft, st, tt;  // First term, second term, third term of autocorrelation function
  float autot, normalized; // auto correlation function at time t, normalized auto correlation at time t

  float *a;  // array of autocorrelation function

  FILE *infile;   // pointer to inputfile
  FILE *outfile;	// pointer to outputfile

  if (argc == 3){
    fprintf(stderr,"\n Good Initializtion:\n");
  }
  else {			// error in value of argc 
    fprintf(stderr,"\n Initialization error:\n");
    fprintf(stderr,"Usage: autocorr1.x infile outfile\n");  // correct input syntax 
    return 1;
  }

  if (infile = fopen(argv[1],"r"))
  {
    i = 0;
    t = 0;
    tp = 0;
    tmax = 0;
    ft = 0;
    st = 0;
    tt = 0;

    // Read all lines in the file and save into num array
    while (fscanf(infile, "%f", &nums[i]) != EOF ){
      i++;
      tmax++;}
    fclose(infile);

    a = vector(0,tmax);                 // use NR subroutine to allocate memory for the array a[]
    for(i=0; i<=tmax; ++i){a[i]=0;}    // initialize autocorrelation array

    // Get autocorrelation function
    for (t=0; t<tmax; ++t){
      for (tp=0; tp<tmax-t; ++tp)
      {
        ft = ft + nums[tp]*nums[tp+t];
        st = st + nums[tp];
        tt = tt + nums[tp+t];
      }
      autot = ft/(tmax -t) - st*tt/((tmax -t)*(tmax -t));
      a[t] = autot;
      autot = 0;
      ft = 0;
      st = 0;
      tt = 0;
    }

    // save the autocorrelation
    outfile = fopen(argv[2],"w");
    for (t=0; t<tmax; t++){
      normalized = a[t]/a[0];
      fprintf(outfile, "%d, %f, %d, %f \n", t, normalized, t, a[t]);
    }
    fclose(outfile);

    free_vector(a,0,tmax);
  }
  else{ fprintf(stderr,"No such input file \n"); return 1;}

  return 0;
}