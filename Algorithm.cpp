
#include "Algorithm.h"
#include "global.h"
#include "Graphics.h"
#include "Manage.h"

int CheckBoard(int pX, int pY) {
	for (int i = 0; i < _BOARD_SIZE; i++) {
		for (int j = 0; j < _BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				_count++;
				if (_TURN == true) { _A[i][j].c = -1; LastMove = _A[i][j]; } // Nếu lượt hiện hành là true thì c = -1
				else { _A[i][j].c = 1; LastMove = _A[i][j]; } // Nếu lượt hiện hành là false thì c = 1
				return _A[i][j].c;
			}
		}
	}
	return 0;
}
int DemSoXungQuanh()
{
	int i = 1;
	int a = 1, b = 1, c = 1, d = 1;
	int dong = (_Y - 1 - _TOP) / 2, cot = (_X - 2 - _LEFT) / 4;

	while (_A[dong][cot].c == _A[dong + i][cot].c)
	{
		if (_A[dong + i][cot].c == 0 || dong + cot >= _BOARD_SIZE) break;
		a++; i++;
	} i = 1;
	while (_A[dong][cot].c == _A[dong - i][cot].c)
	{
		if (_A[dong - i][cot].c == 0 || dong - i < 0) break;
		a++; i++;
	}i = 1;

	while (_A[dong][cot].c == _A[dong][cot + i].c)
	{
		if (_A[dong][cot + i].c == 0 || cot + i >= _BOARD_SIZE) break;
		b++; i++;
	}i = 1;
	while (_A[dong][cot].c == _A[dong][cot - i].c)
	{
		if (_A[dong][cot - i].c == 0 || cot - i < 0) break;
		b++; i++;
	}i = 1;

	while (_A[dong][cot].c == _A[dong + i][cot + i].c)
	{
		if (_A[dong + i][cot + i].c == 0 || cot + i >= _BOARD_SIZE || dong + i >= _BOARD_SIZE) break;
		c++; i++;
	}i = 1;
	while (_A[dong][cot].c == _A[dong - i][cot - i].c)
	{
		if (_A[dong - i][cot - i].c == 0 || cot - i < 0 || dong - i < 0) break;
		c++; i++;
	}i = 1;

	while (_A[dong][cot].c == _A[dong + i][cot - i].c)
	{
		if (_A[dong + i][cot - i].c == 0 || cot - i < 0 || dong + i >= _BOARD_SIZE) break;
		d++; i++;
	}i = 1;
	while (_A[dong][cot].c == _A[dong - i][cot + i].c)
	{
		if (_A[dong - i][cot + i].c == 0 || cot + i >= _BOARD_SIZE || dong - i < 0) break;
		d++; i++;
	}i = 1;

	return max(a, max(b, max(c, d)));
}
int Evaluate(int row, int col)
{
	int score = 0;
	int _size = 12;

	// Kiểm tra 3 ô liên tiếp bên phải
	if (col <= _size - 4 && _A[row][col + 1].getCheck() == 1
		&& _A[row][col + 2].getCheck() == 1 && _A[row][col + 3].getCheck() == 1)
	{
		score += 100;
	}
	// Kiểm tra 3 ô liên tiếp phía đường chéo bên phải
	if (row >= 3 && col <= _size - 4 && _A[row - 1][col + 1].getCheck() == 1
		&& _A[row - 2][col + 2].getCheck() == 1 && _A[row - 3][col + 3].getCheck() == 1)
	{
		score += 100;
	}

	// Kiểm tra 3 ô liên tiếp phía dưới bên phải
	if (row <= _size - 4 && col <= _size - 4 && _A[row + 1][col + 1].getCheck() == 1
		&& _A[row + 2][col + 2].getCheck() == 1 && _A[row + 3][col + 3].getCheck() == 1)
	{
		score += 100;
	}
	// Kiểm tra 3 ô liên tiếp bên trái
	if (col >= 3 && _A[row][col - 1].getCheck() == 1
		&& _A[row][col - 2].getCheck() == 1 && _A[row][col - 3].getCheck() == 1)
	{
		score += 100;
	}

	// Kiểm tra 3 ô liên tiếp phía đường chéo bên trái
	if (row >= 3 && col >= 3 && _A[row - 1][col - 1].getCheck() == 1
		&& _A[row - 2][col - 2].getCheck() == 1 && _A[row - 3][col - 3].getCheck() == 1)
	{
		score += 100;
	}

	// Kiểm tra 3 ô liên tiếp phía dưới bên trái
	if (row <= _size - 4 && col >= 3 && _A[row + 1][col - 1].getCheck() == 1
		&& _A[row + 2][col - 2].getCheck() == 1 && _A[row + 3][col - 3].getCheck() == 1)
	{
		score += 100;
	}


	// Kiểm tra 3 ô liên tiếp phía trên
	if (row >= 3 && _A[row - 1][col].getCheck() == 1
		&& _A[row - 2][col].getCheck() == 1 && _A[row - 3][col].getCheck() == 1)
	{
		score += 100;
	}

	// Kiểm tra 3 ô liên tiếp phía dưới
	if (row <= _size - 4 && _A[row + 1][col].getCheck() == 1
		&& _A[row + 2][col].getCheck() == 1 && _A[row + 3][col].getCheck() == 1)
	{
		score += 100;
	}

	// Kiểm tra 2 ô liên tiếp bên phải
	if (col <= _size - 3 && _A[row][col + 1].getCheck() == 1
		&& _A[row][col + 2].getCheck() == 1)
	{
		score += 10;
	}

	// Kiểm tra 2 ô liên tiếp phía đường chéo bên phải
	if (row >= 2 && col <= _size - 3 && _A[row - 1][col + 1].getCheck() == 1
		&& _A[row - 2][col + 2].getCheck() == 1)
	{
		score += 10;
	}

	// Kiểm tra 2 ô liên tiếp phía dưới bên phải
	if (row <= _size - 3 && col <= _size - 3
		&& _A[row + 1][col + 1].getCheck() == 1 && _A[row + 2][col + 2].getCheck() == 1)
	{
		score += 10;
	}

	// Kiểm tra 2 ô liên tiếp bên trái
	if (col >= 2 && _A[row][col - 1].getCheck() == 1
		&& _A[row][col - 2].getCheck() == 1)
	{
		score += 10;
	}

	// Kiểm tra 2 ô liên tiếp phía đường chéo bên trái
	if (row >= 2 && col >= 2 && _A[row - 1][col - 1].getCheck() == 1
		&& _A[row - 2][col - 2].getCheck() == 1)
	{
		score += 10;
	}

	// Kiểm tra 2 ô liên tiếp phía dưới bên trái
	if (row <= _size - 3 && col >= 2 && _A[row + 1][col - 1].getCheck() == 1
		&& _A[row + 2][col - 2].getCheck() == 1)
	{
		score += 10;
	}

	// Kiểm tra 2 ô liên tiếp phía trên
	if (row >= 2 && _A[row - 1][col].getCheck() == 1
		&& _A[row - 2][col].getCheck() == 1)
	{
		score += 10;
	}

	// Kiểm tra 2 ô liên tiếp phía dưới
	if (row <= _size - 3 && _A[row + 1][col].getCheck() == 1
		&& _A[row + 2][col].getCheck() == 1)
	{
		score += 10;
	}

	// Kiểm tra 4 ô liên tiếp bên phải
	if (col <= _size - 5 && _A[row][col + 1].getCheck() == 1
		&& _A[row][col + 2].getCheck() == 1 && _A[row][col + 3].getCheck() == 1
		&& _A[row][col + 4].getCheck() == 1)
	{
		score += 200;
	}

	// Kiểm tra 4 ô liên tiếp phía đường chéo bên phải
	if (row >= 4 && col <= _size - 5 && _A[row - 1][col + 1].getCheck() == 1
		&& _A[row - 2][col + 2].getCheck() == 1 && _A[row - 3][col + 3].getCheck() == 1
		&& _A[row - 4][col + 4].getCheck() == 1)
	{
		score += 200;
	}

	// Kiểm tra 4 ô liên tiếp phía dưới bên phải
	if (row <= _size - 5 && col <= _size - 5 && _A[row + 1][col + 1].getCheck() == 1
		&& _A[row + 2][col + 2].getCheck() == 1 && _A[row + 3][col + 3].getCheck() == 1
		&& _A[row + 4][col + 4].getCheck() == 1)
	{
		score += 200;
	}

	// Kiểm tra 4 ô liên tiếp bên trái
	if (col >= 4 && _A[row][col - 1].getCheck() == 1
		&& _A[row][col - 2].getCheck() == 1 && _A[row][col - 3].getCheck() == 1
		&& _A[row][col - 4].getCheck() == 1)
	{
		score += 200;
	}

	// Kiểm tra 4 ô liên tiếp phía đường chéo bên trái
	if (row >= 4 && col >= 4 && _A[row - 1][col - 1].getCheck() == 1
		&& _A[row - 2][col - 2].getCheck() == 1 && _A[row - 3][col - 3].getCheck() == 1
		&& _A[row - 4][col - 4].getCheck() == 1)
	{
		score += 200;
	}

	// Kiểm tra 4 ô liên tiếp phía dưới bên trái
	if (row <= _size - 5 && col >= 4 && _A[row + 1][col - 1].getCheck() == 1
		&& _A[row + 2][col - 2].getCheck() == 1 && _A[row + 3][col - 3].getCheck() == 1
		&& _A[row + 4][col - 4].getCheck() == 1)
	{
		score += 200;
	}

	// Kiểm tra 4 ô liên tiếp phía trên
	if (row >= 3 && _A[row - 1][col].getCheck() == 1
		&& _A[row - 2][col].getCheck() == 1 && _A[row - 3][col].getCheck() == 1)
	{
		score += 200;
	}

	// Kiểm tra 4 ô liên tiếp phía dưới
	if (row <= _size - 4 && _A[row + 1][col].getCheck() == 1
		&& _A[row + 2][col].getCheck() == 1 && _A[row + 3][col].getCheck() == 1)
	{
		score += 200;
	}
	return score;
}
_POINT PVC_hard() {
	int max_score = INT_MIN;

	_POINT best_move;

	// Lưu trữ các nước đi có cùng điểm số tốt nhất
	vector<_POINT> best_moves;

	for (int j = 0; j < _BOARD_SIZE; ++j) {
		for (int i = 0; i < _BOARD_SIZE; ++i) {
			if (_A[i][j].getCheck() == 0) {
				if (checkEmpty(i, j)) {
					continue;
				}
				_A[i][j].setCheck(1);
				int score = Evaluate(i,j);
				_A[i][j].setCheck(0);

				if (score > max_score) {
					// Đặt lại danh sách các nước đi tốt nhất và nâng cấp điểm số tốt nhất
					max_score = score;
					best_moves.clear();
					best_moves.push_back(_POINT(i, j));
				}
				else if (score == max_score) {
					// Thêm nước đi có điểm số bằng tốt nhất vào danh sách
					best_moves.push_back(_POINT(i, j));
				}
			}
		}
	}

	// Chọn một nước đi ngẫu nhiên từ danh sách các nước đi tốt nhất
	int index = rand() % best_moves.size();
	return best_moves[index];
}
void TakeBack()
{
	for (int i = 0; i < _BOARD_SIZE; i++)
		for (int j = 0; j < _BOARD_SIZE; j++) {
			if (_A[i][j].x == LastMove.x && _A[i][j].y == LastMove.y)
				if (_A[i][j].c != 0) {
					_A[i][j].c = 0;
					//GotoXY(_X, _Y);
					for (int a = 0; a < _BOARD_SIZE; a++)
						for (int b = 0; b < _BOARD_SIZE; b++)
							if (_A[a][b].x == _X && _A[a][b].y == _Y)
								if (_A[a][b].c == 0)
								{
									TextColor(240);
									printf(" ");
								}
								else if (_A[a][b].c == -1)
								{
									TextColor(244);
									printf("X");
									TextColor(240);
								}
								else
								{
									TextColor(241);
									printf("O");
									TextColor(240);
								}
					_TURN = !_TURN;
					_count--;
					_X = LastMove.x;
					_Y = LastMove.y;
					GotoXY(_X, _Y); printf(" "); GotoXY(_X, _Y);//Xóa dấu đã đánh 
				}
		}

}
int TestBoard()
{
	if (_count == _BOARD_SIZE * _BOARD_SIZE) return 0; // Hòa
	else {
		if (WinnerCheck())
			return (_TURN == true ? -1 : 1); // -1 nghĩa là lượt ‘true’ thắng, 1 la false thang
		else
			return 2; // 2 nghĩa là chưa ai thắng
	}
}
bool WinnerCheck()
{
	if (DemSoXungQuanh() >= 5) return true;
	else return false;
}
bool checkEmpty(int x, int y) {
	for (int i = max(x - 1, 0); i <= min(x + 1, _BOARD_SIZE - 1); ++i) {
		for (int j = max(y - 1, 0); j <= min(y + 1, _BOARD_SIZE - 1); ++j) {
			//if (i >= x - 1 && i <= x + 1 && j >= y - 1 && j <= y + 1) 
			if (i == x && j == y)
			{
				continue;
			}
			if (i >= 0 && i < _BOARD_SIZE && j >= 0 && j < _BOARD_SIZE) {
				if (_A[i][j].c != 0) {
					return false;
				}
			}
		}
	}
	return true;
}
int countCol()
{
	int i = 1;
	int a = 1;
	int dong = (_Y - 1 - _TOP) / 2, cot = (_X - 2 - _LEFT) / 4;

	while (_A[dong][cot].c == _A[dong + i][cot].c)
	{
		if (_A[dong + i][cot].c == 0) break;
		a++; i++;
	} i = 1;
	while (_A[dong][cot].c == _A[dong - i][cot].c)
	{
		if (_A[dong - i][cot].c == 0) break;
		a++; i++;
	}

	return a;

}
int countRow()
{
	int i = 1;
	int a = 1;
	int dong = (_Y - 1 - _TOP) / 2, cot = (_X - 2 - _LEFT) / 4;

	while (_A[dong][cot].c == _A[dong][cot + i].c)
	{
		if (_A[dong][cot + i].c == 0 || cot + i >= _BOARD_SIZE) break;
		a++; i++;
	}i = 1;
	while (_A[dong][cot].c == _A[dong][cot - i].c)
	{
		if (_A[dong][cot - i].c == 0 || cot - i < 0) break;
		a++; i++;
	}
	return a;
}
int countHuyen()
{
	int i = 1;
	int a = 1;
	int dong = (_Y - 1 - _TOP) / 2, cot = (_X - 2 - _LEFT) / 4;

	while (_A[dong][cot].c == _A[dong + i][cot + i].c)
	{
		if (_A[dong + i][cot + i].c == 0 || cot + i >= _BOARD_SIZE) break;
		a++; i++;
	}i = 1;
	while (_A[dong][cot].c == _A[dong - i][cot - i].c)
	{
		if (_A[dong - i][cot - i].c == 0 || cot - i < 0) break;
		a++; i++;
	}
	return a;
}
int countSac()
{
	int i = 1;
	int a = 1;
	int dong = (_Y - 1 - _TOP) / 2, cot = (_X - 2 - _LEFT) / 4;

	while (_A[dong][cot].c == _A[dong + i][cot - i].c)
	{
		if (_A[dong + i][cot - i].c == 0 || cot - i < 0) break;
		a++; i++;
	}i = 1;
	while (_A[dong][cot].c == _A[dong - i][cot + i].c)
	{
		if (_A[dong - i][cot + i].c == 0 || cot + i >= _BOARD_SIZE) break;
		a++; i++;
	}
	return a;
}
int timeCheck()
{
	if (timeCountDownX == 0) return 1;
	if (timeCountDownO == 0) return -1;
	return 3;
}

