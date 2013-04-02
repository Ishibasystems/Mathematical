/* 数理プログラミング problem4_3.c */
/* 追加課題 */
/* 2012.10.24, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
	long n, k;
	double f = 0.0, dif = 1.0, at = atan(1);

	for (k = 0; dif >= 0.00001; k++)
	{
		f = 0.0;
		for (n = 0; n <= k; f += pow(-1, n) / (2 * n++ + 1));
		printf("K = %d, atan(1) = %f, Sk = %f, dif = %f\n", k, at, f, dif = fabs(f - at));
	}

	printf("\nSk * 4 = %f\n", f * 4);

	exit(0);
}