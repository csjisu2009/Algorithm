/*remember : when you wannna solve shortest path problem, bfs is proper
             you must think clearly when use dfs and when use bfs
             you know when dfs and bfs are same same?? -- when you wanna check all the situation!! they are same same!!
*/

//time   : 3h 0m

/*review : 1. bfs
           2. binary -> hexadecimal convert
*/

#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

#define MAX 512

int N, board[MAX][MAX];

class Info {
public:
	int y;//y-coordinate
	int x;//x-coordinate
	int size;

	Info(){}
	Info(int y, int x, int size) {
		this->y = y;
		this->x = x;
		this->size = size;
	}
};

bool bDiscovered[MAX];
bool bConnected[MAX][MAX];
stack<int> binNum;
stack<char> chHex;

enum Type {AllZero, AllOne, Devidable};

int checkType(int y, int x, int len) {
	int cntZero = 0;
	int cntOne = 0;
	int checkedSize = len * len;
	for(int j = y ; j < y+len ; j++)
		for (int i = x ; i < x+len ; i++) {//bug : x < x+len  ==> C:\Users\csjis\source\repos\test\Debug\test.exe (process 13848) exited with code -1073741819. 
			if (board[j][i] == 0) cntZero++;
			if (board[j][i] == 1) cntOne++;
		}
	if (cntZero == checkedSize) return AllZero;
	else if (cntOne == checkedSize) return AllOne;
	else return Devidable;
}

void createBinaryNumBFS(Info info) {
	queue<Info> qNotVisitedYet;
	qNotVisitedYet.push(info);
	Info v;
	int type;
	while (!qNotVisitedYet.empty()) {
		v = qNotVisitedYet.front();
		qNotVisitedYet.pop();
		type = checkType(v.y, v.x, v.size);
		if (type == Devidable) {
			binNum.push(1);
			if (1 < v.size) {
				qNotVisitedYet.push(Info(v.y, v.x, v.size / 2));
				qNotVisitedYet.push(Info(v.y, v.x + v.size / 2, v.size / 2));
				qNotVisitedYet.push(Info(v.y + v.size / 2, v.x, v.size / 2));
				qNotVisitedYet.push(Info(v.y + v.size / 2, v.x + v.size / 2, v.size / 2));
			}
		}
		else {
			binNum.push(0);
			if (type == AllZero)
				binNum.push(0);
			if (type == AllOne)
				binNum.push(1);
		}
	}
}

void convertBinToHex() {
	char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int intHex;
	int num;
	while (!binNum.empty()) {
		intHex = 0;
		for (int i = 0; i < 4; i++) {
			if (binNum.empty()) {
				chHex.push(digit[intHex]);
				return;
			}
			if (i == 0) num = 1;
			else if (i == 1) num = 2;
			else if (i == 2) num = 4;
			else num = 8;
			intHex += binNum.top()*num;
			binNum.pop();
		}
		chHex.push(digit[intHex]);
	}
}

void printHex(){
    while (!chHex.empty()) {
		printf("%c", chHex.top());
		chHex.pop();
	}
	printf("\n");
}

int main() {
	scanf("%d", &N);
	for (int j = 0; j < N; j++)
		for (int i = 0; i < N; i++)
			scanf("%d", &board[j][i]);
	createBinaryNumBFS( Info(0, 0, N) );
	convertBinToHex();
    printHex();
	
	return 0;
}