#include <iostream>
using namespace std;

int main() {
	int board[20][20];
	int ySize, xSize;//board size
	int xPosition = 0, countErasedRow = 0;
	int countFilledRow;
	cin >> xSize >> ySize;
	for(int j = 0 ; j < ySize ; ++j)
		for (int i = 0; i < xSize; ++i) {
			cin >> board[j][i];
		}

	for (int i = 0; i < xSize; ++i) {
		for (int j = 0; j < ySize; ++j) {
			//check column

			//case 1: 
			//0  four    j-4, i
			//0  three   j-3, i
			//0  two     j-2, i
			//0  one     j-1, i
			//1  bottom  j, i

			//case 2: all col is '0'
			//0  four            j-4, i
			//0  three           j-3, i
			//0  two             j-2, i
			//0  one (bottom)    j-1, i
			if (0 <= j - 4
				&& ( board[j][i] == 1 || (board[j][i] == 0 && j == ySize-1))//don't forget the case that all col is '0' 
				&& board[j - 1][i] == 0
				&& board[j - 2][i] == 0
				&& board[j - 3][i] == 0
				&& board[j - 4][i] == 0) {

				for (int row = j - 4; row <= j; ++row) {// j): the bottom is '1'  ;  j]: all col is '0'
					countFilledRow = 0;
					for (int col = 0; col < xSize; ++col) {
						if (col == i) continue;
						if (board[row][col] == 1) countFilledRow++;
					}
					if (countFilledRow == xSize - 1) countErasedRow++;
				}

				//if can erase row (there is not max situation)
				if (countErasedRow > 0) {
					xPosition = i;
					cout << xPosition + 1 << " " << countErasedRow << endl;//maxEraseColX is in [0, xSize), so should +1 when you print output in the end
					return 0;
				}
			}
		}
	}
	//if cannot erase any row
	cout << 0 << " " << 0 << endl;
	return 0;
}