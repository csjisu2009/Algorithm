//time   : 1h 0m

/*review : dfs version
*/

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

#define MAX 1000

int N, E;
bool bVisited[MAX];
bool bConnected[MAX][MAX];
bool bDiscovered[MAX];
enum Color {WHITE, BLUE, YELLOW};
Color vCol[MAX];
bool bPaintWrong = false;

bool checkTwoColor(int n) {
	for (int i = 0; i < N; i++) {
		if (bConnected[n][i] && (vCol[n] == vCol[i])){
			printf("NO\n");
			//printf("NO!! from node %d connected with %d\n", n, i);
			bPaintWrong = true;
			break;
		}
	}
	if(bPaintWrong)
		return false;
	return true;
}

void dfsPaintColor(int n) {
	if(!bPaintWrong) checkTwoColor(n);
	if (bPaintWrong) return;
	//test
	/*
	printf("%d\n", n);
	switch (vCol[n]) {
	case 0 :
		printf("WHITE\n");
		break;
	case 1:
		printf("BLUE\n");
		break;
	case 2:
		printf("YELLOW\n");
		break;
	}
	*/
	//
	bVisited[n] = true;
	for (int i = 0; i < N; i++)
		if (bConnected[n][i] && !bVisited[i]) {
			if (vCol[n] == BLUE)  vCol[i] = YELLOW;
			else if (vCol[n] == YELLOW)  vCol[i] = BLUE;
			dfsPaintColor(i);
		}
	return;
}

int main() {
	scanf("%d %d", &N, &E);
	for (int i = 0; i < N; i++) {
		bVisited[i] = false;
		if (i == 0)
			vCol[i] = BLUE;
		else
			vCol[i] = WHITE;
	}
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

	dfsPaintColor(0);
	if (!bPaintWrong)
		printf("YES\n");

	return 0;
}