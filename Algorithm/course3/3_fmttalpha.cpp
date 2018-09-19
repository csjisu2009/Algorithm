//time   : 

//review : can't solve if you just use for-loop, you should use recursion

#include <stdio.h>

int main(){
    int count = 0;
    int xStart, yEnd;
    scanf("%d %d", &xStart, &yEnd);

    int dist = yEnd - xStart;
    int distToGo = dist;
    if(0 <= dist && dist <= 3)
        printf("%d", dist);

    for(int i = 1 ; i < dist/2 ; i++){
        distToGo = distToGo - i;
        count++;
        if(distToGo == dist/2 -1){
            count = count*2 -1;
            break;
        }
        if(distToGo == dist/2){
            count = count*2;
            break;
        }
        if(distToGo == dist/2+1){
            count = count*2 + 1;
            break;
        }
    }
    printf("%d", count);
    return 0;
}

/*
#include <stdio.h>

int main(){
    int xStart, yEnd;
    scanf("%d %d", &xStart, &yEnd);

    // printf("xStart : %d  yEnd : %d\n", xStart, yEnd);
    int firstDistance = yEnd - xStart - 1; 
    int leftDistance = firstDistance;
    int move;

    for(int i = 1 ; i <= firstDistance ; i++){
        // printf("leftDistance : %d\n", leftDistance);
        // printf("i : %d\n", i);
        if(leftDistance == 0){
            
            move = i;
            // printf("move : %d\n", move);
            break;
        }
        
        for(int w = i ; i-2 <= w ; w--){
            // printf("w : %d\n", w);
            if(0 <= leftDistance-w){
                leftDistance = leftDistance - w;
                // printf("leftDistance : %d\n", leftDistance);
                // printf("break\n");
                break;
            }
        }
    }

    printf("%d\n", move);

    return 0;
}
*/