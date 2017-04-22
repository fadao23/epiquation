//crout.h a set of function to solve linear equation

# ifndef _EPIQUATION_CROUT_H_
# define _EPIQUATION_CROUT_H_

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "../controller/erreur.h"

float *vector(long nh);
void ludcmp(float *a, int n, int *indx);
void lubksb(float *a, int n, int *indx, float b[]);

# endif  /*_EPIQUATION_CROUT_H_*/
