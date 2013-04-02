/* 数理プログラミング problem4_1.c */
/* 提出課題A */
/* 2012.10.24, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
	long n, x, y;
	char i;
	double f;

	//(1)
	x = 0;
	for (i = -5; i <= 50; x += i++);
	printf("(1) %d\n", x);

	//(2)
	x = 0;
	for (i = -5; x < 500; x += i++);
	printf("(2) %d\n", i);

	//(3)
	x = y = 0;
	for (n = 30; n <= 100; x += n++ % 3 ? 0 : n - 1) y += n % 5 ? 0 : n;
	printf("(3) 3の倍数の和: %d, 5の倍数の和: %d\n", x, y);

	//(4)
	x = 0;
	f = 0.0;
	for (n = 1; n + x <= 1000; (n + x) % 7 ? x++ : n++)
		f += (n + x) % 7 ? (double)n : 0;
	printf("(4) %d %f\n", x, f / x);

	//(5)
	printf("(5)");
	for (n = 0; n <= 4; printf(" %f", pow(-1, n) / (2 * n++ + 1)));
	printf("\n");

	//(6)
	f = 0.0;
	for (n = 0; n <= 1000; f += pow(-1, n) / (2 * n++ + 1));
	printf("(6) %f\n", f);

	//(7)
	f = 0.0;
	for (n = 0; n <= 1000; f += pow(-1, n) / (2 * n++ + 1));
	printf("(6) Pi %f\n", f * 4);

	exit(0);
}