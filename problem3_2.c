/* �����v���O���~���O problem3_2.c */
/* ��o�ۑ�B */
/* 2012.10.03, 10RU004, �΋��ˑ� */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
	int seiseki;

	printf("��������͂���\n> ");
	scanf("%d", &seiseki);

	if (seiseki < 0 || 100 < seiseki) printf("0�ȏ�100�ȉ��̐�������͂��ĉ�����\n");
	else if(seiseki >= 90) printf("S�F���΂炵��\n");
	else if(seiseki >= 80) printf("A�F�悭�ł��܂���\n");
	else if(seiseki >= 70) printf("B�F�ڂ��ڂ��ł�\n");
	else if(seiseki >= 60) printf("C�F���肬��ł���\n");
	else printf("D�F���N�܂���܂��傤\n");
	exit(0);
}