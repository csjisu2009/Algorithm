#include <stdio.h>

#define MAX 500000
int N;
int hTower[MAX];
int rReTower[MAX];//radar received tower

int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &hTower[i]);

    rReTower[0] = 0;
    for(int i = N-1 ; 1 <= i ; i--){
        for(int j = i-1 ; 0 <= j ; j--){
            if(hTower[j] >= hTower[i]){
                rReTower[i] = j + 1;
                break;
            }
            if(j == 0)//if can not find radar received tower
                rReTower[i] = 0;
        }
    }

    for(int i = 0 ; i < N ; i++){
        printf("%d", rReTower[i]);
        if(i == N-1) printf("\n");
        else printf(" ");
    }

    return 0;
}