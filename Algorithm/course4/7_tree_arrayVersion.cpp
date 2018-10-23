//time   : 0h 20m

/*review : use array when you solve tree problem!!
           it's easier than original tree version!!
*/

#include <stdio.h>

#define MAX 100
int tree[MAX][2];
int N;
bool bNodesPrinted[100];//check nodes are printed or not

void preOrder(int node){
    char ch = node;
    if(ch+65 == '.') return;
    printf("%c", node+65);
    preOrder(tree[node][0]);
    preOrder(tree[node][1]);
}

void inOrder(int node){
    char ch = node;
    if(ch+65 == '.') return;
    inOrder(tree[node][0]);
    printf("%c", node+65);
    inOrder(tree[node][1]);
}

void postOrder(int node){
    char ch = node;
    if(ch+65 == '.') return;
    postOrder(tree[node][0]);
    postOrder(tree[node][1]);
    printf("%c", node+65);
}

void initializebNodePrinted(){
    for(int i = 0 ; i < N ; i++)
        bNodesPrinted[i] = false;
}

int main(){
    scanf("%d", &N);
    
    char rootData, lcData, rcData;
    for(int i = 0 ; i < N ; i++){
        scanf(" %c %c %c", &rootData, &lcData, &rcData);
        tree[i][0] = lcData-65;
        tree[i][1] = rcData-65;
    }
    initializebNodePrinted();
    preOrder(0);printf("\n");
    initializebNodePrinted();
    inOrder(0);printf("\n");
    initializebNodePrinted();
    postOrder(0);printf("\n");

    return 0;
}