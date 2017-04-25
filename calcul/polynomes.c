# include "polynomes.h"

int sec_deg(float a, float b, float c, char **sol)
{
	float delt = b * b - 4.0 * a * c;
  *sol = calloc(20, sizeof (char));
  sprintf(*sol,"%f",delt);
	if (delt > 0)
	{
		float x1 = (-b + sqrt(delt)) / (2 * a);
		float x2 = (-b - sqrt(delt)) / (2 * a);


		sol[1] = calloc(20, 1);
		sol[2] = calloc(20, 1);

    sprintf(*(sol+1),"%.5f",x1);
    sprintf(*(sol+2),"%.5f",x2);

		return 2;
	}

	if (delt == 0)
	{
		float x = -b / (2 * a);

		sol[1] = calloc(20, 1);
    sprintf(*(sol+1),"%.5f",x);
		return 1;
	}

  {
		sol[1] = calloc(100, 1);
		sol[2] = calloc(100, 1);
    float r = -b/(2*a);
    float i1 =  sqrt(-1*delt)/( 2 * a);
    float i2 =  -sqrt(-1*delt)/( 2 * a);
    if (r == 0.0000) {
      if (i1 != 0.0000)
		    sprintf(sol[1], "%.2fi", i1);
		  else
        sprintf(sol[1], "0");
      if (i2 != 0.0000)
		    sprintf(sol[2], "%.2fi", i2);
		  else
        sprintf(sol[2], "0");
    }
    else {
      if(i1 != 0.0000)
		    sprintf(sol[1], "%.2f %+.2fi", r, i1);
      else
		    sprintf(sol[1], "%.2f", r);
      if(i2 != 0.0000)
		    sprintf(sol[2], "%.2f %+.2fi", r, i2);
      else
		    sprintf(sol[2], "%.2f", r);
    }
	}
	return -2;
}
