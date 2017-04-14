#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define TINY 1.0e-20  //A small number.

void nrerror(char error_text[])
/* Numerical Recipes standard error handler */
{
	fprintf(stderr,"Numerical Recipes run-time error...\n");
	fprintf(stderr,"%s\n",error_text);
	fprintf(stderr,"...now exiting to system...\n");
	exit(1);
}

float *vector(long nl, long nh)
/* allocate a float vector with subscript range v[nl..nh] */
{
	float *v;

	v=(float *)malloc((size_t) ((nh-nl+2)*sizeof(float)));
	if (!v) nrerror("allocation failure in vector()");
	return v-nl+1;
}

void free_vector(float *v, long nl, long nh)
/* free a float vector allocated with vector() */
{
	free((char*) (v+nl-1));
}

void ludcmp(float **a, int n, int *indx, float *d)
{
	/*
		a -> matrice carre remplacer en sortie par sa LU decomposition permutee
		n -> taille de la matrice
		indx -> vecteur qui sauvegarde les permutations
		d -> vaut 1 si le nombre de permutation et pair, -1 sinon
	*/
  int i,imax,j,k;
  float big,dum,sum,temp;
  float *vv;         //vv contient le coef multiplicateur de chaque ligne.
  vv=vector(1,n);
  *d=1.0;            //No row interchanges yet.
  for (i=1;i<=n;i++) { //Loop over rows to get the implicit scaling information.
    big=0.0;
    for (j=1;j<=n;j++)
      if ((temp=fabs(a[i][j])) > big) big=temp;
    if (big == 0.0) nrerror("Singular matrix in routine ludcmp");
    //No nonzero largest element.
    vv[i]=1.0/big; //Save the scaling.
  }
  for (j=1;j<=n;j++) { //This is the loop over columns of Crout’s method.
    for (i=1;i<j;i++) {
      //This is equation (2.3.12) except for i = j.
      sum=a[i][j];
      for (k=1;k<i;k++) sum -= a[i][k]*a[k][j];
        a[i][j]=sum;
      }
      big=0.0; //Initialize for the search for largest pivot element.
      for (i=j;i<=n;i++) {
        //This is i = j of equation (2.3.12)
        //and i = j + 1 ... N of equation (2.3.13).
        sum=a[i][j];
        for (k=1;k<j;k++)
					sum -= a[i][k]*a[k][j];
				a[i][j]=sum;
				if ( (dum=vv[i]*fabs(sum)) >= big) {
					//Is the figure of merit for the pivot better than the best so far?
					big=dum;
					imax=i;
				}
			}
			if (j != imax) { //Do we need to interchange rows?
				for (k=1;k<=n;k++) {
					//Yes, do so...
					dum=a[imax][k];
					a[imax][k]=a[j][k];
					a[j][k]=dum;
				}
				*d = -(*d);	//...and change the parity of d.
				vv[imax]=vv[j]; //Also interchange the scale factor.
			}
			indx[j]=imax;
			if (a[j][j] == 0.0) a[j][j]=TINY;
			/*
			If the pivot element is zero the matrix is singular (at least to the
			precision of the algorithm). For some applications on singular matrices,
			it is desirable to substitute TINY for zero.
			*/
			if (j != n) { //Now, finally, divide by the pivot element.
				dum=1.0/(a[j][j]);
				for (i=j+1;i<=n;i++) a[i][j] *= dum;
			}
	} //Go back for the next column in the reduction.
	free_vector(vv,1,n);
}

int main() {
	float b[4][4] = {{0,0,0,0},{0,1,3,6},{0,2,8,16},{0,5,21,45}};
	float **a = malloc(16*sizeof (int));
	*a = b[0];
	*(a+1) = b[1];
	*(a+2) = b[2];
	*(a+3) = b[3];

	int indx[4] = {0,0,0,0};
	float d = 1;
	ludcmp(a, 3, indx, &d);

	printf("%d %d %d %d\n", *indx, *(indx + 1), *(indx + 2), *(indx+3));

	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			printf("%f  ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
