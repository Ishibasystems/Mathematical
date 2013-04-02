/* 数理プログラミング problem6_2.c */
/* 追加課題 */
/* 2012.11.14, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char n, data[35] = {
		1, 1, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 1,
		1, 1, 1, 0, 0, 0, 1};

	FILE *fp;

	/* (1) */
	fp = fopen("problem6_2_1.ppm", "w");
	fprintf(fp, "P3\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 7, 5);
	fprintf(fp, "%d\n", 256);

	for (n = 0; n < 35; n++)
		fprintf(fp, n % 7 == 6 ? "%03d %03d %03d\n" : "%03d %03d %03d ",
			(data[n] != 0) * (n % 7 * 50 + 100) * (n % 7 < 3),
			(data[n] != 0) * (n % 7 * 50 - 100) * (n % 7 > 3),
			(data[n] != 0) * (250 - n / 7 * 50));

	fclose(fp);

	return;
}