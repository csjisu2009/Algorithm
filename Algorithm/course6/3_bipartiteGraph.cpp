//time   : 0h 15m

/*review : 1. bipartite graph == two color paint
           2. dfs version
           3. reference : https://ko.wikipedia.org/wiki/%EC%9D%B4%EB%B6%84_%EA%B7%B8%EB%9E%98%ED%94%84
*/

#include <stdio.h>

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
			printf("No\n");
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
	int uTemp, vTemp;
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &uTemp, &vTemp);
		u = uTemp - 1;
		v = vTemp - 1;
		bConnected[u][v] = true;
		bConnected[v][u] = true;
	}

	dfsPaintColor(0);
	if (!bPaintWrong)
		printf("Yes\n");

	return 0;
}