/* 数理プログラミング fr_enshu6.c */
/* 演習6 */
/* 2012.12.05, 10RU004, 石橋祥太 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)
#define EPSILON 2.0
#define TMAX 100
#define PNUM 500

//(2)
short img[PNUM][PNUM];

int main(void)
{
	//(3)
	short c, cnt, r, t, flag;
	double u[PNUM], v[PNUM], x[TMAX], y[TMAX], z[TMAX],
		UMIN[9] = {-1.5000, -1.5000, -1.5000, -1.5000, -1.5000, -1.5000, -1.5000, -1.4900, -1.4834},
		UMAX[9] = {-0.0000, -0.4000, -0.9000, -1.2000, -1.3000, -1.4000, -1.4600, -1.4700, -1.4734},
		VMIN[9] = {-0.7500, -0.5000, -0.3000, -0.1500, -0.1000, -0.0500, -0.0200, -0.0100, -0.0050},
		VMAX[9] = { 0.7500,  0.5000,  0.3000,  0.1500,  0.1000,  0.0500,  0.0200,  0.0100,  0.0050};
	char name[255];

	FILE *fp;
	
	for (cnt = 0; cnt < 9; cnt++)
	{
		//(4a～e)
		for (c = 0; c < PNUM; c++) u[c] = UMIN[cnt] + c * (UMAX[cnt] - UMIN[cnt]) / (PNUM - 1);
		for (r = 0; r < PNUM; r++) v[r] = VMIN[cnt] + r * (VMAX[cnt] - VMIN[cnt]) / (PNUM - 1);

		//(5)
		for (r = 0; r < PNUM; r++)
		{
			for (c = 0; c < PNUM; c++)
			{
				//(6)
				x[0] = y[0] = z[0] = 0.0;
				flag = 0;

				//(7)
				for (t = 1 ; t < TMAX; t++)
				{
					x[t] = x[t - 1] * x[t - 1] - y[t - 1] * y[t - 1] + u[c];
					y[t] = 2 * x[t - 1] * y[t - 1] + v[r];
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
		sprintf(name, "mandelbrot_zoom%d.pgm", cnt + 1);
		fp = fopen(name, "wb");
		fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
		fprintf(fp, "%d %d\n", PNUM, PNUM);
		fprintf(fp, "%d\n", TMAX);

		for (r = 0; r < PNUM; r++)
			for (c = 0; c < PNUM; c++)
				fprintf(fp, "%d ", img[r][c]);

		fclose(fp);
	}

	exit(0);
}