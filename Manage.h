#pragma once


#include "Algorithm.h"
#include "global.h"
#include "Graphics.h"
#include "Manage.h"


void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void CREDITS(int s);

void ExitGame();
void GabageCollect();
void GotoXY(int x, int y);
void HELPS(int s);
void LOADGAME(int s, int& load, char loadg[][100]);
void NewGame(int& pmode, int m, int s);
int ProcessFinish(int pWhoWin,int m);
void ResetData();
void SETTINGS(int& m, int& s);
void StartGame();
char askSave();
void gameClock(int& temp_time_cl, int x, int y);
int move();
void multiplay();
void playAfterLoad(char name[][100], int load);
void sleep(clock_t wait);
char waitKeyBoard();
void saveGame();
void saveNameOfFile(char name[]);
int AskContinue();
void singleplay_PVC(int s, int m);
void printFileName(char s[][100]);