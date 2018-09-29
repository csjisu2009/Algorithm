//time   : 4h 0m

/*review : use recursion & array together !! because you should save the pre-numbers!!
*/ 
#include <stdio.h>

int b[31];
int N, K;
int countOne;
void binaryNK(int n, int k){
    if(k < 0 || n < 0) return;

    //if countOne == K, print result
    if(n == 0 && k == 0){
        countOne = 0;
        for(int i = 1 ; i <= N ; i++)
            if(b[i] == 1)
                countOne++;
            
        if(countOne == K){
            for(int i = 1 ; i <= N ; i++)
                printf("%d", b[i]);
            printf("\n");
        }
        return;
    }

    b[N-n+1] = 1;
    binaryNK(n-1, k-1);
    b[N-n+1] = 0;
    binaryNK(n-1, k);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    N = n;
    K = k;
    binaryNK(n, k);
    
    return 0;
}