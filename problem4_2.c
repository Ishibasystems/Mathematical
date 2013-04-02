/* 数理プログラミング problem4_2.c */
/* 提出課題B */
/* 2012.10.24, 10RU004, 石橋祥太 */

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