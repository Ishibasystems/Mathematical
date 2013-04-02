#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIZE_H 40	//�摜�̍����iHeight�j
#define SIZE_W 40	//�摜�̕��iWidth�j


//(1)
#define INUM 50
#define FNUM 3

//////////////////////////////////////////////////////////////////////////////
//���̕����͂�����Ȃ��i�֐��v���g�^�C�v�錾�j
void input_pgm(char *imgname, int img[SIZE_H][SIZE_W]);
int getint(FILE *fp);
//////////////////////////////////////////////////////////////////////////////


int main(void)
{
	// �ϐ��錾�i���ɕK�v�ƂȂ�ϐ��͊e���Ő錾���邱�Ɓj
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
			if (f >= theta[h]) printf("%f��%f: ��\n", f, theta[h], vote++);
			else printf("%f��%f: not��\n", f, theta[h]);
		}
		printf("%d��%d��: ��Ɣ��� �� ���������%s�͊�摜%s\n", FNUM, vote, imgname, vote >= 0.5 * FNUM ? "" : "�ł͂Ȃ�");
		w += (vote >= 0.5 * FNUM) ^ (i > 24);
	}
	printf("RESULT: %f%%\n", 100.0 * w / 50);

	exit(0);
}


/**************************************************************************/
/* �������牺�͂�����Ȃ����Ɓi�摜�ǂݍ��ݗp�̊֐��̒�`�j               */
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


