#pragma once
int readInt(const char *section, const char *keyword, int defaultValue, const char *filePath);	/*int�ǂݍ���*/
const char* readChar(const char *section, const char *keyword, const char *defaultValue, char *returnValue, const char *filePath);	/*������ǂݍ���*/
void getCurrentDirectory(char *currentDirectory);
int getRand(int x);		/*��������*/
void initRand();		/*�����̎평����*/
struct Player {			/*�v���C���[�f�[�^�̍\����*/
	const char* name;
	int money;
	int wincount;
	int consecutive;
};
void gameResult(Player x);	/*���ʂ̃t�@�C���o��*/

