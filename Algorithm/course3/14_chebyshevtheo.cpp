//time   : 0h 24m

/*review : 
*/ 
#include <stdio.h>

#define MAX 123456

bool bPrime[MAX*2 + 1];

void checkPrime(){
    bPrime[1] = false;

    for(int i = 2 ; i <= MAX*2 ; i++)
        bPrime[i] = true;
    for(int i = 2 ; i*i <= MAX*2 ; i++){
        if(bPrime[i])
            for(int j = i*i ; j <= MAX*2 ; j += i){
                bPrime[j] = false;
            }
    }
}

int main(){
    checkPrime();
    int n, count = 0;
    
    while(true){
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = n+1 ; i <= 2*n ; i++)
            if(bPrime[i])
                count++;
        printf("%d\n", count);
        count = 0;
    }

    return 0;
}