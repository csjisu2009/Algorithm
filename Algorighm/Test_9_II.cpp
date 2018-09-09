#include <iostream>
using namespace std;

#define MAX 25

int main() {
	int n;
	cin >> n;
	int board[MAX][MAX];

	for (int j = 0; j < n; ++j)
		for (int i = 0; i < n; ++i)
			board[j][i] = -1;

	int y = 0, x = 0;
	for (int num = 1; num <= n * n ; ++num) {
		//first one
		if (y == 0 && x == 0) {
			board[y][x] = num;
			x++;
		}
		//right flow
		else if (board[y][x + 1] == -1 && x < n - 1 && board[y - 1][x] != -1) {
			board[y][x] = num;
			x++;
		}
		//down flow
		else if (board[y + 1][x] == -1 && y < n - 1) {
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
		else if (num == n * n)
			board[y][x] = num;
	}

	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i)
			cout << board[j][i] << " ";
		cout << endl;
	}
	return 0;
}