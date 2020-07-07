#include "stdafx.h"
#include "HighAndLow.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE *fp;
errno_t error;

void initRand() {		/*乱数の種を変えるために現在時刻を使用*/
	srand((unsigned int)time(NULL));
}

int getRand(int x) {   /*1～引数xまでの乱数を生成*/
	return rand() % x + 1;
}

void gameResult(Player x) {    /*結果をcsvファイルに出力する関数*/
	error = fopen_s(&fp, "Result.csv", "w");
	if (error != 0) {
		fprintf_s(stderr, "failed to open");
	}
	else {
		fprintf_s(fp, "プレイヤー名,所持金,総勝利数,最大連勝数\n");
		fprintf_s(fp, "%s,%d,%d,%d\n", x.name, x.money, x.wincount, x.consecutive);
		fclose(fp);
	}
}