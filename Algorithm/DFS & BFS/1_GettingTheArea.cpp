#include <stdio.h>
#include <queue>
using namespace std;

#define MAX 100

int Y, X, K;
//int board[MAX][MAX]; //you do not have to use board[][]!! because you already have bDiscovered[][]!!
class Point {
public:
	int y;
	int x;

	Point() {}
	Point(int y, int x) {
		this->y = y;
		this->x = x;
	}
};
bool bDiscovered[MAX][MAX];
int sArray[MAX];
int sIndex = 0;
int s = 0;
void bfs(Point p) {
	bDiscovered[p.y][p.x] = true;
	s++;
	queue<Point> qNotVistedYet;
	qNotVistedYet.push(p);
	Point vp;
	while (!qNotVistedYet.empty()) {
		vp = qNotVistedYet.front();
		qNotVistedYet.pop();

		//check Up-Coordinate
		if (vp.y + 1 < Y && !bDiscovered[vp.y + 1][vp.x]) {
			bDiscovered[vp.y + 1][vp.x] = true;
			qNotVistedYet.push(Point(vp.y+1, vp.x));
			s++;
		}
		//check Right-Coordinate
		if (vp.x + 1 < X && !bDiscovered[vp.y][vp.x+1]) {
			bDiscovered[vp.y][vp.x+1] = true;
			qNotVistedYet.push(Point(vp.y, vp.x+1));
			s++;
		}
		//check Down-Coordinate
		if (0 < vp.y-1 && !bDiscovered[vp.y-1][vp.x]) {
			bDiscovered[vp.y-1][vp.x] = true;
			qNotVistedYet.push(Point(vp.y-1, vp.x));
			s++;
		}
		//check Left-Coordinate
		if (0 < vp.x-1 && !bDiscovered[vp.y][vp.x-1]) {
			bDiscovered[vp.y][vp.x-1] = true;
			qNotVistedYet.push(Point(vp.y, vp.x-1));
			s++;
		}
	}
	sArray[sIndex] = s;
	s = 0;
	sIndex++;
	return;
}

//quick sort
	//source code
int partition(int* A, int start, int end) {
	int pivot = A[end];
	int pIndex = start;

	for (int i = start; i < end; ++i)
		if (A[i] <= pivot) {
			swap(A[i], A[pIndex]);
			++pIndex;
		}
	swap(A[pIndex], A[end]);
	return pIndex;
}

void quickSort(int* A, int start, int end) {
	if (start < end) {
		int pIndex = partition(A, start, end);
		quickSort(A, start, pIndex - 1);
		quickSort(A, pIndex + 1, end);
	}
}

int main() {
	scanf("%d %d %d", &Y, &X, &K);
	//initialize board[][] as 1
	for(int j = 0 ; j < Y ; j++)
		for (int i = 0; i < X; i++)
			bDiscovered[j][i] = false;
	//declare square's leftDown coordinates and rightUp coordinates
	int yDown, xDown, yUp, xUp;
	//fill the board's square area with 0
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &xDown, &yDown, &xUp, &yUp);
		if (xDown == xUp && yDown == yUp)//do not forget the 'square's s == 1' situation!!
			bDiscovered[yUp][xUp] = true;
		else {
			for (int y = yDown; y < yUp; y++)
				for (int x = xDown; x < xUp; x++)
					bDiscovered[y][x] = true;
		}
	}

	for(int j = 0 ; j < Y ; j++)
		for (int i = 0; i < X; i++) {
			if (!bDiscovered[j][i])
				bfs(Point(j, i));
		}

	printf("%d\n", sIndex);
	quickSort(sArray, 0, sIndex-1);//becareful!! [start, end], not [start, end)
	for (int i = 0; i < sIndex; i++) {
		printf("%d", sArray[i]);
		if (i == sIndex - 1) printf("\n");
		else printf(" ");
	}
	return 0;
}