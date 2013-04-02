/* 数理プログラミング burningship2_color.c */
/* 問題4 */
/* 2012.12.12, 10RU004, 石橋祥太 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)
#define EPSILON 2.0
#define TMAX 1000
#define TLOOP 100
#define PNUM 500
#define UMIN -0.23172450
#define UMAX -0.23155770
#define VMIN  0.70800490
#define VMAX  0.70815000

int red[PNUM][PNUM], grn[PNUM][PNUM], blu[PNUM][PNUM];

int main(void)
{
	//(3)
	short c, r, t, flag;
	double ustep = (UMAX - UMIN) / (PNUM - 1), vstep = (VMAX - VMIN) / (PNUM - 1);
	double u[PNUM], v[PNUM], x[TMAX], y[TMAX], z[TMAX], val1, val2,
		node[4] = {0.0, 0.3, 0.5, 1.0};
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
			val1 = (double) (flag % TLOOP) / TLOOP;
			if (node[0] <= val1 && val1 < node[1])
			{
				val2 = (val1 - node[0]) / (node[1] - node[0]);
				red[r][c] =   0 * (1 - val2) +   0 * val2;
				grn[r][c] =   0 * (1 - val2) +  17 * val2;
				blu[r][c] =   0 * (1 - val2) + 255 * val2;
			}
			else if (node[1] <= val1 && val1 < node[2])
			{
				val2 = (val1 - node[1]) / (node[2] - node[1]);
				red[r][c] =   0 * (1 - val2) +  17 * val2;
				grn[r][c] =  17 * (1 - val2) + 187 * val2;
				blu[r][c] = 255 * (1 - val2) + 255 * val2;
			}
			else if (node[2] <= val1)
			{
				val2 = (val1 - node[2]) / (node[3] - node[2]);
				red[r][c] =  17 * (1 - val2) + 255 * val2;
				grn[r][c] = 187 * (1 - val2) + 255 * val2;
				blu[r][c] = 255 * (1 - val2) + 255 * val2;
			}
			else printf("OUT: val1 is failed. val1 = %f\n", val1);
		}
	}

	//(9)
	fp = fopen("burningship2_color.ppm", "wb");
	fprintf(fp, "P6\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", PNUM, PNUM);
	fprintf(fp, "%d\n", 255);

	for (r = 0; r < PNUM; r++)
		for (c = 0; c < PNUM; c++)
			fprintf(fp, "%c%c%c", red[r][c], grn[r][c], blu[r][c]);

	fclose(fp);

	exit(0);
}