#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <vector>
#include <time.h>
#include <string.h>
#include<io.h>
#include<fcntl.h>


#define _BOARD_SIZE 12
#define _LEFT 10
#define _TOP 5


#define trentrai 201
#define ngang 205
#define	trenphai 187
#define trenngang 203
#define doc 186
#define doctrai 204 
#define	docphai 185
#define docngang 206
#define duoitrai 200
#define duoiphai 188
#define duoingnang 202

using namespace std;

/*
Golbal.h
exterrn int a;

Global.cpp
int a;
*/

struct _POINT {
	int x, y, c;

	_POINT() : x(0), y(0) {}
	_POINT(int x, int y) : x(x), y(y) {}
	bool operator==(const _POINT& other) const {
		return (x == other.x && y == other.y);
	}
	bool operator!=(const _POINT& other) const {
		return !(*this == other);
	}
	_POINT operator-(const _POINT& other) const {
		return _POINT(x - other.x, y - other.y);
	}
	int length() const {
		return abs(x) + abs(y);
	}

	// phương thức trả về giá trị của ô cờ (_Cell) đang xét
	int getCheck() {
		if (c == 1) {
			return -1; // giá trị của ô là O
		}
		else if (c == -1) {
			return 1; // giá trị của ô là X
		}
		else {
			return 0; // giá trị của ô là rỗng
		}
	}

	void setCheck(int value) {
		if (value == -1 || value == 0 || value == 1) {
			c = value;
		}
	}
};
class _Point {
	int _X;
	int _Y;
	int _check;
public:
	int GetCheck() { return _check; }
	int GetX() { return _X; }
	int GetY() { return _Y; }
	bool setCheck(int value) {
		if (value == -1 || value == 1 || value == 0) {
			_check = value;
			return true;
		}
		return false;
	}
};
class Menu {

public:

	Menu();

	~Menu() {}

	void printMenu();

	void deleteMenu(); //Xóa menu khi kết thúc chương trình bằng cách viết đè kí tự trắng

	int numberOfItem() {
		return _numberOfItem;
	}

	string* getItem() {
		return item;
	}

private:

	string* item; //Mảng lưu tên của các menu

	int _numberOfItem; //Số lượng menu

};


extern _POINT LastMove;
extern _POINT _A[_BOARD_SIZE][_BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;
extern int _loop;
extern int _count; //Đếm số nước đã đi để tính hòa
extern HANDLE hConsoleColor;
extern clock_t start;
extern int timeCountDownX;
extern int timeCountDownO;
extern int m, s;

extern FILE* ffile;

class NewGameMenu {
public:

	NewGameMenu();

	~NewGameMenu() {}

	void printMenu();

	void deleteMenu(); //Xóa menu khi kết thúc chương trình bằng cách viết đè kí tự trắng

	int numberOfItem() {
		return _numberOfItem;
	}

	string* getItem() {
		return item;
	}

private:

	string* item; //Mảng lưu tên của các menu

	int _numberOfItem; //Số lượng menu

};

class Settings {
public:

	Settings();

	~Settings() {}

	void printMenu();


	int numberOfItem() {
		return _numberOfItem;
	}

	string* getItem() {
		return item;
	}

private:

	string* item; //Mảng lưu tên của các menu

	int _numberOfItem; //Số lượng menu

};
