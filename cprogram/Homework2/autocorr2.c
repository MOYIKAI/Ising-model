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
  float data[MAX_LINES]; // create an float array with max line 1500000
  int i;
  int t, tp, tmax;   // data relate to time sequence
  float ft, st, tt;  // First term, second term, third term of discrete autocorrelation function
  float autot, normalized; // auto correlation function at time t, normalized auto correlation at time t


  float *a;  // array of autocorrelation function


  FILE *infile;   // pointer to inputfile
  FILE *outfile;	// pointer to outputfile

  if (argc == 3){
    fprintf(stderr,"\n Good Initializtion:\n");
  }
  else {			// error in value of argc 
    fprintf(stderr,"\n Initialization error:\n");
    fprintf(stderr,"Usage: autocorr2.x infile outfile\n");  // correct input syntax 
    return 1;
  }

  if (infile = fopen(argv[1],"r"))
  {
    // initialize parameters
    i = 0;
    t = 0;
    tp = 0;
    tmax = 0;
    ft = 0;
    st = 0;
    tt = 0;
    autot = 0;


    // Read all lines in the file and save into num array
    while (fscanf(infile, "%f", &data[i]) != EOF ){
      i++;
      tmax++;}
    fclose(infile);


    a = vector(0,tmax);                // use NR subroutine to allocate memory for the array a[]
    for(i=0; i<=tmax; ++i){a[i]=0;}    // initialize autocorrelation array


    // Get autocorrelation function truncate at autocorrelation coefficient lesser than 0
    while (t < tmax && autot >= 0 )
    {
      for (tp=0; tp<tmax-t; ++tp)
      {
        ft = ft + data[tp]*data[tp+t];
        st = st + data[tp];
        tt = tt + data[tp+t];
      }
      autot = ft/(tmax -t) - st*tt/((tmax -t)*(tmax -t));
      a[t] = autot;
      ft = 0;
      st = 0;
      tt = 0;
      t = t+1;
    }

    // save the autocorrelation function
    t=0;
    outfile = fopen(argv[2],"w");
    while (t < tmax && a[t] >= 0 )
    {
      normalized = a[t]/a[0];
      fprintf(outfile, "%d, %f\n", t, normalized);
      t++;
    }
    fclose(outfile);

    free_vector(a,0,tmax);

  }
  else{ fprintf(stderr,"No such input file \n"); return 1;}

  return 0;
}