#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define width	100
#define high	50
#define PixMax	255
#define H	200
#define L	100

int main(void)
{
	int x, y;
	int img[50][100];
	FILE *fp;

	for (y = 0; y < high; y++)
		for (x = 0; x < width; x++)
			img[y][x] = (y % 3 == x % 3) ? H : L;

	fp = fopen("diagonal.pgm", "w");
	fprintf(fp, "P2\n# Created by Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", width, high);
	fprintf(fp, "%d\n", PixMax);
	for (y = 0; y < high; y++)
		for (x = 0; x < width; x++)
			fprintf(fp, "%d ", img[y][x]);

	exit(0);
}