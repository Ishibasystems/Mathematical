#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	//(1)
	int a = 3, b = 5, c;

	//(2)
	a -= b;
	printf("(2) %d \n", a);

	//(3)
	b *= 2;
	printf("(3) %d \n", b);

	//(4)
	b--;
	printf("(4) %d \n", b);

	//(5)
	printf("(5) %d \n", 3-5*2);
	printf("(5) %d \n", c=3-5*2);
	printf("(5) %d \n", c);

	exit(0);
}

