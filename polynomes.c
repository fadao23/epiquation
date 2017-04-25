# include <stdio.h>
# include <stdlib.c>

int sec_deg(float a, float b, float c, char **sol)
{
	float delt = b * b - 4.0 * a * c;

	if (delt > 0)
	{
		float x1 = (-b + sqrt(delt)) / 2 * a;
		float x2 = (-b - sqrt(delt)) / 2 * a;
		
		float X1 = x1;
		float X2 = x2;
		int l1 = 1;
		
		while (fabs(X1) > 10)
		{
			l1++;
			X1 /= 10;
		}
		int l2 = 1;
		
		while (fabs(X2) > 10)
		{
			l1++;
			X2 /= 10;
		}

		sol[0] = calloc(l1 + 4, 1);
		sol[1] = calloc(l2 + 4, 1);

		gcvt(x1, 2, sol[0]);
		gcvt(x2, 2, sol[1]);

		return 2;
	}

	if (delt == 0)
	{
		float x = -b / 2 * a;
		float X = x;
		int l = 0;
		while (fabs(X) > 10)
    { 
      l++; 
      X /= 10;
    }

		gcvt(x, 2, sol[0]);
		return 1;
	}

	if (delt < 0)
  {
		sprintf(sol[0], "(-%f + i%f)/%f", b, sqrt(delt), 2 * a);
    sprintf(sol[1], "(-%f - i%f)/%f", b, sqrt(delt), 2 * a);
	}
	return -2;
}
