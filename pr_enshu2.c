#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIZE_H 40	//�摜�̍����iHeight�j
#define SIZE_W 40	//�摜�̕��iWidth�j


//(1)
#define INUM 50

//////////////////////////////////////////////////////////////////////////////
//���̕����͂�����Ȃ��i�֐��v���g�^�C�v�錾�j
void input_pgm(char *imgname, int img[SIZE_H][SIZE_W]);
int getint(FILE *fp);
//////////////////////////////////////////////////////////////////////////////


int main(void)
{
	// �ϐ��錾�i���ɕK�v�ƂȂ�ϐ��͊e���Ő錾���邱�Ɓj
	int img[SIZE_H][SIZE_W];
	int i, r, c, num, w = 0;
	int rb1, re1, cb1, ce1;
	int rb2, re2, cb2, ce2;
	double theta;
	double mean1, mean2, f;
	char imgname[256];


	//(2)
	rb1 = 30;
	re1 = 35;
	cb1 = 10;
	ce1 = 28;
	rb2 = 20;
	re2 = 25;
	cb2 = 27;
	ce2 = 37;
	theta = 10;

	//(3)
	for(i = 0; i < INUM; i++)
	{
		//(4)
		sprintf(imgname, "data/image%03d.pgm", i);
		input_pgm(imgname, img);

		//(5a)
		mean1 = 0.0;
		for(r = rb1; r <= re1; r++)
			for(c = cb1; c <= ce1; c++)
				mean1 += (double)img[r][c] / (re1 - rb1 + 1) / (ce1 - cb1 + 1);

		//(5b)
		mean2 = 0.0;
		for(r = rb2; r <= re2; r++)
			for(c = cb2; c <= ce2; c++)
				mean2 += (double)img[r][c] / (re2 - rb2 + 1) / (ce2 - cb2 + 1);

		//(6)
		f = mean2 - mean1;

		//(7)
		if (f >= theta)
		{
			printf("%f��%f���A%s�͊�摜\n", f, theta, imgname);
			if (i <= 24) w++;
		}
		else
		{
			printf("%f��%f���A%s�͊�摜�ł͂Ȃ�\n", f, theta, imgname);
			if (i > 24) w++;
		}

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


