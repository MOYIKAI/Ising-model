// Simple C example program that performs historgram binning
// by Yi-Kai Mo, originally written 8/2022
//
// Program uses Numerical Recipies (NR) arrays, random numbers, 
// and uses simple graphics to show the evolution of the lattice.
//
// Parameters:
// inputfile - data need to be binning
// outfile   - output histogram

#include <stdio.h>	  // standard io library
#include <string.h>   // standard string library
#include <stdlib.h>	  // standard library with lots of functions
#include <math.h>	    // standard math library
#define NRANSI		    // needed for NR
#include "my_nrutil.h"    // include NR header files


int main(int argc, char *argv[]){ 
  double *nums; // array for data
  double tau;   // correlaiton time
  double dt;    // measurement between time
  double mQabs, Qabs, eQabs, mQ, Q, eQ, mQQ, QQ, eQQ, mQQQQ, QQQQ, eQQQQ;
  int i, lnum;

  FILE *infile;   // pointer to inputfile
  FILE *outfile;	// pointer to outputfile
  FILE *tfile;    // pointer to correlation time file

  if (argc == 5){
    fprintf(stderr,"\n Good Initializtion:\n");
    dt  = atof(argv[1]);
  }
  else {			// error in value of argc 
    fprintf(stderr,"\n Initialization error:\n");
    fprintf(stderr,"Usage: mean.x dt(time between measurement) taufile infile outfile \n");  // correct input syntax 
    return 1;
  }

  if ((infile = fopen(argv[3],"r")) && (tfile = fopen(argv[2],"r"))) // check if both tau file and infile exist.
  {
    fscanf(tfile, "%lf", &tau); // read the only line in taufile
    i = 0;
    Q = 0;  // sum of Q
    QQ = 0; // sum of Q^2
    lnum = 0; // numbers of element in num array
    nums = dvector(0,10000000);

    // Read all lines in the file and save into num array
    while (fscanf(infile, "%lf", &nums[i]) != EOF ){i++;lnum++;}
    fclose(infile);

    for (i = 0; i < lnum; i++)
    {
      if(nums[i] > 0){Qabs = Qabs+nums[i];}
      else{Qabs = Qabs-nums[i];}
      Q = Q + nums[i];
      QQ = QQ + nums[i]*nums[i];
      QQQQ = QQQQ + nums[i]*nums[i]*nums[i]*nums[i];
    }

    mQabs = Qabs/lnum;
    mQ = Q/lnum;
    mQQ = QQ/lnum;
    mQQQQ = QQQQ/lnum;

    eQabs = sqrt((1+2.0*tau)*(mQQ - mQabs*mQabs)/(lnum-1));
    eQ = sqrt((1+2.0*tau)*(mQQ - mQ*mQ)/(lnum-1));
    eQQ = sqrt((1+2.0*tau)*(mQQQQ - mQQ*mQQ)/(lnum-1));

    // Print the histogram value out
    outfile = fopen(argv[4],"w");
    fprintf(outfile, "%lf, %lf, %lf, %lf, %lf, %lf\n", mQ, eQ, mQQ, eQQ, mQabs, eQabs);
    fclose(outfile);
    printf("%lf, %lf, %lf, %lf, %lf, %lf\n", mQ, eQ, mQQ, eQQ, mQabs, eQabs);

    free_dvector(nums,0,10000000);
  }
  else{ fprintf(stderr,"No such input file \n"); return 1;}

  return 0;
}