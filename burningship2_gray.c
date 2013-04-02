/* 数理プログラミング burningship2_gray.c */
/* 問題1 */
/* 2012.12.05, 10RU004, 石橋祥太 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)
#define EPSILON 2.0
#define TMAX 200
#define PNUM 500
#define UMIN -0.22962210
#define UMAX -0.22954630
#define VMIN  0.70133460
#define VMAX  0.70139520

//(2)
short img[PNUM][PNUM];

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
			flag = 0;

			//(7)
			for (t = 1 ; t < TMAX; t++)
			{
				x[t] = x[t - 1] * x[t - 1] - y[t - 1] * y[t - 1] + u[c];
				y[t] = 2 * x[t - 1] * y[t - 1] + v[r];
				if (y[t] < 0) y[t] = -y[t];
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
	fp = fopen("burningship2_gray.pgm", "wb");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", PNUM, PNUM);
	fprintf(fp, "%d\n", TMAX);

	for (r = 0; r < PNUM; r++)
		for (c = 0; c < PNUM; c++)
			fprintf(fp, "%d ", img[r][c]);

	fclose(fp);

	exit(0);
}