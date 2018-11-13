/*remember : when you wannna solve shortest path problem, bfs is proper
             you must think clearly when use dfs and when use bfs
             you know when dfs and bfs are same same?? -- when you wanna check all the situation!! they are same same!!
*/

//time   : 2h 0m

/*review : 1. read the text correctly!!
              "if the 99999 < result, calculator break down"
              == "ignore/continue the situation when 99999 < result"
              != "stop the situation when 99999 < result"
           2. use bfs to make graph !! (calculating results are node)
              use bDiscovered[] array to avoid same node
           3. if array size is too big and if you try that kind of situation many times
              it occurs "This app can't run on your pc" error
              //link : https://answers.microsoft.com/en-us/windows/forum/windows_10-power/this-app-cant-run-on-your-pc/d4869176-98fa-45b7-baf9-23c083335148
*/

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
        //review - 1
        /*
        if (99999 < v * 2){
            result = v;
            break;
        }
        */
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