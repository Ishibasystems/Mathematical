#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	//(1)
	printf("(1) %f\n", fabs(-4.5));

	//(2)
	printf("(2) %f\n", sqrt(2));

	//(3)
	printf("(3) %f\n", pow(2.0, 4.0));

	//(4)
	printf("(4) %f\n", pow(2.0, 0.5));

	//(5)
	printf("(5) %f\n", sin(3.14 / 6.0));

	//(6)
	printf("(6) %f\n", cos(3.14 / 6.0));

	//(7)
	printf("(7) %f\n", 4.0 * atan(1));

	//(8)
	printf("(8) %f\n", ceil(2.5));

	//(9)
	printf("(9) %f\n", floor(2.5));

	exit(0);
}

