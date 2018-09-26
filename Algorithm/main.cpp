//time   : 0h 0m

/*review : 
*/ 
#include <stdio.h>

void nBinaryK1(int n, int k){
    if(n == 0){
        printf("\n");
        return;
    }
    if(0 < k){
        printf("1");
        nBinaryK1(n-1, k-1);
        printf("0");
        nBinaryK1(n-1, k);
    }
    else{
        printf("0");
        nBinaryK1(n-1, k);
    }
    return;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    nBinaryK1(n, k);
    
    return 0;
}