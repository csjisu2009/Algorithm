#include <stdio.h>

int N;
int unitY, unitX, unitR;
int absoluteValue(int a, int b){
    if(a <= b)
        return b-a;
    else
        return a-b;
}

int calculateDistanceYX(int y, int x){
    int distance;
    distance = absoluteValue(y, unitY) + absoluteValue(x, unitX);
    if(distance <= unitR)
        return distance;
    else
        return 0;
}

int main(){

    scanf("%d", &N);
    scanf("%d %d %d", &unitY, &unitX, &unitR);
    unitY = unitY - 1;
    unitX = unitX - 1;

    for(int j = 0 ; j < N ; j++)
        for(int i = 0 ; i < N ; i++){
            if(j == unitY && i == unitX)
                printf("x");
            else 
                printf("%d", calculateDistanceYX(j, i));
            if(i == N-1)
                printf("\n");
            else
                printf(" ");
        }
    return 0;
}