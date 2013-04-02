#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//•Ï”éŒ¾
	char x, y;
	int n;

	for(y = 1; y <= 9; y++)
	{
		for(x = 1; x <= 9; x++)
			printf("% 3d", x*y);
		printf("\n");
	}

	exit(0);
}