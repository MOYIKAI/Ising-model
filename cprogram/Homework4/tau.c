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

int main(int argc, char *argv[]){
  int t, tmax;    // data relate to time sequence
  
  double dt, fx;   // time difference, data mean
  double tau;      // auto correlation time tau

  double *corr;   // correlation data
  double *time;   // time 

  FILE *infile;   // pointer to inputfile
  FILE *outfile;  // pointer to outputfile

  if (argc == 3){}
  else {			// error in value of argc 
    fprintf(stderr,"\n Initialization error:\n");
    fprintf(stderr,"Usage: tau.x infile outfile\n");  // correct input syntax 
    return 1;
  }

  if (infile = fopen(argv[1],"r"))
  {
    corr = dvector(0,20000000);
    time = dvector(0,20000000);
    t = 0;
    tmax = 0;
    tau = 0;

    // Read all lines in the file and save into time and corr array
    while (fscanf(infile, "%lf, %lf\n", &time[t], &corr[t]) != EOF ){
      t++;
      tmax++;
      }
    fclose(infile);
    
    // discrete integration to find tau
    for (t = 0; t < tmax - 1; t++)
    {
      dt = time[t+1]-time[t];
      fx = (corr[t+1]+corr[t])/2;
      tau = tau + fx*dt;
    }

    // save correlation time into file
    outfile = fopen(argv[2],"w");
    fprintf(outfile, "%f\n", tau);
    fclose(outfile);

    free_dvector(time,0,20000000);
    free_dvector(corr,0,20000000);

  }

  else{ fprintf(stderr,"No such input file \n"); return 1;}

  return 0;
  }