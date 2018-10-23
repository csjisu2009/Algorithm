//time   : 0h 30m

/*review : 1. lca & tree height, that's all fo tree distance
           2. this code is too dirty.. need to improve!!
           3. implement tree using array
*/

#include <stdio.h>

#define MAX 1000
int tree[MAX][MAX];
int childrenNum[MAX];
int height[MAX];
int parent[MAX];

int N, u, v;

int main(){
    scanf("%d %d %d", &N, &u, &v);
    height[0] = 0;
    for(int i = 0 ; i < N ; i++)
        childrenNum[i] = 0;
    
    int nodeP, nodeC, index = 0;
    int nodePTemp = 0;
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%d %d", &nodeP, &nodeC);
        parent[nodeC] = nodeP;
        height[nodeC] = height[nodeP]+1;
        if(nodeP != nodePTemp){
            childrenNum[nodePTemp] = index;
            index = 0;
        }
        tree[nodeP][index] = nodeC;
        index++;
        nodePTemp = nodeP;
    }
    childrenNum[nodeP] = index;//this line store last node's children num

    //--------------------------------------------------------lca--------------------------------------------------------
    //this part of code is too dirty... need to be improve!!!!
    int lca;
    
    //get parents of 'u' vertex
    int uAncestors[MAX];//include node self!! uAncestors[0] = node self
    uAncestors[0] = u;
    nodeC = u;
    int uAncestorsSize;
    index = 1;
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
                lca = nodeC;
                //printf("%d\n", nodeC);
                bLCA = true;
            }
            if(bLCA) break;
        }
        nodeC = parent[nodeC];
        if(bLCA) break;
    }
    //--------------------------------------------------------lca--------------------------------------------------------

    printf("%d\n", height[u] - height[lca] + height[v] - height[lca]);
    return 0;
}