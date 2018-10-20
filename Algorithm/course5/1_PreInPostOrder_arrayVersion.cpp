//time   : 0h 20m

/*review : use array when you solve tree problem!!
           it's easier than original tree version!!
*/

#include <stdio.h>

#define MAX 100
int tree[MAX][2];
int N;
bool bNodesPrinted[100];//check nodes are printed or not

void printNode(int node){//print node with ' ' or '\n'
    printf("%d", node);
    bNodesPrinted[node] = true;
    for(int i = 0 ; i < N ; i++){
        if(!bNodesPrinted[i]){
            printf(" ");
            break;
        }
        if(i == N-1)
            printf("\n");
    }
}

void preOrder(int node){
    if(node == -1) return;
    printNode(node);
    preOrder(tree[node][0]);
    preOrder(tree[node][1]);
}

void inOrder(int node){
    if(node == -1) return;
    inOrder(tree[node][0]);
    printNode(node);
    inOrder(tree[node][1]);
}

void postOrder(int node){
    if(node == -1) return;
    postOrder(tree[node][0]);
    postOrder(tree[node][1]);
    printNode(node);
}

void initializebNodePrinted(){
    for(int i = 0 ; i < N ; i++)
        bNodesPrinted[i] = false;
}

int main(){
    scanf("%d", &N);
    
    int rootData;//useless
    for(int i = 0 ; i < N ; i++)
        scanf("%d %d %d", &rootData, &tree[i][0], &tree[i][1]);
    initializebNodePrinted();
    preOrder(0);
    initializebNodePrinted();
    inOrder(0);
    initializebNodePrinted();
    postOrder(0);

    return 0;
}