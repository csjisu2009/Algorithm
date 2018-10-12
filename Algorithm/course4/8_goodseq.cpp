#include <stdio.h>

int N;
int count = 0;
int bEndFunction = false;
void mountain(int n){
    if(bEndFunction) return;
    if(count == N){
        //printf("count == N == %d\n", N);
        bEndFunction = true;
        return;
    }
    if(n == 1){
        
        //count
        
        if(count == N){
        //printf("count == N == %d\n", N);
        bEndFunction = true;
        return;
        }
        
        count++;
        printf("1");//printf("\n count: %d\n", count);
        
        return;
    }
    mountain(n-1);
    //count
    
        if(count == N){
        //printf("count == N == %d\n", N);
        bEndFunction = true;
        return;
        }
    
    count++;
    
    printf("%d", n); //printf("\n count: %d\n", count);
    mountain(n-1);
    return;
}

int main(){
    scanf("%d", &N);
    mountain(N);
    return 0;
}