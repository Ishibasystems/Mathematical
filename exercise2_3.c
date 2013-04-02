#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	//(1)
	int i = 3;
	double x = 3.0;

	//(2)
	printf("(2) %d %d %d\n", 3 / 2, i / 2, x / 2);

	//(3)
	printf("(3) %d %d %d\n", 3.0 / 2.0, i / 2.0, x / 2.0);

	//(4)
	printf("(4) %f %f %f\n", 3.0 / 2.0, i / 2.0, x / 2.0);

	exit(0);
}

