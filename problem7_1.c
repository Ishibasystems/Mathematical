/* 数理プログラミング problem7_1.c */
/* 提出課題 */
/* 2012.11.14, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Product "P2\n# Created by Ishibashi Shota\n"

void main(void)
{
	unsigned char x, y, width, high, PixMax;
	FILE *fp;

	/* (1) */
	width = 100;
	high = 50;
	PixMax = 200;
	fp = fopen("problem7_1_1.pgm", "w");
	fprintf(fp, Product);
	fprintf(fp, "%d %d\n", width, high);
	fprintf(fp, "%d\n", PixMax);

	for (y = 0; y < high; y++)
		for (x = 0; x < width; x++)
			fprintf(fp, "%d ", 2 * x);

	fclose(fp);

	/* (2) */
	width = 100;
	high = 50;
	PixMax = 255;
	fp = fopen("problem7_1_2.pgm", "w");
	fprintf(fp, Product);
	fprintf(fp, "%d %d\n", width, high);
	fprintf(fp, "%d\n", PixMax);

	for (y = 0; y < high; y++)
		for (x = 0; x < width; x++)
			fprintf(fp, "%d ", x % 2 == 0 && y % 2 == 0 ? 200 : 50);

	fclose(fp);

	/* (3) */
	width = 100;
	high = 100;
	PixMax = 255;
	fp = fopen("problem7_1_3.pgm", "w");
	fprintf(fp, Product);
	fprintf(fp, "%d %d\n", width, high);
	fprintf(fp, "%d\n", PixMax);

	for (y = 0; y < high; y++)
		for (x = 0; x < width; x++)
			fprintf(fp, "%d ", (short)(3 * sqrt((x - 50) * (x - 50) + (y - 50) * (y - 50))));

	fclose(fp);

	/* (4) */
	width = 100;
	high = 100;
	PixMax = 255;
	fp = fopen("problem7_1_4.pgm", "w");
	fprintf(fp, Product);
	fprintf(fp, "%d %d\n", width, high);
	fprintf(fp, "%d\n", PixMax);

	for (y = 0; y < high; y++)
		for (x = 0; x < width; x++)
			fprintf(fp, "%d ", (x - 50) * (x - 50) + (y - 50) * (y - 50) > 400 ? 50 : 200);

	fclose(fp);

	/* (5) */
	width = 100;
	high = 100;
	PixMax = 255;
	fp = fopen("problem7_1_5.pgm", "w");
	fprintf(fp, Product);
	fprintf(fp, "%d %d\n", width, high);
	fprintf(fp, "%d\n", PixMax);

	for (y = 0; y < high; y++)
		for (x = 0; x < width; x++)
			fprintf(fp, "%d ", abs(x - 50) > 25 || abs(y - 50) > 25 ? (abs(x - 50) + abs(y - 50)) * 2 : 255 - (abs(x - 50) + abs(y - 50)) * 2);

	fclose(fp);

	/* (6) */
	width = 100;
	high = 100;
	PixMax = 255;
	fp = fopen("problem7_1_6.pgm", "w");
	fprintf(fp, Product);
	fprintf(fp, "%d %d\n", width, high);
	fprintf(fp, "%d\n", PixMax);

	for (y = 0; y < high; y++)
		for (x = 0; x < width; x++)
			fprintf(fp, "%d ", (short)((sin(6 * cos(sqrt((x - 50) * (x - 50) + (y - 50) * (y - 50)) / 10) + 5 * atan2(y - 50.0, x - 50.0)) + 1) * 128));

	fclose(fp);

	return;
}