/* 数理プログラミング problem3_2.c */
/* 提出課題B */
/* 2012.10.03, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
	int seiseki;

	printf("整数を入力する\n> ");
	scanf("%d", &seiseki);

	if (seiseki < 0 || 100 < seiseki) printf("0以上100以下の整数を入力して下さい\n");
	else if(seiseki >= 90) printf("S：すばらしい\n");
	else if(seiseki >= 80) printf("A：よくできました\n");
	else if(seiseki >= 70) printf("B：ぼちぼちです\n");
	else if(seiseki >= 60) printf("C：ぎりぎりでした\n");
	else printf("D：来年また会いましょう\n");
	exit(0);
}