#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIZE_H 40	//画像の高さ（Height）
#define SIZE_W 40	//画像の幅（Width）


//(1)
#define INUM 50
#define FNUM 3

//////////////////////////////////////////////////////////////////////////////
//この部分はいじらない（関数プロトタイプ宣言）
void input_pgm(char *imgname, int img[SIZE_H][SIZE_W]);
int getint(FILE *fp);
//////////////////////////////////////////////////////////////////////////////


int main(void)
{
	// 変数宣言（他に必要となる変数は各自で宣言すること）
	int img[SIZE_H][SIZE_W];
	int i, h, r, c, num, vote, w = 0;
	int rb1[FNUM] = {30, 3, 35}, re1[FNUM] = {35, 13, 39}, cb1[FNUM] = {10, 5, 20}, ce1[FNUM] = {28, 35, 39};
	int rb2[FNUM] = {20, 5, 35}, re2[FNUM] = {25, 14, 39}, cb2[FNUM] = {27, 16, 0}, ce2[FNUM] = {37, 24, 19};
	double theta[FNUM] = {10, 5, 0};
	double mean1, mean2, f;
	char imgname[256];

	//(2)

	//(3)
	for(i = 0; i < INUM; i++)
	{
		//(4)
		sprintf(imgname, "data/image%03d.pgm", i);
		input_pgm(imgname, img);
		for (vote = h = 0; h < FNUM; h++)
		{
			//(5a)
			mean1 = 0.0;
			for(r = rb1[h]; r <= re1[h]; r++)
				for(c = cb1[h]; c <= ce1[h]; c++)
					mean1 += (double)img[r][c] / (re1[h] - rb1[h] + 1) / (ce1[h] - cb1[h] + 1);

			//(5b)
			mean2 = 0.0;
			for(r = rb2[h]; r <= re2[h]; r++)
				for(c = cb2[h]; c <= ce2[h]; c++)
					mean2 += (double)img[r][c] / (re2[h] - rb2[h] + 1) / (ce2[h] - cb2[h] + 1);

			//(6)
			f = mean2 - mean1;

			//(7)
			if (f >= theta[h]) printf("%f≧%f: 顔\n", f, theta[h], vote++);
			else printf("%f＜%f: not顔\n", f, theta[h]);
		}
		printf("%d回中%d回: 顔と判定 ⇒ 多数決より%sは顔画像%s\n", FNUM, vote, imgname, vote >= 0.5 * FNUM ? "" : "ではない");
		w += (vote >= 0.5 * FNUM) ^ (i > 24);
	}
	printf("RESULT: %f%%\n", 100.0 * w / 50);

	exit(0);
}


/**************************************************************************/
/* ここから下はいじらないこと（画像読み込み用の関数の定義）               */
/**************************************************************************/


void input_pgm(char *imgname, int img[SIZE_H][SIZE_W])
{
	int i, j, g1, c, w, h, maxv;

	FILE *fp;
	fopen_s(&fp, imgname, "r");
	if(fp == NULL)
	{
		printf("実行エラー：\n");
		printf("　　　ファイル「%s」を開けませんでした．\n", imgname);
		printf("　　　ファイルの名前や場所が正しいか確認してください．\n");
		printf("　　　画像ファイルと実行ファイルは同じフォルダにある必要があります．\n");
		exit(1);
	}

	g1 = getc(fp);
	c = getc(fp);
	w = getint(fp);
	h = getint(fp);
	maxv = getint(fp);

	if(w != SIZE_W || h != SIZE_H)
	{
		printf("実行エラー：\n");
		printf("　　　画像サイズが不正です．\n", SIZE_W, SIZE_H);
		printf("　　　%dx%dピクセルの画像を入力して下さい．\n", SIZE_W, SIZE_H);
		printf("　　　または，ソースファイルのマクロ置換を高さ%d，幅%dピクセルに変更して下さい．\n", h, w);
		exit(1);
	}

	if(c == '2')
	{
		for(i=0; i<h; i++)
		{
			for(j=0; j<w; j++)
			{
				fscanf_s(fp, "%d", &img[i][j]);
			}
		}
	}
	else
	{
		fprintf(stderr, "実行エラー：\n");
		fprintf(stderr, "　　　 未対応の画像形式です．\n");
		fprintf(stderr, "　　　 「%s」が正しいPGM画像ファイルであるか確認して下さい．\n", imgname);
		exit(1);
	}

	fclose(fp);
}


int getint(FILE *fp)
{
	int c;
	int i;
	int firstchar;

	c = getc(fp);
	while(1)
	{
		if (c=='#')
		{
			char cmt[256];
			char *sp;
			sp = cmt;
			firstchar = 1;
			while(1)
			{
				c = getc(fp);
				if(firstchar && c == ' ')
				{
					firstchar = 0; 
				}
				else
				{
					if(c == '\n' || c == EOF)
					{
						break;
					}
					if((sp-cmt) < 250)
					{
						*sp++ =c;
					}
				}
			}
			*sp++ = '\n';
			*sp   = '\0';
		}
		if(c == EOF)
		{
			return 0;
		}
		if(c >= '0' && c <= '9')
		{
			break;
		}
		if(c != ' ' && c != '\t' && c != '\r' && c != '\n' && c != ',')
		{
		}
		c = getc(fp);
	}
	i = 0;

	while(1)
	{
		i = (i*10) + (c-'0');
		c = getc(fp);
		if(c == EOF)
		{
			return i;
		}
		if(c < '0' || c > '9')
		{
			break;
		}
	}

	return (i);
}


