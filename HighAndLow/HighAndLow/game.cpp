#include "stdafx.h"
#include "HighAndLow.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initRand() {
	srand((unsigned int)time(NULL));
}

int getRand(int x) {
	return rand() % x + 1;
}