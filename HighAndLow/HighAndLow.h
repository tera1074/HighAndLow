#pragma once
int readInt(const char *section, const char *keyword, int defaultValue, const char *filePath);	/*int読み込み*/
const char* readChar(const char *section, const char *keyword, const char *defaultValue, char *returnValue, const char *filePath);	/*文字列読み込み*/
void getCurrentDirectory(char *currentDirectory);
int getRand(int x);		/*乱数生成*/
void initRand();		/*乱数の種初期化*/
struct Player {			/*プレイヤーデータの構造体*/
	const char* name;
	int money;
	int wincount;
	int consecutive;
};
void gameResult(Player x);	/*結果のファイル出力*/

