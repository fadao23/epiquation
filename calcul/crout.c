# include "crout.h"

#define TINY 1.0e-20  //A small number.

float *vector(long nh)
/* allocate a float vector with subscript range v[nl..nh] */
{
	float *v = malloc(nh * sizeof(float));
	return v;
}

void ludcmp(float *a, int n, int *indx)
{
	/*
		a -> matrice carre remplacer en sortie par sa LU decomposition permutee
		n -> taille de la matrice
		indx -> vecteur qui sauvegarde les permutations
		d -> vaut 1 si le nombre de permutation et pair, -1 sinon
	*/
  int i,imax=0,j,k;
  float big,dum,sum,temp;
  float *vv;         //vv contient le coef multiplicateur de chaque ligne.
  vv=vector(n);
  for (i=0;i<n;i++) { //On parcours les lignes
    big=0.0;
    for (j=0;j<n;j++)
      if ((temp=fabs(*(a +i * n + j))) > big) big=temp;
    if (big == 0.0) set_erreur(11);
    //Le plus grand elem est > 0
    vv[i]=1.0/big; //On sauve le coef multiplicateur
  }
  for (j=0;j<n;j++) { //On parcours les colonnes
    for (i=0;i<j;i++) {
      //This is equation (2.3.12) except for i = j.
      sum=*(a+i*n+j);
      for (k=0;k<i;k++) sum -= *(a+i*n+k)* *(a+k*n+j);
        *(a+i*n+j)=sum;
      }
      big=0.0; //On recheche l'élément le plus grand
      for (i=j;i<n;i++) {
        //This is i = j of equation (2.3.12)
        //and i = j + 1 ... N of equation (2.3.13).
        sum=*(a+i*n+j);
        for (k=0;k<j;k++)
					sum -= *(a+i*n+k)* *(a+k*n+j);
				*(a+i*n+j)=sum;
				if ( (dum=vv[i]*fabs(sum)) >= big) {
					//Il existe un meilleur pivot
					big=dum;
					imax=i;
				}
			}
			if (j != imax) { //Est-ce qu'il y a besoin de changer les lignes
				for (k=0;k<n;k++) {
					dum=*(a+imax*n+k);
					*(a+imax*n+k)=*(a+j*n+k);
					*(a+j*n+k)=dum;
				}
				vv[imax]=vv[j]; //on change le vecteur de coef
			}
			indx[j]=imax;
			if (*(a+j*n+j) == 0.0) *(a+j*n+j)=TINY;
			if (j != n) { //On divise par le pivot
				dum=1.0/(*(a+j*n+j));
				for (i=j+1;i<n;i++) *(a+i*n+j) *= dum;
			}
	}
	free(vv);
}

void lubksb(float *a, int n, int *indx, float b[])
/*
  Solves the set of n linear equations A·X = B. Here a[1..n][1..n] is input, not as the matrix
  A but rather as its LU decomposition, determined by the routine ludcmp . indx[1..n] is input
  as the permutation vector returned by ludcmp . b[1..n] is input as the right-hand side vector
  B, and returns with the solution vector X. a , n , and indx are not modified by this routine
  and can be left in place for successive calls with different right-hand sides b . This routine takes
  into account the possibility that b will begin with many zero elements, so it is efficient for use
  in matrix inversion.
*/
{
  int i,ii=-1,ip,j;
  float sum;
  for (i=0;i<n;i++) {
    //When ii is set to a positive value, it will become the
    ip=indx[i];
    //index of the first nonvanishing element of b. We now
    sum=b[ip];
    //do the forward substitution, equation (2.3.6). The
    b[ip]=b[i];
    //only new wrinkle is to unscramble the permutation
    if (ii>-1) //as we go.
      for (j=ii;j<i;j++) sum -= *(a+i*n+j)*b[j];
    else if (sum) ii=i;
    //A nonzero element was encountered, so from now on we
    b[i]=sum;
    //will have to do the sums in the loop above.
  }
  for (i=n-1;i>=0;i--) {
    //Now we do the backsubstitution, equation (2.3.7).
    sum=b[i];
    for (j=i+1;j<n;j++) sum -= *(a+i*n+j)*b[j];
    b[i]=sum/(*(a+i*n+i));
    //Store a component of the solution vector X.
  }
  //All done!
}
