/* �����v���O���~���O problem7_3.c */
/* �ǉ��ۑ�B */
/* 2012.11.14, 10RU004, �΋��ˑ� */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1)#define�錾
#define SIZE 200
#define TMAX 10000

double Func(double mu, double x)
{
	return mu * x + 2 * (1 - mu) * x * x / (x * x + 1);
}

int main(void)
{
	//(2)�ϐ��錾
	short max = logf(0), min = -logf(0);
	long x, y;
	char img[SIZE][SIZE] = {0};	//(3)img���[���N���A

	double a = 0.008, mu = -0.9, u[TMAX], v[TMAX];
	FILE *fp;

		
	//(4)����u,v�̌v�Z
	//(5)�v�Z����u,v�̍ő�l�E�ŏ��l�̎擾
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

	//(6)img�̐���
	for (x = 1; x < TMAX; x++)
		img[(short)(SIZE * (v[x] - min) / (max - min))][(short)(SIZE * (u[x] - min) / (max - min))] = 1;
	
	//(7)img��PGM�摜�ŕۑ�
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