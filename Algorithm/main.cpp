#include <stdio.h>
#include <queue>
using namespace std;
 
#define MAX 100000
 
int result;
bool bVisited[MAX];
bool bDiscovered[MAX];
int preNum[MAX];
 
void bfs(int n) {
    bDiscovered[n] = true;
    queue<int> qNotVisitedYet;
    qNotVisitedYet.push(n);
    while (!qNotVisitedYet.empty()) {
        int v = qNotVisitedYet.front();
        if (v == result) {//result calculation completed !!
            break;
        }
        qNotVisitedYet.pop();
        //if (99999 < v * 2){
        //    result = v;
        //    break;
        //}
        if (v * 2 < 100000 && !bDiscovered[v * 2]) {
            preNum[v * 2] = v;
            qNotVisitedYet.push(v * 2);
            bDiscovered[v * 2] = true;
        }
        if (!bDiscovered[v / 3]) {
            preNum[v / 3] = v;
            qNotVisitedYet.push(v / 3);
            bDiscovered[v / 3] = true;
        }
    }
    return;
}
 
int calculateLength(int n) {
    int cnt = 0;
    while (n != 1) {
        cnt++;
        n = preNum[n];
    }
    return cnt;
}
 
int main() {
    scanf("%d", &result);
    for (int i = 0; i < MAX; i++) {
        bVisited[i] = false;
        bDiscovered[i] = false;
        preNum[i] = -1;
    }
    bfs(1);
 
    printf("%d\n", calculateLength(result));
 
    return 0;
}



/*
#include <stdio.h>
#include <queue>
using namespace std;

#define MAX 1000000

int result;
bool bVisited[MAX];
//bool bConnected[MAX][MAX];
bool bDiscovered[MAX];// 1) discover-x
int preNum[MAX];

void bfs(int n) {
	bDiscovered[n] = true;// 2) discover-o
	queue<int> qNotVisitedYet;
	qNotVisitedYet.push(n);// 2) visit-x
	while (!qNotVisitedYet.empty()) {
		int v = qNotVisitedYet.front();// 3) visit-o
		if (v == result) {
			//printf("v : %d, result : %d\n", v, result);
			break;
		}
		//printf("%d\n", v);
		qNotVisitedYet.pop();
		//printf("%d * 2 is %d\n", v, v * 2);
		//printf(bDiscovered[v * 2] ? "true" : "false");
		//printf("\n");
		if (!bDiscovered[v * 2]) {
			//printf("%d is not discovered\n", v * 2);
			preNum[v * 2] = v;
			qNotVisitedYet.push(v * 2);
			bDiscovered[v * 2] = true;
		}
		if (!bDiscovered[v / 3]) {
			//printf("%d is not discovered\n", v / 2);
			preNum[v / 3] = v;
			qNotVisitedYet.push(v / 3);
			bDiscovered[v / 3] = true;
		}
		/*
		for (int i = 0; i < N; i++)
			if (bConnected[v][i] && !bDiscovered[i]) {
				qNotVisitedYet.push(i);
				bDiscovered[i] = true;
			}
		*/
/*
	}
	return;
}

long long int calculateLength(int n) {
	long long int cnt = 0;
	while (n != 1) {
		cnt++;
		n = preNum[n];
        printf("n : %d\n", n);
	}
	return cnt;
}

int main() {
	scanf("%d", &result);
	for (int i = 0; i < MAX; i++) {
		bVisited[i] = false;
		bDiscovered[i] = false;
		preNum[i] = -1;
	}
	bfs(1);
	
	printf("%lld\n", calculateLength(result));

	return 0;
}
*/
/*
#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

#define MAX 100000

int result;
bool bVisited[MAX];
bool bDiscovered[MAX];// 1) discover-x
int preNum[MAX];

void bfs(int n) {
	bDiscovered[n] = true;// 2) discover-o
	queue<int> qNotVisitedYet;
	qNotVisitedYet.push(n);// 2) visit-x
	while (!qNotVisitedYet.empty()) {
		int v = qNotVisitedYet.front();// 3) visit-o
		if (v == result) {
			break;
		}
		qNotVisitedYet.pop();

		if (!bDiscovered[v * 2]) {
			preNum[v * 2] = v;
			qNotVisitedYet.push(v * 2);
			bDiscovered[v * 2] = true;
		}
		if (!bDiscovered[v / 3]) {
			preNum[v / 3] = v;
			qNotVisitedYet.push(v / 3);
			bDiscovered[v / 3] = true;
		}
	}
	return;
}

int calculateLength(int n) {
	int cnt = 0;
	while (n != 1) {
		cnt++;
		n = preNum[n];
	}
	return cnt;
}

int main() {
	scanf("%d", &result);
	for (int i = 0; i < MAX; i++) {
		bVisited[i] = false;
		bDiscovered[i] = false;
		preNum[i] = -1;
	}
	bfs(1);
	printf("%d\n", calculateLength(result));
	return 0;
}
*/