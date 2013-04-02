#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//変数宣言（必要なだけ追加する）
	
	int m, n;
	FILE *fp, *fp2;
	
	//(1)
	fp = fopen("myprofile.txt", "w");
	fprintf(fp, "My name is Ishibashi Shota.\n");
	fprintf(fp, "I was born in %d\n", 1991);
	fprintf(fp, "So now I'm %d years old.\n", 20);
	fclose(fp);

	//(2)
	fp2 = fopen("19x9.txt", "w");
	for (m = 0; m < 19; m++)
	{
		for (n = 0; n < 9; n++)
			fprintf(fp2, "%2d*%d=%3d ", m + 1, n + 1, (m + 1) * (n + 1));

		fprintf(fp2, "\n");
	}
	fclose(fp2);

	printf("テキストファイルが正しく作成されたか確認してください．\n");
	exit(0);
}