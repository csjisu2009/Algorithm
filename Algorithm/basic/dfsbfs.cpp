/*review : 1. bfs remember 3 status
		      1) discover-x
			  2) discover-o  visit-x
			  3) discover-o  visit-o
*/

#include <stdio.h>
#include <queue>
using namespace std;

#define MAX 1000

class Point{
public: 
	int y;
	int x;
};

int N, E;
bool bVisited[MAX];
bool bConnected[MAX][MAX];
bool bDiscovered[MAX];// 1) discover-x

void dfs(int n) {
	printf("%d", n);
	bVisited[n] = true;
	for (int i = 0; i < N; i++)
		if (bConnected[n][i] && !bVisited[i])
			dfs(i);
	return;
}

void bfs(int n) {
	bDiscovered[n] = true;// 2) discover-o
	queue<int> qNotVisitedYet;
	qNotVisitedYet.push(n);// 2) visit-x
	while (!qNotVisitedYet.empty()) {
		int v = qNotVisitedYet.front();// 3) visit-o
		printf("%d", v);
		qNotVisitedYet.pop();
		for (int i = 0; i < N; i++)
			if (bConnected[v][i] && !bDiscovered[i]) {
				qNotVisitedYet.push(i);
				bDiscovered[i] = true;
			}
	}
	return;
}

int main() {
	scanf("%d %d", &N, &E);
	for (int i = 0; i < N; i++)
		bVisited[i] = false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			bConnected[i][j] = false;
			bConnected[j][i] = false;
		}

	int u, v;
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &u, &v);
		bConnected[u][v] = true;
		bConnected[v][u] = true;
	}

	dfs(0);

	bfs(0);

	return 0;
}