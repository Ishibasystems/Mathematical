/* 数理プログラミング problem2_1.c */
/* 提出課題A */
/* 2012.10.03, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
	double x = fabs(pow(3.5, 3.0) - pow(3.0, 3.5)), M_PI = atan(1) * 4;
	long a = fmod(pow(1, 1) + pow(2, 2) + pow(3, 3) + pow(4, 4), 10);
	short year;
	char month, day;

	//(1)
	printf("(1) %f \n", x);

	//(2)
	printf("(2) %0.0f \n", x);

	//(3)
	printf("(3) %d \n", a);

	//(4)
	printf("(4) %f \n", 1 - 1 / sqrt(2) + 1 / sqrt(3) - 1 / sqrt(4));

	//(5)
	printf("(5) %f \n", 1 + 1 / (1 + 1 / (1 + 1.0 / 1)));

	//(6)
	printf("(6) %f \n", sin(M_PI/3) * cos(M_PI/6) - cos(M_PI/3) * sin(M_PI/6));

	//(7)
	do {	/* 数値入力 */
		printf("順に自分（または適当な人物）の誕生年、月、日を代入せよ。\n> ");
		scanf("%d", &year);
		scanf("%d", &month);
		scanf("%d", &day);
	} while(year > 2012 || month > 12 || month < 1 || day > 31 || day < 1);
	printf("(7) 誕生日が%d年%d月%d日の人は、今年で%d歳になります\n", year, month, day, 2012 - year);

	exit(0);
}