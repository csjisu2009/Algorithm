#include <stdio.h>
#include <queue>
#include <iostream>
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