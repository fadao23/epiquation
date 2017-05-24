#include <math.h>
#include "nrutil.h"
#define CON 1.4   //Stepsize is decreased  by CON at each iteration.
#define CON2 (CON*CON)
#define BIG 1.0e30
#define NTAB 10   //Sets  maximum  size  of  tableau.
#define SAFE 2.0  // Return  when  error  is SAFE worse  than  the  best  so far.


float dfridr(float (*func)(float), float x, float h, float *err)
  /*Returns  the  derivative  of  a  function func at  a  point x by  Ridders’
    method  of  polynomial extrapolation.  The  value his  input  as  an  estimated
    initial  stepsize;  it  need  not  be  small,  but rather  should  be  an
    increment  in x over  which func changes substantially. Anestimateofthe error
    in  the  derivative  is  returned  as err. */
{
  int i,j;
  float errt,fac,hh,**a,ans;
  if (h == 0.0) nrerror("h must be nonzero in dfridr.");
  a=matrix(1,NTAB,1,NTAB);
  hh=h;
  a[1][1]=((*func)(x+hh)-(*func)(x-hh))/(2.0*hh);
  *err=BIG;
  for (i=2;i<=NTAB;i++) {
    /*Successive  columns  in the  Neville tableau  will go to  smaller stepsizes  and higher  orders  of
      extrapolation.*/
    hh /= CON;
    a[1][i]=((*func)(x+hh)-(*func)(x-hh))/(2.0*hh); //Try  new,  smaller  step-size.
    fac=CON2;
    for (j=2;j<=i;j++) {
      // Compute  extrapolations  of  various  orders,  requiring  no new function eval-uations.
      a[j][i]=(a[j-1][i]*fac-a[j-1][i-1])/(fac-1.0);
      fac=CON2*fac;
      errt=FMAX(fabs(a[j][i]-a[j-1][i]),fabs(a[j][i]-a[j-1][i-1]));
      /* The error strategy is to compare each new extrapolation to one order lower, both
         at  the  present  stepsize  and  the  previous  one.*/
      if (errt <= *err) {
        /*If error is decreased,  save the improved answer.*/
          *err=errt;
        ans=a[j][i];
      }
    }
    if (fabs(a[i][i]-a[i-1][i-1]) >= SAFE*(*err)) break;
    /*If higher  order  is  worse  by  a  significant  factor SAFE,  then  quit  
    early.*/
  }
  free_matrix(a,1,NTAB,1,NTAB);
  return ans;
}
