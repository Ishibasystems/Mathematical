#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	//•Ï”éŒ¾
	long n, x, y;
	double f;

	//(1)
	printf("(1)\n");
	x = 0;
	for(n = 1; n < 1000; n <<= 1)
		printf("%d: %d\n", ++x, n);

	//(2)
	x = 0;
	for (n = 1; n <= 100; x += n++);
	printf("(2) %d\n", x);

	//(3)
	x = 0;
	for (n = -5; n <= 10; n++) x += n * n - 2 * n + 3;
	printf("(3) %d\n", x);

	//(4)
	f = 0.0;
	for (n = 0; n <= 20; n += 2) f += sqrt(pow(2.0, n));
	printf("(4) %f\n", f);

	//(5)
	x = 0;
	f = 0.0;
	for (n = 50; n <= 100; n = 50 + ++x * 2) f += (double)n;
	printf("(5) %d %f\n", x, f / x);

	//(6)
	x = 0;
	for (n = 1; n <= 50; x += pow(-1, n - 1) * n++);
	printf("(6) %d\n", x);

	//(7)
	x = y = 0;
	for (n = 1; n <= 100; n % 2 ? (y += n++) : (x += n++));
	printf("(6) ‹ô”‚Ì˜a: %d, Šï”‚Ì˜a: %d\n", x, y);

	//(8)
	x = 0;
	for (n = 0; x <= 500; x += ++n);
	printf("(8) %d %d\n", n, x);

	exit(0);
}