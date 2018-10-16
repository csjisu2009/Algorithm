//time   : 0h 0m

/*review : 1. Gen:Variant.Ursu.236333
           2. there are 3 status of vectex in bfs
              a. not discovered yet
              b. discovered but not visited yet(stored in queue)
              c. visited
*/


#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 26

int N;
int E;
bool bVisited[MAX];
bool bDiscovered[MAX];
bool bConnected[MAX][MAX];
int cnt = 0;

void dfs(int n) {
	printf("%c", n+65);
	bVisited[n] = true;
	for (int i = 0; i < N; i++) {
		if (bConnected[n][i] && !bVisited[i]) {
			cnt++;
			dfs(i);
		}
	}
	return;
}

void bfs(int n) {
	queue<int> qNotVisitedYet;
	bDiscovered[n] = true;
	qNotVisitedYet.push(n);
	while (!qNotVisitedYet.empty()) {
		int v = qNotVisitedYet.front();
		printf("%c", v+65);
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
	//initilize bVisited[], bConnected[][] as false
	for (int i = 0; i < N; i++) {
		bVisited[i] = false;
		bDiscovered[i] = false;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			bConnected[i][j] = false;
	//input bConnected[][]
	char ch1, ch2;
	for (int i = 0; i < E; i++) {
		cin >> ch1 >> ch2;
		bConnected[ch1 - 65][ch2 - 65] = true;
		bConnected[ch2 - 65][ch1 - 65] = true;
	}
	char cStart;
	cin >> cStart;
	int iStart = cStart - 65;

	dfs(iStart);
	printf("\n");
	bfs(iStart);
	printf("\n");

	return 0;
}