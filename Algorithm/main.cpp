//time   : 1h 30m

//review : can't solve if you just use for-loop, you should use recursion

#include <stdio.h>

int main(){
    int count= 0, flyDist = 0, dist = 0;
    int x, y;
    bool bArrived = false;
    scanf("%d %d", &x, &y);
    dist  = y - x;
    for(int i = 1; ; i++){
        for(int j = 0 ; j < 2 ; j++){
            flyDist = flyDist + i;
            count++;
            if(dist <= flyDist){
                bArrived = true;
                break;
            }
        }
        if(bArrived)
            break;
    }
    printf("%d\n", count);
    return 0;
}