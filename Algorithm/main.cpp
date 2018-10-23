#include <stdio.h>

#define MAX 1000

int N, u, v;
int parent[MAX];

int main(){
    scanf("%d %d %d", &N, &u, &v);
    int nodeP, nodeC;
    int nodePTemp = 0;
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%d %d", &nodeP, &nodeC);
        parent[nodeC] = nodeP;
    }

    //test
    //for(int i = 1 ; i < N ; i++)
    //    printf("parent[%d] : %d\n", i, parent[i]);

    //
    
    //get parents of 'u' vertex
    int uAncestors[MAX];//include node self!! uAncestors[0] = node self
    uAncestors[0] = u;
    nodeC = u;
    int uAncestorsSize;
    int index = 1;
    while(nodeC != 0){
        uAncestors[index] = parent[nodeC];
        nodeC = uAncestors[index];
        index++;
    }
    uAncestorsSize = index;
    //test
    //for(int i = 0 ; i < index ; i++)
    //    printf("uAncestors[%d] : %d\n", i, uAncestors[i]);
    //

    //get parents of 'v' vertex, if find lca break!!
    bool bLCA = false;
    int vAncestors[MAX];//include node self!! uAncestors[0] = node self
    vAncestors[0] = v;
    nodeC = v;

    //printf("uAncestorsSize : %d\n", uAncestorsSize);
    while(true){
        for(int i = 0 ; i < uAncestorsSize ; i++){

            if(nodeC == uAncestors[i]){
                printf("%d\n", nodeC);
                bLCA = true;
            }
            if(bLCA) break;
        }
        //vAncestors[index] = parent[nodeC];
        //nodeC = vAncestors[index];
        nodeC = parent[nodeC];

        if(bLCA) break;
    }
    return 0;
}

































//time   : 0h 20m

/*review : use array when you solve tree problem!!
           it's easier than original tree version!!
*/

/*#include <stdio.h>

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
*/