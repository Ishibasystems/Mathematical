#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char x, y;
	FILE *fp;

	fp = fopen("excersize6_3_1.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 100, 50);
	fprintf(fp, "%d\n", 9);

	for (y = 0; y < 50; y++)
		for (x = 0; x < 100; x++)
			fprintf(fp, x == 99 ? "%d\n" : "%d ", y % 2 ? 7 : 4);
	
	fclose(fp);
	exit(0);
}