// HighAndLow.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "HighAndLow.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include <ctype.h>
#define BUFFSIZE 1024
int targetNum = 0;
int compareNum = 0;
char str[BUFFSIZE];
int trueflag = 0;
int winflag = 0;
int wincount = 0;
int money = 2500;
int betmoney = 0;
int getmoney = 0;
int gamecount = 0;
int betflag = 0;
int consecutive = 0;

int main()
{
	srand((int)time(NULL));
	while (gamecount < 5 && money != 0) {
		int tmp = 0;
		fprintf_s(stdout, "%d��ڂ̃Q�[���ł�\n", gamecount+1);
		fprintf_s(stdout, "���݂̏�������%d�ł�\n", money);
		while (betflag == 0) {
			char bet[BUFFSIZE];
			fprintf_s(stdout, "�q������I�����Ă�������\n");
			fprintf_s(stdout, "50�Ȃ�A,500�Ȃ�B,5000�Ȃ�C����͂��Ă��������B\n");
			scanf_s("%s", &bet);
			if (!strcmp(bet, "A")) {
				if (money >= 50) {
					betmoney = 50;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "�q�������������𒴂��Ă��܂�\n");
				}
			}
			if (!strcmp(bet, "B")) {
				if (money >= 500) {
					betmoney = 500;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "�q�������������𒴂��Ă��܂�\n");
				}
			}
			if (!strcmp(bet, "C")) {
				if (money >= 5000) {
					betmoney = 5000;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "�q�������������𒴂��Ă��܂�\n");
				}
			}
		}
		fprintf_s(stdout, "�q������%d�ł�\n", betmoney);
		money = money - betmoney;
		getmoney = betmoney;
		while (winflag == 0) {
			targetNum = getRand(9);
			compareNum = getRand(9);
			fprintf_s(stdout, "���̐�����%d���high��low���ǂ���ł��傤�I\n", targetNum);
			while (trueflag == 0) {
				fprintf_s(stdout, "high��low��stop����͂��Ă�������\n");
				scanf_s("%s", &str);
				if (!strcmp(str, "high") || !strcmp(str, "low") || !strcmp(str, "stop")) {
					trueflag = 1;
				}
			}
			trueflag = 0;
			if (!strcmp(str, "high")) {
				fprintf_s(stdout, "%d�ł����I\n", compareNum);
				fprintf_s(stdout, "your choice is high!\n");
				if (targetNum < compareNum) {
					fprintf_s(stdout, "�����ł��A���΂炵���I\n");
					wincount++;
					tmp++;
					if (tmp > consecutive) {
						consecutive = tmp;
					}
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
			else if (!strcmp(str, "low")) {
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
			else if (!strcmp(str, "stop")) {
				winflag = 1;
				gamecount++;
				fprintf_s(stdout, "your choice is stop!\n");
				money = money + getmoney;
			}
			Sleep(1000);
		}
		winflag = 0;
		betflag = 0;
	}
	fprintf_s(stdout, "�I���ł��A����ꂳ�܂ł���\n");
	fprintf_s(stdout, "����������%d�ł�\n",wincount);
	fprintf_s(stdout, "�ő�A������%d�ł�\n", consecutive);
	fprintf_s(stdout, "��������%d�ł�\n", money);



    return 0;
}

