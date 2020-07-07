#include "stdafx.h"
#include "HighAndLow.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE *fp;
errno_t error;

void initRand() {		/*�����̎��ς��邽�߂Ɍ��ݎ������g�p*/
	srand((unsigned int)time(NULL));
}

int getRand(int x) {   /*1�`����x�܂ł̗����𐶐�*/
	return rand() % x + 1;
}

void gameResult(Player x) {    /*���ʂ�csv�t�@�C���ɏo�͂���֐�*/
	error = fopen_s(&fp, "Result.csv", "w");
	if (error != 0) {
		fprintf_s(stderr, "failed to open");
	}
	else {
		fprintf_s(fp, "�v���C���[��,������,��������,�ő�A����\n");
		fprintf_s(fp, "%s,%d,%d,%d\n", x.name, x.money, x.wincount, x.consecutive);
		fclose(fp);
	}
}