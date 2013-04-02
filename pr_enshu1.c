#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmpsave.h"


//(1)
#define SIZE_H 40
#define SIZE_W 40

//////////////////////////////////////////////////////////////////////////////
//���̕����͂�����Ȃ��i�֐��v���g�^�C�v�錾�j
void input_pgm(char *imgname, int img[SIZE_H][SIZE_W]);
int getint(FILE *fp);
//////////////////////////////////////////////////////////////////////////////


int main(void)
{
	// �ϐ��錾
	int img[SIZE_H][SIZE_W];
	unsigned char image[SIZE_H * SIZE_W * 3];
	int r, c, rb, re, cb, ce;
	char imgname[256] = "[�t�@�C�������w��ł�]";
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
	


	printf("�摜 %s �̈ꕔ���������Ctest.pgm �Ƃ��ďo�͂��܂����D\n", imgname);
	printf("PGM�摜���m�F���ĉ������D\n");

	exit(0);
}


/**************************************************************************/
/* �������牺�͂�����Ȃ����Ɓi�摜�ǂݍ��݊֐��̒�`�j               */
/**************************************************************************/


void input_pgm(char *imgname, int img[SIZE_H][SIZE_W])
{
	int i, j, g1, c, w, h, maxv;

	FILE *fp;
	fopen_s(&fp, imgname, "r");
	if(fp == NULL)
	{
		printf("���s�G���[�F\n");
		printf("�@�@�@�t�@�C���u%s�v���J���܂���ł����D\n", imgname);
		printf("�@�@�@�t�@�C���̖��O��ꏊ�����������m�F���Ă��������D\n");
		printf("�@�@�@�摜�t�@�C���Ǝ��s�t�@�C���͓����t�H���_�ɂ���K�v������܂��D\n");
		exit(1);
	}

	g1 = getc(fp);
	c = getc(fp);
	w = getint(fp);
	h = getint(fp);
	maxv = getint(fp);

	if(w != SIZE_W || h != SIZE_H)
	{
		printf("���s�G���[�F\n");
		printf("�@�@�@�摜�T�C�Y���s���ł��D\n", SIZE_W, SIZE_H);
		printf("�@�@�@%dx%d�s�N�Z���̉摜����͂��ĉ������D\n", SIZE_W, SIZE_H);
		printf("�@�@�@�܂��́C�\�[�X�t�@�C���̃}�N���u��������%d�C��%d�s�N�Z���ɕύX���ĉ������D\n", h, w);
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
		fprintf(stderr, "���s�G���[�F\n");
		fprintf(stderr, "�@�@�@ ���Ή��̉摜�`���ł��D\n");
		fprintf(stderr, "�@�@�@ �u%s�v��������PGM�摜�t�@�C���ł��邩�m�F���ĉ������D\n", imgname);
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


