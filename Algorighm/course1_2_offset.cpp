#include <iostream>
using namespace std;

int main() {
	int board[5][5];
	int countBigger[5][5];//neighbors bigger than self


	for (int j = 0; j < 5; ++j)
		for (int i = 0; i < 5; ++i)
			cin >> board[j][i];

	for (int j = 0; j < 5; ++j)
		for (int i = 0; i < 5; ++i)
			countBigger[j][i] = 0;

	for (int j = 0; j < 5; ++j)
		for (int i = 0; i < 5; ++i) {
			if (0 <= i-1 && board[j][i] < board[j][i-1]) ++countBigger[j][i];
			if (i+1 < 5 && board[j][i] < board[j][i+1]) ++countBigger[j][i];
			if (0 <= j-1 && board[j][i] < board[j-1][i]) ++countBigger[j][i];
			if (j+1 < 5 && board[j][i] < board[j+1][i]) ++countBigger[j][i];
		}

	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 5; ++i) {
			//countBigger == 2 -> '*'
			if (countBigger[j][i] == 2
				&& ((j == 0 && i == 0) || (j == 0 && i == 4) || (j == 4 && i == 0) || (j == 4 && i == 4)))
				cout << "*";
			//countBigger == 3 -> '*'
			else if (countBigger[j][i] == 3
				&& ((j == 0 && 0 < i && i < 4) || (j == 4 && 0 < i && i < 4) || (0 < j && j < 4 && i == 0) || (0 < j && j < 4 && i == 4)))
				cout << "*";
			//countBigger == 4 -> '*'
			else if (countBigger[j][i] == 4)
				cout << "*";
			else
				cout << board[j][i];

			if (i == 4) cout << endl;
			else cout << " ";
		}
	}
	return 0;
}