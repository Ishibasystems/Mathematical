#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//�ϐ��錾�i�K�v�Ȃ����ǉ�����j
	int m, n, img[4][5] =
	{
		{0,   0,   255, 0,   220},
		{0,   0,   255, 0,     0},
		{255, 255, 100, 255, 255},
		{0,   0,   255, 0,   100},
	};
	FILE *fp;

	//(1)
	fp = fopen("excersize6_2.pgm", "w");
	fprintf(fp, "P2\n# Created by 10RU004 Ishibashi Shota\n");
	fprintf(fp, "%d %d\n", 5, 4);
	fprintf(fp, "%d\n", 255);

	//(2)

	for (m = 0; m < 4; m++)
		for (n = 0; n < 5; n++)
			fprintf(fp, n == 4 ? "% 4d\n" : "% 4d ", img[m][n]);
	
	fclose(fp);

	printf("PGM�摜���������쐬���ꂽ���m�F���ĉ������D\n");
	exit(0);
}