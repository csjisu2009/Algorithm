#include <iostream>
using namespace std;

#define MAX 10000

int board[MAX][MAX];//do not define in main() function, it cause stackoverflow !!

int main() {
	int ySize, xSize, numWait;//careful!! C == ySize, R == xSize
	cin >> ySize >> xSize;
	cin >> numWait;

	//seats are fully filled already
	if (xSize*ySize < numWait) {
		cout << 0 << endl;
		return 0;
	}

	for (int j = 0; j < ySize; ++j)
		for (int i = 0; i < xSize; ++i)
			board[j][i] = -1;

	int y = 0, x = 0;
	for (int num = 1; num <= xSize * ySize ; ++num) {
		//print seats
		if (numWait == num) {
			cout << y+1 << " " << x+1 << endl;
			return 0;
		}

		//first one
		if (y == 0 && x == 0) {
			board[y][x] = num;
			x++;
		}
		//right flow
		else if (board[y][x + 1] == -1 && x < xSize - 1 && board[y - 1][x] != -1) {
			board[y][x] = num;
			x++;
		}
		//down flow
		else if (board[y + 1][x] == -1 && y < ySize - 1) {
			board[y][x] = num;
			y++;
		}
		//left flow
		else if (board[y][x - 1] == -1 && x > 0) {
			board[y][x] = num;
			x--;
		}
		//up flow
		else if (board[y - 1][x] == -1 && y > 1) {
			board[y][x] = num;
			y--;
		}
		//last one
		else if (num == xSize * ySize)
			board[y][x] = num;
	}

	return 0;
}