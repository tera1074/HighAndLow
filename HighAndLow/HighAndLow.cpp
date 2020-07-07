// HighAndLow.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "HighAndLow.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include <ctype.h>
#define CHARBUFF 124
int targetNum = 0;    /*�\������鐔��*/
int compareNum = 0;   /*�\������鐔���ɔ�ׂč������Ⴂ�����Ă鐔��*/
char str[CHARBUFF];
int trueflag = 0;    /*�����������񂪓��͂��ꂽ�����肷��ϐ�*/
int winflag = 0;     /*���s�𔻒肷��ϐ�*/
int wincount = 0;    /*��������*/
int money = 0;       /*������*/
int betmoney = 0;    /*�q����*/
int getmoney = 0;    /*�l����*/
int gamecount = 0;   /*�Q�[����*/
int betflag = 0;     /*�|�����I���������������肷��ϐ�*/
int consecutive = 0; /*�ő�A����*/

int main()
{
	char currentDirectory[CHARBUFF];    /*ini�t�@�C���ǂݍ��ݐݒ�*/
	getCurrentDirectory(currentDirectory);
	char section[CHARBUFF];
	sprintf_s(section, "section1");
	char keyword[CHARBUFF];
	sprintf_s(keyword, "name");
	char filePath[CHARBUFF];
	sprintf_s(filePath, "%s\\HighAndLow.ini", currentDirectory);
	char returnValue[CHARBUFF];

	Player p1;
	p1.name = readChar(section, keyword, "none", returnValue, filePath); /*ini�t�@�C������v���C���[���ǂݍ���*/
	sprintf_s(keyword, "money");
	p1.money = readInt(section, keyword, -1, filePath);  /*ini�t�@�C�����珊�����ǂݍ���*/
	money = p1.money;
	initRand();  /*�����̎��������*/
	while (gamecount < 5 && money != 0) {   /*�Q�[���񐔂�5��ȉ�����������0�łȂ��ꍇ�Q�[�����s��*/
		int tmp = 0;					/*�Q�[�����Ƃ̘A�����ۑ��p�ϐ�*/
		fprintf_s(stdout, "%d��ڂ̃Q�[���ł�\n", gamecount+1);
		fprintf_s(stdout, "���݂̏�������%d�ł�\n", money);
		while (betflag == 0) {    /*�q�����I������*/
			char bet[CHARBUFF];
			fprintf_s(stdout, "�q������I�����Ă�������\n");
			fprintf_s(stdout, "50�Ȃ�A,500�Ȃ�B,5000�Ȃ�C,�S�z�Ȃ�D����͂��Ă��������B\n");
			scanf_s("%s", &bet);  /*���͂�ǂݍ���*/
			if (!strcmp(bet, "A")) {  /*���͂�A�̂Ƃ�*/
				if (money >= 50) {   /*��������50�ȏ�Ȃ�q������50�ɂ��A���[�v�𔲂���*/
					betmoney = 50;
					betflag = 1;
				}
				else {   /*��������50��菭�Ȃ�*/
					fprintf_s(stdout, "�q�������������𒴂��Ă��܂�\n");
				}
			}
			if (!strcmp(bet, "B")) {    /*���͂�B�̏ꍇ�i������A�Ɠ��l�j*/
				if (money >= 500) {
					betmoney = 500;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "�q�������������𒴂��Ă��܂�\n");
				}
			}
			if (!strcmp(bet, "C")) {    /*���͂�C�̏ꍇ�i������A�Ɠ��l)*/
				if (money >= 5000) {
					betmoney = 5000;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "�q�������������𒴂��Ă��܂�\n");
				}
			}
			if (!strcmp(bet, "D")) {    /*���͂�D�̏ꍇ*/
				betmoney = money;		/*�q�������������Ɠ��z�ɂ���*/
				betflag = 1;
			}
		}
		fprintf_s(stdout, "�q������%d�ł�\n", betmoney);
		money = money - betmoney;		/*����������q����������*/
		getmoney = betmoney;			/*�l������q������*/
		while (winflag == 0) {			/*�Q�[���ɕ����Ȃ����胋�[�v*/
			targetNum = getRand(9);		/*��̂P����X�̗�������*/
			compareNum = getRand(9);
			fprintf_s(stdout, "���̐�����%d���high��low���ǂ���ł��傤�I\n", targetNum);
			while (trueflag == 0) {		/*���������͂�����܂Ń��[�v*/
				fprintf_s(stdout, "high��low��stop����͂��Ă�������\n");
				scanf_s("%s", &str);	/*���͓ǂݍ���*/
				if (!strcmp(str, "high") || !strcmp(str, "low") || !strcmp(str, "stop")) {	/*���͂�high��low��stop�Ȃ烋�[�v�𔲂���*/
					trueflag = 1;
				}
			}
			trueflag = 0;		/*trueflag��߂��Ă���*/
			if (!strcmp(str, "high")) {		/*���͂�high�̂Ƃ�*/
				fprintf_s(stdout, "%d�ł����I\n", compareNum);
				fprintf_s(stdout, "your choice is high!\n");
				if (targetNum < compareNum) {		/*�I�����������ꍇ*/
					fprintf_s(stdout, "�����ł��A���΂炵���I\n");
					wincount++;						/*���������������Z*/
					tmp++;							/*�A�������Z*/
					if (tmp > consecutive) {		/*���A������consecutive���傫����΍X�V*/
						consecutive = tmp;
					}
					getmoney = getmoney * 2;		/*�l������2�{*/
					fprintf_s(stdout, "���݂̊l������%d�ł�\n", getmoney);
				}
				else if (targetNum == compareNum) { /*��̐����������Ƃ�*/
					fprintf_s(stdout, "�����ł��A������x�I\n");
				}
				else {								/*�s�����̎�*/
					fprintf_s(stdout, "�s�����ł��A�c�O�I\n");
					winflag = 1;					/*�������̂Ń��[�v�𔲂���*/
					gamecount++;					/*�Q�[���������Z*/
					getmoney = 0;					/*�l�����v��*/
				}
			}
			else if (!strcmp(str, "low")) {			/*���͂�low�̂Ƃ��i������high�Ƃقړ���)*/
				fprintf_s(stdout, "%d�ł����I\n", compareNum);
				fprintf_s(stdout, "your choice is low!\n");
				if (targetNum > compareNum) {
					fprintf_s(stdout, "�����ł��A���΂炵���I\n");
					tmp++;
					if (tmp > consecutive) {
						consecutive = tmp;
					}
					wincount++;
					getmoney = getmoney * 2;
					fprintf_s(stdout, "���݂̊l������%d�ł�\n", getmoney);
				}
				else if (targetNum == compareNum) {
					fprintf_s(stdout, "�����ł��A������x�I\n");
				}
				else {
					fprintf_s(stdout, "�s�����ł��A�c�O�I\n");
					winflag = 1;
					gamecount++;
					getmoney = 0;
				}
			}
			else if (!strcmp(str, "stop")) {		/*���͂�stop�̂Ƃ�*/
				winflag = 1;						/*���[�v�𔲂���*/
				gamecount++;						/*�Q�[�������Z*/
				fprintf_s(stdout, "your choice is stop!\n");
				money = money + getmoney;			/*�������Ɋl���������Z*/
			}
			Sleep(1000);							/*�����������ɂȂ�Ȃ��悤1�b�҂�*/
		}
		winflag = 0;								/*�e�t���b�O��߂�*/
		betflag = 0;
	}
	p1.money = money;								/*�\���̂Ɍ��ʂ���*/
	p1.wincount = wincount;
	p1.consecutive = consecutive;
	fprintf_s(stdout, "�I���ł��A����ꂳ�܂ł���\n");
	fprintf_s(stdout, "����������%d�ł�\n",p1.wincount);
	fprintf_s(stdout, "�ő�A������%d�ł�\n", p1.consecutive);
	fprintf_s(stdout, "��������%d�ł�\n", p1.money);
	gameResult(p1);									/*���ʂ��t�@�C���o��*/
    return 0;
}

