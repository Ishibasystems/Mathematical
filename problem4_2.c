/* vO~O problem4_2.c */
/* ñoÛèB */
/* 2012.10.24, 10RU004, Î´Ë¾ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
	long m, n;

	for (m = 1; m < 10; m++)
	{
		for (n = 1; n < 10; printf("%c ", m % n++ ? '0' + m % (n - 1) : ' '));
		printf("\n");
	}

	exit(0);
}