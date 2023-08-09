
#include "Algorithm.h"
#include "global.h"
#include "Graphics.h"
#include "Manage.h"

void MoveRight() {
	_moveEffect();
	if (_X < _A[_BOARD_SIZE - 1][_BOARD_SIZE - 1].x)
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
	else
	{
		_X = _A[0][0].x;
		GotoXY(_X, _Y);
	}
	moveEffect(s);
}
void MoveLeft() {
	_moveEffect();
	if (_X > _A[0][0].x) {
		_X -= 4;
		GotoXY(_X, _Y);
	}
	else
	{
		_X = _A[_BOARD_SIZE - 1][_BOARD_SIZE - 1].x;
		GotoXY(_X, _Y);

	}
	moveEffect(s);

}
void MoveDown() {
	_moveEffect();
	if (_Y < _A[_BOARD_SIZE - 1][_BOARD_SIZE - 1].y)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
	else
	{
		_Y = _A[0][0].y;
		GotoXY(_X, _Y);
	}
	moveEffect(s);
}
void MoveUp() {
	_moveEffect();
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
	else
	{
		_Y = _A[_BOARD_SIZE - 1][_BOARD_SIZE - 1].y;
		GotoXY(_X, _Y);
	}
	moveEffect(s);

}
void CREDITS(int s) {
	int x_CRE;
	bool BACK_CRE = false;
	int line_CRE = 26;
	credits();
	gotoxy(52, 26);
	SetConsoleTextAttribute(hConsoleColor, 222);
	cout << "RETURN TO MENU";
	SetConsoleTextAttribute(hConsoleColor, 255);
	while (!BACK_CRE) {
		if (_kbhit()) {
			x_CRE = move();
			if (x_CRE == 5) {
				if (s % 2 == 0)
					PlaySound(TEXT("enter.wav"), NULL, SND_ASYNC);
				BACK_CRE = true;
			}
		}
	}
}

