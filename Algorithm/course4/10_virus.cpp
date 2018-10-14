//time   : 0 h 26m

/*review : implement dfs by using recursion!!
*/
#include <stdio.h>

int N;//node count
int M;//edge count
bool  bVisited[101];
bool bConnected[101][101];
int count = 0;

void dfs(int n){
    bVisited[n] = true;
    for(int i = 1 ; i <= N ; i++){
        if(i == n) continue;
        if(bConnected[n][i] && !bVisited[i]){
            count++;
            dfs(i);
        }
    }
    return;
}

int main(){
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i = 1 ; i <= N ; i++)
        bVisited[i] = false;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++)
            bConnected[i][j] = false;
    }
    int v1, v2;
    for(int i = 1 ; i <= M ; i++){
        scanf("%d %d", &v1, &v2);
        bConnected[v1][v2] = true;
        bConnected[v2][v1] = true;
    }

    dfs(1);
    printf("%d\n", count);
    return 0;
}