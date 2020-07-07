// HighAndLow.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "HighAndLow.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include <ctype.h>
#define CHARBUFF 124
int targetNum = 0;    /*表示される数字*/
int compareNum = 0;   /*表示される数字に比べて高いか低いか当てる数字*/
char str[CHARBUFF];
int trueflag = 0;    /*正しい文字列が入力されたか判定する変数*/
int winflag = 0;     /*勝敗を判定する変数*/
int wincount = 0;    /*総勝利数*/
int money = 0;       /*所持金*/
int betmoney = 0;    /*賭け金*/
int getmoney = 0;    /*獲得金*/
int gamecount = 0;   /*ゲーム数*/
int betflag = 0;     /*掛け金選択が正しいか判定する変数*/
int consecutive = 0; /*最大連勝数*/

int main()
{
	char currentDirectory[CHARBUFF];    /*iniファイル読み込み設定*/
	getCurrentDirectory(currentDirectory);
	char section[CHARBUFF];
	sprintf_s(section, "section1");
	char keyword[CHARBUFF];
	sprintf_s(keyword, "name");
	char filePath[CHARBUFF];
	sprintf_s(filePath, "%s\\HighAndLow.ini", currentDirectory);
	char returnValue[CHARBUFF];

	Player p1;
	p1.name = readChar(section, keyword, "none", returnValue, filePath); /*iniファイルからプレイヤー名読み込み*/
	sprintf_s(keyword, "money");
	p1.money = readInt(section, keyword, -1, filePath);  /*iniファイルから所持金読み込み*/
	money = p1.money;
	initRand();  /*乱数の種を初期化*/
	while (gamecount < 5 && money != 0) {   /*ゲーム回数が5回以下か所持金が0でない場合ゲームを行う*/
		int tmp = 0;					/*ゲームごとの連勝数保存用変数*/
		fprintf_s(stdout, "%d回目のゲームです\n", gamecount+1);
		fprintf_s(stdout, "現在の所持金は%dです\n", money);
		while (betflag == 0) {    /*賭け金選択処理*/
			char bet[CHARBUFF];
			fprintf_s(stdout, "賭け金を選択してください\n");
			fprintf_s(stdout, "50ならA,500ならB,5000ならC,全額ならDを入力してください。\n");
			scanf_s("%s", &bet);  /*入力を読み込み*/
			if (!strcmp(bet, "A")) {  /*入力がAのとき*/
				if (money >= 50) {   /*所持金が50以上なら賭け金を50にし、ループを抜ける*/
					betmoney = 50;
					betflag = 1;
				}
				else {   /*所持金が50より少ない*/
					fprintf_s(stdout, "賭け金が所持金を超えています\n");
				}
			}
			if (!strcmp(bet, "B")) {    /*入力がBの場合（処理はAと同様）*/
				if (money >= 500) {
					betmoney = 500;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "賭け金が所持金を超えています\n");
				}
			}
			if (!strcmp(bet, "C")) {    /*入力がCの場合（処理はAと同様)*/
				if (money >= 5000) {
					betmoney = 5000;
					betflag = 1;
				}
				else {
					fprintf_s(stdout, "賭け金が所持金を超えています\n");
				}
			}
			if (!strcmp(bet, "D")) {    /*入力がDの場合*/
				betmoney = money;		/*賭け金を所持金と同額にする*/
				betflag = 1;
			}
		}
		fprintf_s(stdout, "賭け金は%dです\n", betmoney);
		money = money - betmoney;		/*所持金から賭け金を引く*/
		getmoney = betmoney;			/*獲得金を賭け金へ*/
		while (winflag == 0) {			/*ゲームに負けない限りループ*/
			targetNum = getRand(9);		/*二つの１から９の乱数生成*/
			compareNum = getRand(9);
			fprintf_s(stdout, "次の数字は%dよりhighかlowかどちらでしょう！\n", targetNum);
			while (trueflag == 0) {		/*正しい入力があるまでループ*/
				fprintf_s(stdout, "highかlowかstopを入力してください\n");
				scanf_s("%s", &str);	/*入力読み込み*/
				if (!strcmp(str, "high") || !strcmp(str, "low") || !strcmp(str, "stop")) {	/*入力がhighかlowかstopならループを抜ける*/
					trueflag = 1;
				}
			}
			trueflag = 0;		/*trueflagを戻しておく*/
			if (!strcmp(str, "high")) {		/*入力がhighのとき*/
				fprintf_s(stdout, "%dでした！\n", compareNum);
				fprintf_s(stdout, "your choice is high!\n");
				if (targetNum < compareNum) {		/*選択が正しい場合*/
					fprintf_s(stdout, "正解です、すばらしい！\n");
					wincount++;						/*総勝利数を一回加算*/
					tmp++;							/*連勝数加算*/
					if (tmp > consecutive) {		/*現連勝数がconsecutiveより大きければ更新*/
						consecutive = tmp;
					}
					getmoney = getmoney * 2;		/*獲得金を2倍*/
					fprintf_s(stdout, "現在の獲得金は%dです\n", getmoney);
				}
				else if (targetNum == compareNum) { /*二つの数字が同じとき*/
					fprintf_s(stdout, "同じです、もう一度！\n");
				}
				else {								/*不正解の時*/
					fprintf_s(stdout, "不正解です、残念！\n");
					winflag = 1;					/*負けたのでループを抜ける*/
					gamecount++;					/*ゲーム数を加算*/
					getmoney = 0;					/*獲得金没収*/
				}
			}
			else if (!strcmp(str, "low")) {			/*入力がlowのとき（処理はhighとほぼ同じ)*/
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
			else if (!strcmp(str, "stop")) {		/*入力がstopのとき*/
				winflag = 1;						/*ループを抜ける*/
				gamecount++;						/*ゲーム数加算*/
				fprintf_s(stdout, "your choice is stop!\n");
				money = money + getmoney;			/*所持金に獲得金を加算*/
			}
			Sleep(1000);							/*乱数が同じにならないよう1秒待つ*/
		}
		winflag = 0;								/*各フラッグを戻す*/
		betflag = 0;
	}
	p1.money = money;								/*構造体に結果を代入*/
	p1.wincount = wincount;
	p1.consecutive = consecutive;
	fprintf_s(stdout, "終了です、お疲れさまでした\n");
	fprintf_s(stdout, "総勝利数は%dです\n",p1.wincount);
	fprintf_s(stdout, "最大連勝数は%dです\n", p1.consecutive);
	fprintf_s(stdout, "所持金は%dです\n", p1.money);
	gameResult(p1);									/*結果をファイル出力*/
    return 0;
}

