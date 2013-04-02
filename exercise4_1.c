#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//•Ï”éŒ¾
	char x;
	int n;

	//(1)
	for(x = 5; x >= 0; x--)
		printf("%d\n", x);

	printf("\n"); //‹æØ‚è‚Ì‰üs

	//(2)
	for(n = 1; n < 1000; n <<= 1)
		printf("%d\n", n);

	printf("\n"); //‹æØ‚è‚Ì‰üs

	system("pause");

	//(3)
	for(x = 1;; x++)
		printf("%d\n", x);

	exit(0);
}