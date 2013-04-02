#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmpsave.h"


//(1)
#define SIZE_H 40
#define SIZE_W 40

//////////////////////////////////////////////////////////////////////////////
//この部分はいじらない（関数プロトタイプ宣言）
void input_pgm(char *imgname, int img[SIZE_H][SIZE_W]);
int getint(FILE *fp);
//////////////////////////////////////////////////////////////////////////////


int main(void)
{
	// 変数宣言
	int img[SIZE_H][SIZE_W];
	unsigned char image[SIZE_H * SIZE_W * 3];
	int r, c, rb, re, cb, ce;
	char imgname[256] = "[ファイル名未指定です]";
	FILE *fp;

	//(2)
	rb = 30;
	re = 35;
	cb = 10;
	ce = 28;

	//(3)
	sprintf(imgname, "data/image%03d.pgm", 0);
	input_pgm(imgname, img);
	//(4)

	//(5)
	for(r = rb; r <= re; r++)
	{
		for(c = cb; c <= ce; c++)
		{
			img[r][c] = 0;
		}
	}
		
	//(6)
	for(r = 0; r < SIZE_H; r++)
		for(c = 0; c < SIZE_W; c++)
			image[(c + r * SIZE_W) * 3 + 0] = 
			image[(c + r * SIZE_W) * 3 + 1] = 
			image[(c + r * SIZE_W) * 3 + 2] = img[r][c];

	bmpsave("test.bmp", image, SIZE_W, SIZE_H, 3, 1);
	


	printf("画像 %s の一部を黒くし，test.pgm として出力しました．\n", imgname);
	printf("PGM画像を確認して下さい．\n");

	exit(0);
}


/**************************************************************************/
/* ここから下はいじらないこと（画像読み込み関数の定義）               */
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


