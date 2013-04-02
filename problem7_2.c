/* 数理プログラミング problem7_2.c */
/* 追加課題A */
/* 2012.11.14, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char width, high, n, data[63] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 1, 1, 0,
		0, 1, 0, 1, 0, 0, 0, 1, 0,
		0, 1, 1, 1, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0};

	FILE *fp;

	width = 9;
	high = 7;
	fp = fopen("problem7_2_1.ppm", "w");
	fprintf(fp, "P3\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", width, high);
	fprintf(fp, "%d\n", 255);

	for (n = 0; n < width * high; n++)
		fprintf(fp, n % width == width - 1 ? "%03d %03d %03d\n" : "%03d %03d %03d ",
			(data[n] != 0) * (n % width * 50 +  50) * (n % width < 4),
			(data[n] != 0) * (n % width * 50 - 150) * (n % width > 4),
			(data[n] != 0) * (300 - n / width * 50));

	fclose(fp);

	return;
}