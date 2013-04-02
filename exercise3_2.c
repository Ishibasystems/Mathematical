#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	//(1)
	int a = 3, b = 5, c;

	//(2)
	printf("(2) %d \n", 2>3);

	//(3)
	printf("(3) %d \n", 2<3);

	//(4)
	c = 2 < 3;
	printf("(4) %d \n", c);

	//(5)
	printf("(5) %d \n", !c);

	//(6)
	printf("(6) %d \n", !5);

	//(7)
	printf("(7) %d \n", !0);

	//(8)
	printf("(8) %d \n", a == b && a != b);

	//(9)
	printf("(9) %d \n", a == b || a != b);

	exit(0);
}
