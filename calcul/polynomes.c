# include "polynomes.h"

int sec_deg(float a, float b, float c, float *sol)
{
	float delt = b*b - 4*a*c;
  *sol = delt;
	if (delt > 0)
	{
		*(sol + 1) = (-b - sqrt(delt)) / 2*a;
		*(sol + 2) = (-b + sqrt(delt)) / 2*a;
		return 2;
	}
	if (delt == 0)
	{
		*(sol + 1) = -b / 2*a;
		return 1;
	}
	return 0;
}
