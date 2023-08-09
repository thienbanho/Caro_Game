#pragma once
#include "Algorithm.h"
#include "global.h"
#include "Graphics.h"
#include "Manage.h"

void moveEffect(int s);
void _moveEffect();
void DRAW_animate();
void HieuUngBanCo();
void Mainmenu();
void X_WIN_animate();
void O_WIN_animate();
void TextColor(int x);
void changeColor(int x, int y, int a, int b);
void credits();
void draw_number(int number, int x, int y, int color);
void drawGameTable(int width, int height, int x, int y);
void drawX();
void drawO();
void drawV();
void drawPlay();
int getCommand();
void gotoxy(int column, int line);
void helps();
int loadGame(const char name[]);
void loadgame();
void newgame();
void settings();
void redToWhite();
void winLine_on();
void winLine_off();
void winLineBlink();
void winEffect();
void timeCountDown(int& temp_time, bool& bufTurn, int x1, int y1, int x2, int y2);
void DrawBoard(int n);