/* 数理プログラミング problem6_1.c */
/* 提出課題 */
/* 2012.11.07, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	char x, y;
	FILE *fp;

	/* (1) */
	fp = fopen("problem6_1_1.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 100, 50);
	fprintf(fp, "%d\n", 200);

	for (y = 0; y < 50; y++)
		for (x = 0; x < 100; x++)
			fprintf(fp, x == 99 ? "%d\n" : "%d ", 2 * x);
	
	fclose(fp);

	/* (2) */
	fp = fopen("problem6_1_2.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 100, 50);
	fprintf(fp, "%d\n",255);

	for (y = 0; y < 50; y++)
		for (x = 0; x < 100; x++)
			fprintf(fp, x == 99 ? "%d\n" : "%d ", x % 2 && y % 2 ? 200 : 50);
	
	fclose(fp);

	/* (3) */
	fp = fopen("problem6_1_3.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 100, 100);
	fprintf(fp, "%d\n", 255);

	for (y = 0; y < 100; y++)
		for (x = 0; x < 100; x++)
			fprintf(fp, x == 99 ? "%d\n" : "%d ", (short)(3.0 * sqrt((x - 50) * (x - 50) + (y - 50) * (y - 50))));
	
	fclose(fp);

	/* (4) */
	fp = fopen("problem6_1_4.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 100, 100);
	fprintf(fp, "%d\n", 255);

	for (y = 0; y < 100; y++)
		for (x = 0; x < 100; x++)
			fprintf(fp, x == 99 ? "%d\n" : "%d ", (x - 50) * (x - 50) + (y - 50) * (y - 50) > 400 ? 50 : 200);
	
	fclose(fp);

	/* (5) */
	fp = fopen("problem6_1_5.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 100, 100);
	fprintf(fp, "%d\n", 255);

	for (y = 0; y < 100; y++)
		for (x = 0; x < 100; x++)
			fprintf(fp, x == 99 ? "%d\n" : "%d ", abs(x - 50) > 25 || abs(y - 50) > 25 ? (abs(x - 50) + abs(y - 50)) * 2 : 255 - (abs(x - 50) + abs(y - 50)) * 2);
	
	fclose(fp);

	/* (6) */
	fp = fopen("problem6_1_6.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 100, 100);
	fprintf(fp, "%d\n", 255);

	/* sin(6cos(r/8)+5θ) < -0.3 */

	for (y = 0; y < 100; y++)
		for (x = 0; x < 100; x++)
			fprintf(fp, x == 99 ? "%d\n" : "%d ", (short)((sin(6 * cos(sqrt((x - 50) * (x - 50) + (y - 50) * (y - 50)) / 10) + 5 * atan2(y - 50.0, x - 50.0)) + 1) * 128));
	
	fclose(fp);


	exit(0);
}