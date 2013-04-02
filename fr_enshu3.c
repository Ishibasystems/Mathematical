#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)
#define EPSILON 2.0
#define TMAX 30
#define PNUM 6

int main(void)
{
	//(2)
	short c, r, t, flag;
	double a, b, u[PNUM], v[PNUM], x[TMAX], y[TMAX], z[TMAX];
	
	for (c = 0; c < PNUM; c++) u[c] = v[c] = 2.0 * c / (PNUM - 1) - 1;

	//(3aÅ`b)
	for (r = 0; r < PNUM; r++)
	{
		b = v[r];
		for (c = 0; c < PNUM; c++)
		{
			a = u[c];
			x[0] = y[0] = z[0] = 0.0;

			flag = 1;
			for (t = 1 ; t < TMAX; t++)
			{
				x[t] = x[t - 1] * x[t - 1] - y[t - 1] * y[t - 1] + a;
				y[t] = 2 * x[t - 1] * y[t - 1] + b;
				z[t] = sqrt(x[t] * x[t] + y[t] * y[t]);
				if (z[t] > EPSILON) flag = 0;
				if (flag == 0) break;
				//(4)
				printf("CNT %02d: X = %+f, Y = %+f, Z = %+f\n", t, x[t], y[t], z[t]);
			}
			printf("ì_(a,b)=(%f,%f)Ç≈ÇÕêîóÒz_tÇÕ%sÇµÇ‹ÇµÇΩ\n", a, b, flag ? "é˚ë©" : "î≠éU");
		}
	}
	exit(0);
}