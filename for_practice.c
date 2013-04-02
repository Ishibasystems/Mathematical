#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short x;
	for (x = 2; ; x += 2)
		printf("x = %d\n", x);

	printf("- - - - - -\n");
	printf("x = %d\n", x);
	exit(0);
}