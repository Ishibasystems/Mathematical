#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)
#define TMAX 30

int main(void)
{
	//(2)
	short t;
	double a, b, x[TMAX], y[TMAX], z[TMAX];
	

	//(3aÅ`b)
	a = 0.3;
	b = -0.5;
	x[0] = y[0] = z[0] = 0.0;

	for (t = 1 ; t < TMAX; t++)
	{
		x[t] = x[t - 1] * x[t - 1] - y[t - 1] * y[t - 1] + a;
		y[t] = 2 * x[t - 1] * y[t - 1] + b;
		z[t] = sqrt(x[t] * x[t] + y[t] * y[t]);
		//(4)
		printf("CNT %02d: X = %+f, Y = %+f, Z = %+f\n", t, x[t], y[t], z[t]);
	}
	exit(0);
}