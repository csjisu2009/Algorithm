//time   : 1h 30m

//review : standard is count!!! not a distance!!!

// count(È½¼ö)
//  1          1
//  2          1 1
//  3          1 2 1
//  4          1 2 2 1
//  5          1 2 3 2 1
//  6          1 2 3 3 2 1
//  7          1 2 3 4 3 2 1

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