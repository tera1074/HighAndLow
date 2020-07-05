#include "stdafx.h"
#include "HighAndLow.h"
#include <stdio.h>
#include <Windows.h>
#define CHARBUFF 124

int readInt(const char *section, const char *keyword, int defaultValue, const char *filePath) {
	return GetPrivateProfileInt(section, keyword, defaultValue, filePath);
}
const char* readChar(const char *section, const char *keyword, const char *defaultValue, char *returnValue, const char *filePath) {
	if (GetPrivateProfileString(section, keyword, defaultValue, returnValue, CHARBUFF, filePath) != 0) {
		/*	fprintf(stdout, "%s,%s\n", filePath, returnValue); */
		return returnValue;
	}
	else {
		fprintf(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyword);
	}
}
double readDouble(const char *section, const char *keyword, double defaultValue, const char *filePath) {
	char buf[CHARBUFF];
	GetPrivateProfileString(section, keyword, "none", buf, CHARBUFF, filePath);
	defaultValue = strtod(buf, NULL);
	return defaultValue;
}
void getCurrentDirectory(char *currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}
bool writeChar(const char *section, const char *keyword, const char *returnValue, const char *filePath) {
	if (WritePrivateProfileString(section, keyword, returnValue, filePath)) {
		return true;
	}
	else {
		fprintf(stderr, "failed to write [$s] %s to %s \n", section, keyword, filePath);
		return false;
	}
}
bool writeInt(const char *section, const char *keyword, int returnValue, const char *filePath) {
	char buf[CHARBUFF];
	sprintf_s(buf, "%d", returnValue);
	if (WritePrivateProfileString(section, keyword, buf, filePath)) {
		return true;
	}
	else {
		fprintf(stderr, "failed to write [$s] %s to %s \n", section, keyword, filePath);
		return false;
	}
}
bool writeDouble(const char *section, const char *keyword, double returnValue, const char *filePath) {
	char buf[CHARBUFF];
	sprintf_s(buf, "%f", returnValue);
	if (WritePrivateProfileString(section, keyword, buf, filePath)) {
		return true;
	}
	else {
		fprintf(stderr, "failed to write [$s] %s to %s \n", section, keyword, filePath);
		return false;
	}
}
