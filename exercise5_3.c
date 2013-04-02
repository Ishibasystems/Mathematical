#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int m, n, z[19][9];

	for (m = 0; m < 19; m++)
		for (n = 0; n < 9; printf(n == 8 ? "%2d * %d = %3d\n" : "%2d * %d = %3d ", m + 1, n + 1, z[m][n++] = (m + 1) * (n + 1)));

	exit(0);
}