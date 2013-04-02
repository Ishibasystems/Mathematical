#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int x, y;
	int img[50][100];
	FILE *fp;

	for (y = 0; y < 50; y++)
		for (x = 0; x < 100; x++)
			if (y % 3 == x % 3)
				img[y][x] = 200;
			else
				img[y][x] = 100;

	fp = fopen("diagonal.pgm", "w");
	fprintf(fp, "P2\n");
	fprintf(fp, "# Created by Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 100, 50);
	fprintf(fp, "%d\n", 255);
	for (y = 0; y < 50; y++)
		for (x = 0; x < 100; x++)
			fprintf(fp, "%d ", img[y][x]);

	exit(0);
}