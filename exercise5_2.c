#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, N = 100;
	double xmin = -5, xmax = 5, xstep, x[100], y[100];

	xstep = (xmax - xmin) / (N - 1);

	x[0] = xmin;

	for (i = 1; i < N; i++)
		x[i] = x[i - 1] + xstep;

	for (i = 0; i < N; i++)
		printf("x%d = %f\n", i, x[i]);

	for (i = 0; i < N; i++)
		printf("(x%d, y%d) = (%f, %f)\n", i, i, x[i], y[i] = x[i] * x[i]);

	exit(0);
}