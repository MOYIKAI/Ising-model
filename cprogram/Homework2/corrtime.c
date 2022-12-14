// Simple C example program that performs correlation time
// by Yi-Kai Mo, originally written 9/2022
//
// Program uses Numerical Recipies (NR) arrays, random numbers, 
// and uses simple graphics to show the evolution of the lattice.
//
// Parameters:
// inputfile - input file should have two columns which has the form "%f, %f\n"
// outfile   - output file correlation time

#include <stdio.h>	  // standard io library
#include <string.h>   // standard string library
#include <stdlib.h>	  // standard library with lots of functions
#include <math.h>	    // standard math library
#define NRANSI		    // needed for NR
#include "my_nrutil.h"    // include NR header files
#define MAX_LINES 20000

int main(int argc, char *argv[]){
  float corr[MAX_LINES], time[MAX_LINES]; // create an float array with max line 20000
  int t, tmax;    // data relate to time sequence
  float dt, fx;   // time difference, data mean
  float tau;      // auto correlation time tau

  float *a;       // array of autocorrelation function

  FILE *infile;   // pointer to inputfile
  FILE *outfile;  // pointer to outputfile

  if (argc == 3){
    fprintf(stderr,"\n Good Initializtion:\n");
  }
  else {			// error in value of argc 
    fprintf(stderr,"\n Initialization error:\n");
    fprintf(stderr,"Usage: autocorr.x infile outfile\n");  // correct input syntax 
    return 1;
  }

  if (infile = fopen(argv[1],"r"))
  {
    t = 0;
    tmax = 0;
    tau = 0;

    // Read all lines in the file and save into time and corr array
    while (fscanf(infile, "%f, %f\n", &time[t], &corr[t]) != EOF ){
      t++;
      tmax++;
      }
    fclose(infile);
    
    // discrete integration to find tau
    for (t = 0; t < tmax - 1; t++)
    {
      dt = time[t+1]-time[t];
      fx = (corr[t+1]+corr[t+1])/2;
      tau = tau + fx*dt;
    }

    printf("Correlation time: %f\n", tau);

    // save correlation time into file
    outfile = fopen(argv[2],"w");
    fprintf(outfile, "%f\n", tau);
    fclose(outfile);
  }

  else{ fprintf(stderr,"No such input file \n"); return 1;}

  return 0;
  }