/* 数理プログラミング fr_enshu4.c */
/* 演習4 */
/* 2012.11.28, 10RU004, 石橋祥太 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)
#define EPSILON 2.0
#define TMAX 30
#define PNUM 50
#define UMIN -2.00
#define UMAX  2.00
#define VMIN -2.00
#define VMAX  2.00

//(2)
char img[PNUM][PNUM];

int main(void)
{
	//(3)
	short c, r, t, flag;
	double ustep = (UMAX - UMIN) / (PNUM - 1), vstep = (VMAX - VMIN) / (PNUM - 1);
	double u[PNUM], v[PNUM], x[TMAX], y[TMAX], z[TMAX];
	FILE *fp;
	
	//(4a～e)
	for (c = 0; c < PNUM; c++) u[c] = UMIN + c * (UMAX - UMIN) / (PNUM - 1);
	for (r = 0; r < PNUM; r++) v[r] = VMIN + r * (VMAX - VMIN) / (PNUM - 1);

	//(5)
	for (r = 0; r < PNUM; r++)
	{
		for (c = 0; c < PNUM; c++)
		{
			//(6)
			x[0] = y[0] = z[0] = 0.0;
			flag = 1;

			//(7)
			for (t = 1 ; t < TMAX; t++)
			{
				x[t] = x[t - 1] * x[t - 1] - y[t - 1] * y[t - 1] + u[c];
				y[t] = 2 * x[t - 1] * y[t - 1] + v[r];
				z[t] = sqrt(x[t] * x[t] + y[t] * y[t]);
				if (z[t] > EPSILON) flag = 0;
				if (flag == 0) break;
			}
			//(8)
			img[r][c] = flag;
		}
	}

	//(9)
	fp = fopen("mandelbrot_binary.pgm", "wb");
	fprintf(fp, "P5\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", PNUM, PNUM);
	fprintf(fp, "%d\n", 1);

	for (r = 0; r < PNUM; r++)
		for (c = 0; c < PNUM; c++)
			fprintf(fp, "%c", img[r][c]);

	fclose(fp);

	exit(0);
}