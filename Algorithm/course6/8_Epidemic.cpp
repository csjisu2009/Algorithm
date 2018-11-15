/*remember : when you wannna solve shortest path problem, bfs is proper
             you must think clearly when use dfs and when use bfs
             you know when dfs and bfs are same same?? -- when you wanna check all the situation!! they are same same!!
*/

//time   : 0h 20m

/*review : 1. use bfs
           2. same as course6_7_WeirdCalculator.cpp
*/

#include <stdio.h>
#include <queue>
using namespace std;

#define MAX 100000

int N, K;
bool bDiscovered[MAX+1];
bool bVisited[MAX+1];

void bfs(int n){
    bDiscovered[n] = true;
    queue<int> qNotVisitedYet;
    qNotVisitedYet.push(n);
    int v;
    while( !qNotVisitedYet.empty() ){
        v = qNotVisitedYet.front();
        qNotVisitedYet.pop();
        if( v*2 <= N && !bDiscovered[v*2]){
            bDiscovered[v*2] = true;
            qNotVisitedYet.push(v*2);
        }
        if(0 < v/3 && !bDiscovered[v/3]){
            bDiscovered[v/3] = true;
            qNotVisitedYet.push(v/3);
        }
    }
}

int countNotVisited(){
    int cnt = 0;
    for(int i = 1 ; i <= N ; i++)
        if(!bDiscovered[i])
            cnt++;
    return cnt;
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1 ; i <= N ; i++){
        bDiscovered[i] = false;
        bVisited[i] = false;
    }

    bfs(K);
    printf("%d\n", countNotVisited());
    return 0;
}