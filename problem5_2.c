/* 数理プログラミング problem5_2.c */
/* 追加課題 */
/* 2012.10.26, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i;
	double x[6], y[10], z[6][10];

	/* (1) */
	for (i = 0; i < 6; x[i++] = 6.0 / 5 * i - 3);
	for (i = 0; i < 10; y[i++] = 8.0 / 9 * i - 4);

	/* (2) */
	for (i = 0; i < 60; z[i % 6][i++ / 6] = x[i % 6] * x[i % 6] + y[i / 6] * y[i / 6]);

	/* (3) */
	for (i = 0; i < 60; printf(i % 6 == 5 ? "%09f\n" : "%09f ", z[i % 6][i++ / 6]));

	return;
}