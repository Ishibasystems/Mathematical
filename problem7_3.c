/* 数理プログラミング problem7_3.c */
/* 追加課題B */
/* 2012.11.14, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)#define宣言
#define SIZE 200
#define TMAX 10000

double Func(double mu, double x)
{
	return mu * x + 2 * (1 - mu) * x * x / (x * x + 1);
}

int main(void)
{
	//(2)変数宣言
	short max = logf(0), min = -logf(0);
	long x, y;
	char img[SIZE][SIZE] = {0};	//(3)imgをゼロクリア

	double a = 0.008, mu = -0.9, u[TMAX], v[TMAX];
	FILE *fp;

		
	//(4)数列u,vの計算
	//(5)計算したu,vの最大値・最小値の取得
	u[0] = v[0] = 0.1;
	for (x = 1; x < TMAX; x++)
	{
		u[x] = v[x - 1] + a * (1 - 0.05 * v[x - 1] * v[x - 1]) * v[x - 1] + Func(mu, u[x - 1]);
		v[x] = -u[x - 1] + Func(mu, u[x]);
		if (max < u[x]) max = u[x];
		if (max < v[x]) max = v[x];
		if (min > u[x]) min = u[x];
		if (min > v[x]) min = v[x];
	}

	//(6)imgの生成
	for (x = 1; x < TMAX; x++)
		img[(short)(SIZE * (v[x] - min) / (max - min))][(short)(SIZE * (u[x] - min) / (max - min))] = 1;
	
	//(7)imgをPGM画像で保存
	fp = fopen("problem7_3.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", SIZE, SIZE);
	fprintf(fp, "%d\n", 1);

	for (y = 0; y < SIZE; y++)
		for (x = 0; x < SIZE; x++)
			fprintf(fp, "%d ", img[y][x]);

	fclose(fp);

	exit(0);
}