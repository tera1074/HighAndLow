#include "stdafx.h"
#include "HighAndLow.h"
#include <stdio.h>
#include <Windows.h>
#define CHARBUFF 124

int readInt(const char *section, const char *keyword, int defaultValue, const char *filePath) {    /*intì«Ç›çûÇ›ä÷êî*/
	return GetPrivateProfileInt(section, keyword, defaultValue, filePath);
}
const char* readChar(const char *section, const char *keyword, const char *defaultValue, char *returnValue, const char *filePath) {  /*ï∂éöóÒì«Ç›çûÇ›ä÷êî*/
	if (GetPrivateProfileString(section, keyword, defaultValue, returnValue, CHARBUFF, filePath) != 0) {
		/*	fprintf(stdout, "%s,%s\n", filePath, returnValue); */
		return returnValue;
	}
	else {
		fprintf(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyword);
	}
}
void getCurrentDirectory(char *currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}