/* 数理プログラミング problem3_3.c */
/* 追加課題 */
/* 2012.10.03, 10RU004, 石橋祥太 */

#include <stdio.h>

void main(void)
{
	int seiseki, shusseki;

	printf("整数を入力する: seiseki\n> ");
	scanf("%d", &seiseki);

	if (seiseki < 0 || 100 < seiseki) printf("0以上100以下の整数を入力して下さい\n");
	else 
	{
		printf("整数を入力する: shusseki\n> ");
		scanf("%d", &shusseki);

		if (shusseki < 1 || 15 < shusseki) printf("1以上15以下の整数を入力して下さい\n");

		seiseki += shusseki == 15;

		if(seiseki >= 90) printf("S：すばらしい\n");
		else if(seiseki >= 80) printf("A：よくできました\n");
		else if(seiseki >= 70) printf("B：ぼちぼちです\n");
		else if(seiseki >= 60) printf("C：ぎりぎりでした\n");
		else printf("D：来年また会いましょう\n");
	}
	exit(0);
}