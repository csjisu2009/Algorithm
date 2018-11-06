
/*remember : when you wannna solve shortest path problem, bfs is proper
             you must think clearly when use dfs and when use bfs
             you know when dfs and bfs are same same?? -- when you wanna check all the situation!! they are same same!!
*/

//time   : 2h 0m

/*review : 1. dfs shortest path!!
           2. reference: 
              Maze solving algorithm - https://en.wikipedia.org/wiki/Maze_solving_algorithm
              A* search algorithm - https://en.wikipedia.org/wiki/A*_search_algorithm
*/

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
bool bDiscovered[MAX][MAX];// 1) discover-x
Point prePoint[MAX][MAX];// use this when you count shortest path length

void bfs(int y, int x) {
	bDiscovered[y][x] = true;// 2) discover-o
	queue<Point> qNotVisitedYet;
	Point pNVY(y, x);
	qNotVisitedYet.push(pNVY);// 2) visit-x
	while (!qNotVisitedYet.empty()) {
		Point vp = qNotVisitedYet.front();// 3) visit-o
		y = vp.y;
		x = vp.x;
		//printf("Point( %d , %d )\n", vp.y, vp.x);
		//printf("queue size : %d\n", qNotVisitedYet.size());
		qNotVisitedYet.pop();
		
		//UP : Point(y-1, x)
		if ( ( 0 <= y-1 && y-1 < Y) && !bDiscovered[y-1][x] && board[y-1][x] == 0) {
			Point pNVY(y-1, x);
			qNotVisitedYet.push(pNVY);
			bDiscovered[y-1][x] = true;
			prePoint[y - 1][x] = Point(y, x);
		}
		//RIGHT : Point(y, x+1)
		if ((0 <= x+1 && x+1 < X) && !bDiscovered[y][x+1] && board[y][x+1] == 0) {
			Point pNVY(y, x+1);
			qNotVisitedYet.push(pNVY);
			bDiscovered[y][x+1] = true;
			prePoint[y][x+1] = Point(y, x);
		}
		//DOWN : Point(y+1, x)
		if ((0 <= y+1 && y+1 < Y) && !bDiscovered[y+1][x] && board[y+1][x] == 0) {
			Point pNVY(y+1, x);
			qNotVisitedYet.push(pNVY);
			bDiscovered[y+1][x] = true;
			prePoint[y+1][x] = Point(y, x);
		}
		//LEFT : Point(y, x-1)
		if ((0 <= x-1 && x-1 < X) && !bDiscovered[y][x-1] && board[y][x-1] == 0) {
			Point pNVY(y, x-1);
			qNotVisitedYet.push(pNVY);
			bDiscovered[y][x-1] = true;
			prePoint[y][x-1] = Point(y, x);
		}
	}
	return;
}

int main() {
	scanf("%d %d", &Y, &X);
	for (int j = 0; j < Y; j++)
		for (int i = 0; i < X; i++)
			scanf("%d", &board[j][i]);

	for(int j = 0 ; j < Y ; j++)
		for (int i = 0; i < X; i++) {
			bDiscovered[j][i] = false;
			bVisited[j][i] = false;
		}

	bfs(Y-1, 0);

	//count shortest path length
	int cnt = 0;
	int tempY = 0, tempX = X-1;
	int j, i;
	while (true) {
		cnt++;
		if (prePoint[tempY][tempX].y == Y - 1
			&& prePoint[tempY][tempX].x == 0)
			break;
		j = prePoint[tempY][tempX].y;
		i = prePoint[tempY][tempX].x;;
		tempY = j;
		tempX = i;
	}
	printf("%d\n", cnt);
	
	return 0;
}