void ExitGame() {
	system("cls");
	GabageCollect();
	//Có thể lưu game trước khi exit
}
void GabageCollect()
{
	// Dọn dẹp tài nguyên nếu có khai báo con trỏ
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void HELPS(int s) {
	int x_HELP;
	bool BACK_HELP = false;
	int line_HELP = 18;
	helps();
	gotoxy(53, 18);
	SetConsoleTextAttribute(hConsoleColor, 222);
	cout << "BACK";
	SetConsoleTextAttribute(hConsoleColor, 255);
	while (!BACK_HELP) {
		if (_kbhit()) {
			x_HELP = move();
			if (x_HELP == 5) {
				if (s % 2 == 0)
					PlaySound(TEXT("enter.wav"), NULL, SND_ASYNC);
				BACK_HELP = true;
			}
		}
	}
}
void LOADGAME(int s, int& load, char loadg[][100]) {
	int x_LG, line_LG = 11;
	bool EXIT_LG = false;
	loadgame();
	printFileName(loadg);
	SetConsoleTextAttribute(hConsoleColor, 6);
	gotoxy(55, 26);
	cout << "BACK";
	SetConsoleTextAttribute(hConsoleColor, 224);
	gotoxy(48, 11);
	cout << ">>";
	while (!EXIT_LG) {
		if (_kbhit()) {
			x_LG = move();
			gotoxy(48, line_LG);
			if (line_LG == 26) {
				SetConsoleTextAttribute(hConsoleColor, 0);
				cout << "  "; //Xóa con trỏ ở vị trí cũ
				SetConsoleTextAttribute(hConsoleColor, 244);
			}
			else {
				SetConsoleTextAttribute(hConsoleColor, 238);
				cout << "  "; //Xóa con trỏ ở vị trí cũ
				SetConsoleTextAttribute(hConsoleColor, 224);
			}
			switch (x_LG) {
			case 1:if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			case 3:
			{if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			line_LG += 3;
			if (line_LG >= 26 + 1) line_LG = 11;
			break;
			}
			case 2:if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			case 4:
			{if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			line_LG -= 3;
			if (line_LG < 11) line_LG = 26;
			break;
			}
			case 5:
			{	if (s % 2 == 0)
				PlaySound(TEXT("enter.wav"), NULL, SND_ASYNC);
			}
			EXIT_LG = true;
			break;
			}
		}
		if (line_LG == 26) {
			gotoxy(48, line_LG);
			SetConsoleTextAttribute(hConsoleColor, 15);
			cout << ">>";
		}
		else {
			gotoxy(48, line_LG);
			SetConsoleTextAttribute(hConsoleColor, 224);
			cout << ">>";
		}
		SetConsoleTextAttribute(hConsoleColor, 255);
		load = line_LG;
	}
}
void NewGame(int& pmode, int m, int s) {
	NewGameMenu newGame;
	int x_NG;
	int line_NG = 6;
	bool BACK_NG = false;
	newGame.printMenu();
	SetConsoleTextAttribute(hConsoleColor, 240);
	gotoxy(45, line_NG);
	cout << ">";
	while (!BACK_NG) {
		if (_kbhit()) {
			x_NG = move();
			gotoxy(45, line_NG);
			SetConsoleTextAttribute(hConsoleColor, 255);
			cout << " "; //Xóa con trỏ ở vị trí cũ
			SetConsoleTextAttribute(hConsoleColor, 240);
			switch (x_NG) {
			case 1:if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			case 3:
			{
				if (s % 2 == 0)
					PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
				line_NG += 5;
				if (line_NG >= newGame.numberOfItem() + 5 + 5 + 6) line_NG = 6;
				break;
			}
			case 2:if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			case 4:
			{
				if (s % 2 == 0)
					PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
				line_NG -= 5;
				if (line_NG < 6) line_NG = newGame.numberOfItem() - 1 + 6 + 3 + 5;
				break;
			}

			case 5:
			{
				pmode = line_NG;
				if (s % 2 == 0)
					PlaySound(TEXT("enter.wav"), NULL, SND_ASYNC);
				BACK_NG = true;
				break;
			}
			}
			gotoxy(45, line_NG);
			SetConsoleTextAttribute(hConsoleColor, 240);
			cout << ">";
		}
	}
}
int ProcessFinish(int pWhoWin, int m) {
	GotoXY(0, _A[_BOARD_SIZE - 1][_BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí
	// thích hợp để in chuỗi thắng/thua/hòa
	switch (pWhoWin) {
	case -1:
		//TextColor(240);
		winEffect();
		gotoxy(0, 10);
		X_WIN_animate();
		sleep(2000);
		break;
	case 1:
		//TextColor(240);
		winEffect();
		gotoxy(0, 10);
		O_WIN_animate();
		sleep(3000);
		break;
	case 0:
		gotoxy(0, 10);
		if (m % 2 == 0)PlaySound(TEXT("joustus_mysterycard_new.wav"), NULL, SND_ASYNC);
		DRAW_animate();
		sleep(2000);
		break;
	case 2:
		_TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
	}
	GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
void ResetData()
{
	for (int i = 0; i < _BOARD_SIZE; i++) {
		for (int j = 0; j < _BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + _LEFT + 2;
			_A[i][j].y = 2 * i + _TOP + 1; //Có thay đổi
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
	_X = _A[0][0].x; _Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu

}
void SETTINGS(int& m, int& s) {
	Settings set;
	int x_SET;
	bool BACK_SET = false;
	int line_SET = 14;
	set.printMenu();
	if (m % 2 == 0) {
		gotoxy(88, 14);
		cout << "ON ";
	}
	else { gotoxy(88, 14); cout << "OFF"; }
	if (s % 2 == 0) {
		gotoxy(88, 19);
		cout << "ON ";
	}
	else { gotoxy(88, 19); cout << "OFF"; }
	gotoxy(76, 14);
	SetConsoleTextAttribute(hConsoleColor, 240);
	cout << ">";
	while (!BACK_SET) {
		if (_kbhit) {
			x_SET = move();
			gotoxy(76, line_SET);
			SetConsoleTextAttribute(hConsoleColor, 255);
			cout << " "; //Xóa con trỏ ở vị trí cũ
			SetConsoleTextAttribute(hConsoleColor, 240);
			switch (x_SET) {
			case 1:if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			case 3:
			{
				if (s % 2 == 0)
					PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
				line_SET += 5;
				if (line_SET >= set.numberOfItem() + 14 + 5 + 5) line_SET = 14;
				break;
			}
			case 2:if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			case 4:
			{
				if (s % 2 == 0)
					PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
				line_SET -= 5;
				if (line_SET < 14) line_SET = set.numberOfItem() - 1 + 14 + 5 + 3;
				break;
			}
			case 5:
			{
				if (s % 2 == 0)
					PlaySound(TEXT("enter.wav"), NULL, SND_ASYNC);
				if (line_SET == 14) {
					m++;
					if (m % 2 == 0) {
						gotoxy(88, 14);
						cout << "ON ";
					}
					else { gotoxy(88, 14); cout << "OFF"; }
				}
				if (line_SET == 19) {
					s++;
					if (s % 2 == 0) {
						gotoxy(88, 19);
						cout << "ON ";
					}
					else { gotoxy(88, 19); cout << "OFF"; }
				}
				if (line_SET == 14 + 5 + 5) BACK_SET = true;
				break;
			}
			}
			gotoxy(76, line_SET);
			SetConsoleTextAttribute(hConsoleColor, 240);
			cout << ">";

		}
	}
}
void StartGame() {
	system("cls");
	ResetData(); // Khởi tạo dữ liệu gốc
	TextColor(240);
	DrawBoard(_BOARD_SIZE); // Vẽ màn hình game
	GotoXY(68, 4);
	TextColor(15);
	cout << "   P1's INFO    " << endl;
	GotoXY(93, 4);
	cout << "   P2's INFO    ";
	TextColor(240);
	drawGameTable(20, 13, 65, 5);
	drawX();
	drawGameTable(20, 13, 90, 5);
	drawO();
	drawGameTable(45, 10, 65, 19);
	drawV();
	TextColor(15);
	GotoXY(74, 20);
	cout << "  TIME:  ";
	GotoXY(89, 20); cout << "    HOW TO PLAY :    ";
	TextColor(240);
	GotoXY(93, 21); cout << "R : UNDO ";
	GotoXY(93, 22); cout << "Y : SAVE  ";
	GotoXY(93, 23); cout << "W : UP ";
	GotoXY(93, 24); cout << "A : LEFT ";
	GotoXY(93, 25); cout << "S : DOWN";
	GotoXY(93, 26); cout << "D : RIGHT";
	GotoXY(93, 27); cout << "ESC : EXIT  ";
	GotoXY(93, 28); cout << "ENTER : CHOOSE ";

	TextColor(240);
	GotoXY(_X, _Y);
	cout << "x";
	GotoXY(_X, _Y);
}
char askSave() { // Hỏi để lưu
	GotoXY(_LEFT, _TOP - 1);
	TextColor(240);
	cout << "Save this game for the next visit, press Y to save";
	waitKeyBoard();
	return getCommand();
}
void gameClock(int& temp_time_cl, int x, int y)
{
	clock_t end = clock();
	int gameTime = (end - start) / 1000;
	if ((gameTime) != temp_time_cl)
	{
		draw_number(gameTime / 600, 71, 24, 11);
		draw_number((gameTime % 600) / 60, 75, 24, 11);
		draw_number(((gameTime % 600) % 60) / 10, 81, 24, 11);
		draw_number(((gameTime % 600) % 60) % 10, 85, 24, 11);
	}
	temp_time_cl = (end - start) / 1000;

}
int move() {

	char c = _getch();

	if ((int)c == -32) c = _getch();

	switch ((int)c) {

	case 80:
		return 1; //cout << "Xuong";

	case 72:
		return 2; //cout << "Len";

	case 77:
		return 3; //cout << "Phai";       

	case 75:
		return 4; //cout << "Trai";

	case 27:
		return 8; //Nut ESC thoat

	case 13:
		return 5; //Nut Enter

	default:
		return 0; //cout << "Sai";

	}

}

void multiplay() { // đã sửa
	GotoXY(_X, _Y);
	_count = 0;
	LastMove = _A[0][0];
	bool validEnter = true;
	int temp_time_cd = 0;
	int temp_time_cl = 0;
	start = clock();
	timeCountDownX = 30;
	timeCountDownO = 30;
	bool bufTurn = _TURN;
	while (1)
	{

		timeCountDown(temp_time_cd, bufTurn, 77, 14, 104, 14);
		gameClock(temp_time_cl, 10, 10);

		switch (ProcessFinish(timeCheck(), m)) {
		case -1: case 1: case 0: {
			ExitGame(); return;
		}
		}


		if (_kbhit()) {
			waitKeyBoard();
			if (_COMMAND == 27) // Nhập phím "ESC" 
			{
				ExitGame();
				break;
			}
			if (_COMMAND == 'Y') // Nhập Y để lưu 
			{
				saveGame();
				ExitGame();
				break;
			}

			else {
				if (_COMMAND == 'A' ) MoveLeft();
				else if (_COMMAND == 'W' ) MoveUp();
				else if (_COMMAND == 'S' ) MoveDown();
				else if (_COMMAND == 'D' ) MoveRight();
				else if (_COMMAND == 'R') TakeBack();
				else if (_COMMAND == 13) {// Người dùng đánh dấu trên màn hình bàn cờ
					redToWhite();
					switch (CheckBoard(_X, _Y)) {
					case -1:
						if (s % 2 == 0) PlaySound(TEXT("menu_nameentry_pick.wav"), NULL, SND_ASYNC);
						TextColor(180);
						printf("X");
						TextColor(240);
						break;
					case 1:
						if (s % 2 == 0) PlaySound(TEXT("menu_nameentry_pick.wav"), NULL, SND_ASYNC);
						TextColor(177);
						printf("O");
						TextColor(240);
						break;
					case 0: validEnter = false; if (s % 2 == 0) { PlaySound(TEXT("map_move_invalid.wav"), NULL, SND_ASYNC); } break; // Khi đánh vào ô đã đánh rồi
					}
					// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
					if (validEnter == true) {
						TextColor(7);
						switch (ProcessFinish(TestBoard(), m)) {
						case -1: case 1: case 0: {
							ExitGame(); return;
						}
						}
					}
					validEnter = true; // Mở khóa
				}
			}
		}
	}
}

void playAfterLoad(char name[][100], int load) {
	int i;
	switch (load) {
	case 11: { i = loadGame(name[0]); break; }
	case 14: {i = loadGame(name[1]); break; }
	case 17:
	{i = loadGame(name[2]); break; }
	case 20:
	{
		i = loadGame(name[3]); break;
	}
	case 23: {i = loadGame(name[4]); break; }
	}
	if (i == 1) multiplay();
} // đã sửa
void printFileName(char s[][100]) { // mới vừa thêm
	ffile = fopen("filename.txt", "r");
	int k = 0;
	char name[100];
	char temp[100][100];
	int count = 0;
	while (!feof(ffile)) {
		fgets(name, 100, ffile);
		strcpy(temp[count], name);
		count++;

	}
	count--;
	fclose(ffile);
	int start = (count >= 5) ? (count - 5) : 0;  // xác định vị trí bắt đầu in
	int pos = 11;
	TextColor(15);
	for (int i = start; i < count; i++) {
		GotoXY(55, pos);
		strcpy(s[k], temp[i]);
		printf("%s", temp[i]);
		pos += 3;
		k++;
	}
	for (int h = 0; h < 5; h++) {
		for (int i = 0; i < 100; i++) {
			if (s[h][i] == '.') s[h][i] = '\0';
		}
		strcat(s[h], ".txt");
	}
}
void sleep(clock_t wait)
{
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}
char waitKeyBoard() { // Nhập phím 
	_COMMAND = toupper(_getwch());
	return _COMMAND;
}
void saveGame() {  // đã thêm
	char name[30];
	drawGameTable(30, 6, 45, 14);
	GotoXY(46, 15);
	TextColor(255);
	cout << "                              ";
	GotoXY(46, 16);
	cout << "                              ";
	GotoXY(46, 17);
	TextColor(255);
	cout << "                              ";
	GotoXY(46, 18);
	TextColor(255);
	cout << "                              ";
	GotoXY(46, 19);
	TextColor(255);
	cout << "                              ";
	TextColor(240);
	GotoXY(51, 17);
	printf("Your name: ");
	gets_s(name);
	char fileName[40] = ".txt";
	strcat(name, fileName);
	saveNameOfFile(name); // thêm ở đây
	FILE* f = fopen(name, "w");
	fprintf(f, "%d\n", _TURN);
	for (int i = 0; i < _BOARD_SIZE; i++) {
		for (int j = 0; j < _BOARD_SIZE; j++)
		{
			fprintf(f, "%d", _A[i][j].c);
			fprintf(f, "\n");
		}
	}
	fclose(f);

}
void saveNameOfFile(char name[]) { // mới vừa thêm
	ffile = fopen("filename.txt", "a");
	if (ffile == NULL) {
		return;
	}
	fprintf(ffile, "%s\n", name);
	fclose(ffile);
}
int AskContinue() {
	GotoXY(0, _A[_BOARD_SIZE - 1][_BOARD_SIZE - 1].y + 4);
	printf("Nhan 'y/n' de tiep tuc/dung: ");
	return toupper(_getch());
}

void singleplay_PVC(int s, int m)
{
	TextColor(15);
	GotoXY(74, 20);
	cout << "  TIME:  ";
	GotoXY(89, 20); cout << "    HOW TO PLAY :    ";
	TextColor(240);
	GotoXY(93, 21); cout << "W : UP        ";
	GotoXY(93, 22); cout << "A : LEFT      ";
	GotoXY(93, 23); cout << "S : DOWN";
	GotoXY(93, 24); cout << "D : RIGHT";
	GotoXY(93, 25); cout << "ESC : EXIT  ";
	GotoXY(93, 26); cout << "ENTER : CHOOSE ";
	GotoXY(93, 27); cout << "              ";
	GotoXY(93, 28); cout << "              ";


	GotoXY(_X, _Y);
	_count = 0;
	LastMove = _A[0][0];
	bool validEnter = true;
	int temp_time_cd = 0;
	int temp_time_cl = 0;
	timeCountDownX = 30;
	timeCountDownO = 30;
	start = clock();
	int temp_time = 0;
	bool isPlayerTurn = true;
	bool bufTurn = isPlayerTurn;
	while (1)
	{

		timeCountDown(temp_time_cd, bufTurn, 77, 14, 104, 14);
		gameClock(temp_time_cl, 10, 10);

		switch (ProcessFinish(timeCheck(), m)) {
		case -1: case 1: case 0: {
			ExitGame(); return;
		}
		}


		if (isPlayerTurn)
		{
			if (_kbhit())
			{
				waitKeyBoard();
				if (_COMMAND == 27) // Nhập phím "ESC"
				{
					ExitGame();
					break;
				}
				
				if (_COMMAND == 'A' ) MoveLeft();
				else if (_COMMAND == 'W' ) MoveUp();
				else if (_COMMAND == 'S' ) MoveDown();
				else if (_COMMAND == 'D' ) MoveRight();
				//else if (_COMMAND == 'R') TakeBack();
				else if (_COMMAND == 13)
				{
					// Người chơi đánh dấu trên màn hình bàn cờ
					redToWhite();
					switch (CheckBoard(_X, _Y))
					{
					case 1: if (s % 2 == 0)
						PlaySound(TEXT("menu_nameentry_pick.wav"), NULL, SND_ASYNC);
					case -1:
						if (s % 2 == 0)
							PlaySound(TEXT("menu_nameentry_pick.wav"), NULL, SND_ASYNC);
						//TextColor(180);
						TextColor(244);
						printf("X");
						TextColor(240);
						break;
					case 0: validEnter = false; if (s % 2 == 0) PlaySound(TEXT("map_move_invalid.wav"), NULL, SND_ASYNC); break; // Khi đánh vào ô đã đánh rồi
					}

					// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
					if (validEnter == true)
					{
						TextColor(7);
						switch (ProcessFinish(TestBoard(), m))
						{
						case -1:case 1: case 0:
						{
							ExitGame();
							return;
						}
						}
						isPlayerTurn = false; // Sau khi người chơi đánh, đến lượt máy
					}
					validEnter = true; // Mở khóa
				}
			}
		}
		else {
			// Lượt của máy
			_POINT p = PVC_hard(); // Tìm nước đi tốt nhất
			LastMove = p;
			LastMove.c = 1;
			redToWhite();
			_A[p.x][p.y].c = 1; // Đánh dấu nước đi của máy trên bàn cờ

			// tính toán vị trí của O
			int row_O = p.x;
			int col_O = p.y;

			_X = col_O * 4 + 2 + _LEFT;
			_Y = row_O * 2 + 1 + _TOP;

			GotoXY(_X, _Y);
			TextColor(177);
			printf("O");
			TextColor(240);
			

			// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
			switch (ProcessFinish(TestBoard(), m))
			{
			case -1: case 1: case 0: {
				ExitGame(); return;
			}

			}
			isPlayerTurn = true;
			validEnter = true;
		}
	}

}
