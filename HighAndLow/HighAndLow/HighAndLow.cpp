// HighAndLow.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
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
		fprintf_s(stdout, "%d回目のゲームです\n", gamecount+1);
		fprintf_s(stdout, "現在の所持金は%dです\n", money);
		while (betflag == 0) {
			char bet[BUFFSIZE];
			fprintf_s(stdout, "賭け金を選択してください\n");
			fprintf_s(stdout, "50ならA,500ならB,5000ならCを入力してください。\n");
			scanf_s("%s", &bet);
			if (!strcmp(bet, "A")) {
				if (money >= 50) {
					betmoney = 50;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "賭け金が所持金を超えています\n");
				}
			}
			if (!strcmp(bet, "B")) {
				if (money >= 500) {
					betmoney = 500;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "賭け金が所持金を超えています\n");
				}
			}
			if (!strcmp(bet, "C")) {
				if (money >= 5000) {
					betmoney = 5000;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "賭け金が所持金を超えています\n");
				}
			}
		}
		fprintf_s(stdout, "賭け金は%dです\n", betmoney);
		money = money - betmoney;
		getmoney = betmoney;
		while (winflag == 0) {
			targetNum = getRand(9);
			compareNum = getRand(9);
			fprintf_s(stdout, "次の数字は%dよりhighかlowかどちらでしょう！\n", targetNum);
			while (trueflag == 0) {
				fprintf_s(stdout, "highかlowかstopを入力してください\n");
				scanf_s("%s", &str);
				if (!strcmp(str, "high") || !strcmp(str, "low") || !strcmp(str, "stop")) {
					trueflag = 1;
				}
			}
			trueflag = 0;
			if (!strcmp(str, "high")) {
				fprintf_s(stdout, "%dでした！\n", compareNum);
				fprintf_s(stdout, "your choice is high!\n");
				if (targetNum < compareNum) {
					fprintf_s(stdout, "正解です、すばらしい！\n");
					wincount++;
					tmp++;
					if (tmp > consecutive) {
						consecutive = tmp;
					}
					getmoney = getmoney * 2;
					fprintf_s(stdout, "現在の獲得金は%dです\n", getmoney);
				}
				else if (targetNum == compareNum) {
					fprintf_s(stdout, "同じです、もう一度！\n");
				}
				else {
					fprintf_s(stdout, "不正解です、残念！\n");
					winflag = 1;
					gamecount++;
					getmoney = 0;
				}
			}
			else if (!strcmp(str, "low")) {
				fprintf_s(stdout, "%dでした！\n", compareNum);
				fprintf_s(stdout, "your choice is low!\n");
				if (targetNum > compareNum) {
					fprintf_s(stdout, "正解です、すばらしい！\n");
					tmp++;
					if (tmp > consecutive) {
						consecutive = tmp;
					}
					wincount++;
					getmoney = getmoney * 2;
					fprintf_s(stdout, "現在の獲得金は%dです\n", getmoney);
				}
				else if (targetNum == compareNum) {
					fprintf_s(stdout, "同じです、もう一度！\n");
				}
				else {
					fprintf_s(stdout, "不正解です、残念！\n");
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
	fprintf_s(stdout, "終了です、お疲れさまでした\n");
	fprintf_s(stdout, "総勝利数は%dです\n",wincount);
	fprintf_s(stdout, "最大連勝数は%dです\n", consecutive);
	fprintf_s(stdout, "所持金は%dです\n", money);



    return 0;
}

