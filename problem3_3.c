/* �����v���O���~���O problem3_3.c */
/* �ǉ��ۑ� */
/* 2012.10.03, 10RU004, �΋��ˑ� */

#include <stdio.h>

void main(void)
{
	int seiseki, shusseki;

	printf("��������͂���: seiseki\n> ");
	scanf("%d", &seiseki);

	if (seiseki < 0 || 100 < seiseki) printf("0�ȏ�100�ȉ��̐�������͂��ĉ�����\n");
	else 
	{
		printf("��������͂���: shusseki\n> ");
		scanf("%d", &shusseki);

		if (shusseki < 1 || 15 < shusseki) printf("1�ȏ�15�ȉ��̐�������͂��ĉ�����\n");

		seiseki += shusseki == 15;

		if(seiseki >= 90) printf("S�F���΂炵��\n");
		else if(seiseki >= 80) printf("A�F�悭�ł��܂���\n");
		else if(seiseki >= 70) printf("B�F�ڂ��ڂ��ł�\n");
		else if(seiseki >= 60) printf("C�F���肬��ł���\n");
		else printf("D�F���N�܂���܂��傤\n");
	}
	exit(0);
}