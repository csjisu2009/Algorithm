//time   : 0h 30m

/*review : implement tree using array, it is not very easy in detail e)childrenNum... and also waste of memory
           next time use vector~!!
*/

#include <stdio.h>

#define MAX 100
int tree[MAX][MAX];
int childrenNum[MAX];
int height[100];

int N, r;

int main(){
    scanf("%d %d", &N, &r);
    height[0] = 0;
    for(int i = 0 ; i < N ; i++)
        childrenNum[i] = 0;
    
    int nodeP, nodeC, index = 0;
    int nodePTemp = 0;
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%d %d", &nodeP, &nodeC);
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

    int maxHeight = -1;
    for(int i = 0 ; i < N ; i++){
        if(maxHeight < height[i])
            maxHeight = height[i];
    }
    printf("%d\n", maxHeight);
    return 0;
}