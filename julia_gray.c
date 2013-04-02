/* 数理プログラミング julia_gray.c */
/* 問題5 */
/* 2012.12.12, 10RU004, 石橋祥太 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)
#define EPSILON 2.0
#define TMAX 200
#define PNUM 500
#define UMIN -2.00
#define UMAX  2.00
#define VMIN -2.00
#define VMAX  2.00

//(2)
short img[PNUM][PNUM];

int main(void)
{
	//(3)
	short c, r, t, flag;
	double a = 0.25, b = -0.52, u[PNUM], v[PNUM], x[TMAX], y[TMAX], z[TMAX],
		ustep = (UMAX - UMIN) / (PNUM - 1), vstep = (VMAX - VMIN) / (PNUM - 1);
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
			x[0] = u[c];
			y[0] = v[r];
			z[0] = 0.0;
			flag = 0;

			//(7)
			for (t = 1 ; t < TMAX; t++)
			{
				x[t] = x[t - 1] * x[t - 1] - y[t - 1] * y[t - 1] + a;
				y[t] = 2 * x[t - 1] * y[t - 1] + b;
				z[t] = sqrt(x[t] * x[t] + y[t] * y[t]);
				if (z[t] > EPSILON) flag = t;
				if (flag != 0) break;
			}
			//(8)
			img[r][c] = TMAX;
			if (flag != 0) img[r][c] = flag;
		}
	}

	//(9)
	fp = fopen("julia_gray.pgm", "wb");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", PNUM, PNUM);
	fprintf(fp, "%d\n", TMAX);

	for (r = 0; r < PNUM; r++)
		for (c = 0; c < PNUM; c++)
			fprintf(fp, "%d ", img[r][c]);

	fclose(fp);

	exit(0);
}