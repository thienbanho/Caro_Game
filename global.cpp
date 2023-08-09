#include "Algorithm.h"
#include "global.h"
#include "Graphics.h"
#include "Manage.h"

_POINT LastMove;
_POINT _A[_BOARD_SIZE][_BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;
int _loop;
int _count; //Đếm số nước đã đi để tính hòa
HANDLE hConsoleColor;
clock_t start;
int timeCountDownX;
int timeCountDownO;
FILE* ffile;
int m , s;


Menu::Menu() {

	item = new string[100];

	_numberOfItem = 6;

	item[0] = "NEW GAME";

	item[1] = "LOAD GAME";

	item[2] = "SETTINGS";

	item[3] = "CREDITS ";

	item[4] = "HELPS";

	item[5] = "EXIT";

}
void Menu::printMenu() {
	Mainmenu();
	SetConsoleTextAttribute(hConsoleColor, 240);
	for (int i = 0 + 14; i < _numberOfItem + 14; i++) {

		gotoxy(55, i);

		cout << item[i - 14] << endl;

		Sleep(100); //Tạm dừng 100ms

	}
}
void Menu::deleteMenu() {

	for (int i = 0; i < 30; i++) {

		Sleep(30);

		gotoxy(0, i);

		for (int j = 0; j < 119; j++) {
			cout << " "; //Xóa bằng cách ghi đè kí tự trắng

		}

	}

}
Settings::Settings() {
	item = new string[100];
	_numberOfItem = 3;
	item[0] = "MUSIC: ";
	item[1] = "  SFX: ";
	item[2] = "  BACK";
}
void Settings::printMenu() {
	settings();
	SetConsoleTextAttribute(hConsoleColor, 240);
	gotoxy(79, 14);
	cout << item[0] << endl;
	Sleep(10);
	gotoxy(79, 14 + 5);
	cout << item[1] << endl;
	Sleep(10);
	gotoxy(79, 14 + 5 + 5);
	cout << item[2] << endl;
	Sleep(10);
}
NewGameMenu::NewGameMenu() {
	item = new string[100];

	_numberOfItem = 3;

	item[0] = "SINGLEPLAYER (PvB)";

	item[1] = "MULTIPLAYER (PvP)";

	item[2] = "      BACK        ";

};
void NewGameMenu::printMenu() {
	newgame();
	SetConsoleTextAttribute(hConsoleColor, 240);
	gotoxy(48, 6);
	cout << item[0] << endl;
	Sleep(100);
	gotoxy(48, 6 + 5);
	cout << item[1] << endl;
	Sleep(100);
	gotoxy(48, 6 + 5 + 5);
	cout << item[2] << endl;
	Sleep(100);
}
void NewGameMenu::deleteMenu() {

	for (int i = 0; i < 30; i++) {

		Sleep(10);

		gotoxy(0, i);

		for (int j = 0; j < 119; j++) {
			cout << " "; //Xóa bằng cách ghi đè kí tự trắng

		}

	}

}
