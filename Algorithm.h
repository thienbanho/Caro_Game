#pragma once

#include "Algorithm.h"
#include "global.h"
#include "Graphics.h"
#include "Manage.h"


int CheckBoard(int pX, int pY);
int DemSoXungQuanh();
int Evaluate();
_POINT PVC_hard();
void TakeBack();
int TestBoard();
bool WinnerCheck();
bool checkEmpty(int x, int y);
int countCol();
int countRow();
int countHuyen();
int countSac();
int timeCheck();