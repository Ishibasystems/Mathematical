/* int4.c */
/* 2012.09.07, 10RU004, 石橋祥太 */

#include <stdio.h>
#include <stdlib.h>

typedef	struct stack_data
{
	struct stack_data *prev;
	char num;
} stack;

char enzanshi(char);
char usen(char);
void push(stack **, char);
char pop(stack **);

void main(void)
{
	short num1, num2;
	char cnt, cout, count, s, shiki1[8] = "\0", shiki2[8] = "\0";
	stack *buf;

	do {	/* 数値入力 */
		printf("4桁の数値を入力してください。\n> ");
		scanf("%d", &num1);
	} while(num1 < 0 || 9999 < num1);

	/* 4桁に分解 */
	shiki1[0] = '0' + num1 / 1000 % 10;
	shiki1[2] = '0' + num1 /  100 % 10;
	shiki1[4] = '0' + num1 /   10 % 10;
	shiki1[6] = '0' + num1 /    1 % 10;

	for (count = 0; count < 4; count++)
	{
		if (count == 3 && shiki1[6] == '0') continue;
		shiki1[5] = enzanshi(count);
		for (cout = 0; cout < 4; cout++)
		{
			if (cout == 3 && shiki1[4] == '0') continue;
			shiki1[3] = enzanshi(cout);
			for (cnt = 0; cnt < 4; cnt++)
			{
				char c1, c2;
				if (cnt == 3 && shiki1[2] == '0') continue;
				shiki1[1] = enzanshi(cnt);
				/* DEBUG *//* printf("%s\n", shiki1); */

				/* 中置記法→逆ポーランド記法 変換 */
				c1 = c2 = 0;
				buf = NULL;
				while (shiki1[c1] != '\0')
				{
					s = shiki1[c1++];
					if ('0' <= s && s <= '9') shiki2[c2++] = s;
					else
					{
						if (s == ')') while ((s = pop(&buf)) != '(') shiki2[c2++] = s;
						else
						{
							if (s != '(')
								while(buf != NULL && usen(buf->num) > usen(s))
									shiki2[c2++] = pop(&buf);

							push(&buf, s);
						}
					}
				}
				while (buf != NULL) shiki2[c2++] = pop(&buf);
				/* DEBUG *//* printf("%s\n", shiki2); */

				num2 = 10;
			}
		}
	}

	return;
}

char enzanshi(char n)
{
	if (n == 0) return'+';
	if (n == 1) return'-';
	if (n == 2) return'*';
	if (n == 3) return'/';

	return 0;
}

char usen(char n)
{
	if (n == '+') return 1;
	if (n == '-') return 1;
	if (n == '*') return 2;
	if (n == '/') return 3;

	return 0;
}

void push(stack **a, char n)
{
	stack *b;

	b = malloc(sizeof(stack));

	b->prev = *a;
	b->num  = n;

	*a = b;

	return;
}

char pop(stack **a)
{
	stack *b;
	char c;

	if (a == NULL || *a == NULL) exit(0);

	b = (*a)->prev;
	c = (*a)->num;

	free(*a);

	*a = b;

	return c;
}