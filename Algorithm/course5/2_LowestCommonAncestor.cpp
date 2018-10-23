//time   : 1h 0m

/*review : 1. this is just a Naive Algorithm!! there are plenty of method to solve this problem
              //https://www.hackerrank.com/topics/lowest-common-ancestor
*/
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

    //get parents of 'v' vertex, if find lca break!!
    bool bLCA = false;
    int vAncestors[MAX];//include node self!! uAncestors[0] = node self
    vAncestors[0] = v;
    nodeC = v;

    while(true){
        for(int i = 0 ; i < uAncestorsSize ; i++){

            if(nodeC == uAncestors[i]){
                printf("%d\n", nodeC);
                bLCA = true;
            }
            if(bLCA) break;
        }
        nodeC = parent[nodeC];
        if(bLCA) break;
    }
    return 0;
}