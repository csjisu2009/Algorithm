#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000

class Point {
public:
	int y;
	int x;

	Point() {}
	Point(int _y, int _x) {
		y = _y;
		x = _x;
	}
};

int Y, X;
int board[MAX][MAX];
queue<Point> qPoints;
bool bVisited[MAX][MAX];
//bool bConnected[MAX][MAX];
bool bDiscovered[MAX][MAX];// 1) discover-x
bool bDistance[MAX][MAX][2];// [0] check have distance for bfs(Y - 1, 0) ; [1] check have distance for bfs(0, X-1) ; only check the distance of both are true!!
Point prePoint[MAX][MAX];

void bfs(int y, int x) {
	bDiscovered[y][x] = true;// 2) discover-o
	queue<Point> qNotVisitedYet;
	Point pNVY(y, x);
	qNotVisitedYet.push(pNVY);// 2) visit-x
	while (!qNotVisitedYet.empty()) {
		Point vp = qNotVisitedYet.front();// 3) visit-o
		y = vp.y;
		x = vp.x;
		printf("Point( %d , %d )\n", vp.y, vp.x);
		//printf("queue size : %d\n", qNotVisitedYet.size());
		qNotVisitedYet.pop();

		//UP : Point(y-1, x)
		if ((0 <= y - 1 && y - 1 < Y) && !bDiscovered[y - 1][x] && board[y - 1][x] == 0) {
			Point pNVY(y - 1, x);
			qNotVisitedYet.push(pNVY);
			bDiscovered[y - 1][x] = true;
			prePoint[y - 1][x] = Point(y, x);
		}
		//RIGHT : Point(y, x+1)
		if ((0 <= x + 1 && x + 1 < X) && !bDiscovered[y][x + 1] && board[y][x + 1] == 0) {
			Point pNVY(y, x + 1);
			qNotVisitedYet.push(pNVY);
			bDiscovered[y][x + 1] = true;
			prePoint[y][x + 1] = Point(y, x);
		}
		//DOWN : Point(y+1, x)
		if ((0 <= y + 1 && y + 1 < Y) && !bDiscovered[y + 1][x] && board[y + 1][x] == 0) {
			Point pNVY(y + 1, x);
			qNotVisitedYet.push(pNVY);
			bDiscovered[y + 1][x] = true;
			prePoint[y + 1][x] = Point(y, x);
		}
		//LEFT : Point(y, x-1)
		if ((0 <= x - 1 && x - 1 < X) && !bDiscovered[y][x - 1] && board[y][x - 1] == 0) {
			Point pNVY(y, x - 1);
			qNotVisitedYet.push(pNVY);
			bDiscovered[y][x - 1] = true;
			prePoint[y][x - 1] = Point(y, x);
		}

		/*these store wall co-ordinates*/
		//UP : Point(y-1, x)
		if (board[y][x] == 0) {
			if ((0 <= y - 1 && y - 1 < Y) && !bDiscovered[y - 1][x] && board[y - 1][x] != 0) {
				Point pNVY(y - 1, x);
				bDiscovered[y - 1][x] = true;
				prePoint[y - 1][x] = Point(y, x);
			}
			//RIGHT : Point(y, x+1)
			if ((0 <= x + 1 && x + 1 < X) && !bDiscovered[y][x + 1] && board[y][x + 1] != 0) {
				Point pNVY(y, x + 1);
				bDiscovered[y][x + 1] = true;
				prePoint[y][x + 1] = Point(y, x);
			}
			//DOWN : Point(y+1, x)
			if ((0 <= y + 1 && y + 1 < Y) && !bDiscovered[y + 1][x] && board[y + 1][x] != 0) {
				Point pNVY(y + 1, x);
				bDiscovered[y + 1][x] = true;
				prePoint[y + 1][x] = Point(y, x);
			}
			//LEFT : Point(y, x-1)
			if ((0 <= x - 1 && x - 1 < X) && !bDiscovered[y][x - 1] && board[y][x - 1] != 0) {
				Point pNVY(y, x - 1);
				bDiscovered[y][x - 1] = true;
				prePoint[y][x - 1] = Point(y, x);
			}
		}
	}
	return;
}

int countPathLen(int startY, int startX, int endY, int endX) {
	int cnt = 0;
	int tempY = endY, tempX = endX;
	int j, i;

	printf("pre-orders : ");
	while (true) {
		cnt++;
		if (prePoint[tempY][tempX].y == startY
			&& prePoint[tempY][tempX].x == startX)
			break;
		j = prePoint[tempY][tempX].y;
		i = prePoint[tempY][tempX].x;
		printf("(%d,%d) -> ", j, i);
		tempY = j;
		tempX = i;
	}
	printf("\n");
	return cnt;
}

int main() {
	scanf("%d %d", &Y, &X);
	for (int j = 0; j < Y; j++)
		for (int i = 0; i < X; i++)
			scanf("%d", &board[j][i]);

	for (int j = 0; j < Y; j++)
		for (int i = 0; i < X; i++) {
			bDiscovered[j][i] = false;
			bVisited[j][i] = false;
		}

	for (int j = 0; j < Y; j++)
		for (int i = 0; i < X; i++)
			for (int k = 0; k < 2; k++) {
				bDistance[j][i][k] = false;
			}

	//convert maze to graph
	bfs(Y - 1, 0);

	//count shortest path length
	//int cnt = countPathLen(Y - 1, 0, 0, X - 1);
	//printf("%d\n", cnt);
	
	//start co-ordinate(Y-1, 0) to Wall distance
	int cnt;
	for (int j = 0; j < Y; j++) {
		for (int i = 0; i < X; i++) {
			if (board[j][i] != 0 && bDiscovered[j][i]) {
				cnt = 0;
				cnt = countPathLen(Y-1, 0, j, i);
				printf("distance between (%d,%d) and (%d,%d) is %d\n", Y - 1, 0, j, i, cnt);
				board[j][i] += (cnt-1);
				bDistance[j][i][0] = true;
			}
		}
	}



	//test start
	for (int j = 0; j < Y; j++)
		for (int i = 0; i < X; i++) {
			printf("%d", board[j][i]);
			if (i == X - 1) printf("\n");
			else printf(" ");
		}
	//test end



	//end co-ordinate(0, X-1) to Wall distance
	for (int j = 0; j < Y; j++)
		for (int i = 0; i < X; i++) {
			bDiscovered[j][i] = false;
			bVisited[j][i] = false;
		}
	//convert maze to graph
	bfs(0, X-1);
	//start co-ordinate(Y-1, 0) to Wall distance
	for (int j = 0; j < Y; j++) {
		for (int i = 0; i < X; i++) {
			if (board[j][i] != 0 && bDiscovered[j][i]) {// && bDiscovered[j][i]
				cnt = 0;
				cnt = countPathLen(0, X-1, j, i);
				board[j][i] += cnt;
				bDistance[j][i][1] = true;
			}
		}
	}
	printf("\n");
	//test start
	for (int j = 0; j < Y; j++)
		for (int i = 0; i < X; i++) {
			printf("%d", board[j][i]);
			if (i == X - 1) printf("\n");
			else printf(" ");
		}
	//test end
	
	int minDistance = 987654321;
	for (int j = 0; j < Y; j++)
		for (int i = 0; i < X; i++) {
			if (bDistance[j][i][0] && bDistance[j][i][1] && (board[j][i] < minDistance))
				minDistance = board[j][i];
		}
	printf("minDistance : %d\n", minDistance);
	//bDistance[j][i][0] = true;
	return 0;
}