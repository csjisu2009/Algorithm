#include <iostream>
using namespace std;

#define MAX 100

int board[MAX][MAX];//do not define in main() function, it cause stackoverflow !!

int main() {
	int y, x;
	cin >> y >> x;
	for (int j = 0; j < y; ++j)
		for (int i = 0; i < x; ++i)
			cin >> board[j][i];

	for (int j = 0; j < y; ++j)
		for (int i = x - 1; 0 <= i; --i) {
			cout << board[j][i];
			if (i == 0)  cout << endl;
			else cout << " ";
		}

	return 0;
}