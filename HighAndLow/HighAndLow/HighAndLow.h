#pragma once
int readInt(const char *section, const char *keyword, int defaultValue, const char *filePath);
const char* readChar(const char *section, const char *keyword, const char *defaultValue, char *returnValue, const char *filePath);
double readDouble(const char *section, const char *keyword, double defaultValue, const char *filePath);
void getCurrentDirectory(char *currentDirectory);
bool writeChar(const char *section, const char *keyword, const char *returnValue, const char *filePath);
bool writeInt(const char *section, const char *keyword, int returnValue, const char *filePath);
bool writeDouble(const char *section, const char *keyword, double returnValue, const char *filePath);
int getRand(int x);
void initRand();

