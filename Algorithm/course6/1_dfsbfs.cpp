//time   : 0h 42m

/*review : 1. improve print \n part, exercise code more faster
           2. bfs remember 3 status
		      1) discover-x
			  2) discover-o  visit-x
			  3) discover-o  visit-o
*/

#include <stdio.h>
#include <queue>
using namespace std;

#define MAX 1000

int N, E;
int cnt = 0;
bool bVisited[MAX];
bool bConnected[MAX][MAX];
bool bDiscovered[MAX];

void dfs(int n) {
	cnt++;
	printf("%d", n);
	//print part
	if (cnt == N) printf("\n");
	else printf(" ");
	//

	bVisited[n] = true;
	for (int i = 0; i < N; i++)
		if (bConnected[n][i] && !bVisited[i])
			dfs(i);
	return;
}

void bfs(int n) {
	queue<int> qNotVisitedYet;
	bDiscovered[n] = true;
	qNotVisitedYet.push(n);
	while (!qNotVisitedYet.empty()) {
		int v = qNotVisitedYet.front();
		//print part
		cnt++;
		printf("%d", v);
		if (cnt == N) printf("\n");
		else printf(" ");
		//
		qNotVisitedYet.pop();
		for (int i = 0; i < N; i++) {
			if (i == v) continue;
			if (bConnected[v][i] && !bDiscovered[i]) {
				qNotVisitedYet.push(i);
				bDiscovered[i] = true;
			}
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
	cnt = 0;
	bfs(0);

	return 0;
}