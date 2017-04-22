# include <stdio.h>
# include <stdlib.c>

int sec_deg(float a, float b, float c, float *sol)
{
	int delt = b*b - 4*a*c;

	if (delt > 0)
	{
		sol[0] = (-b + sqrt(delt)) / 2*a;
		sol[1] = (-b - sqrt(delt)) / 2*a;
		return 2;
	}
	if (delt == 0)
	{
		sol[0] = -b / 2*a;
		return 1;
	}
	return 0;
}
