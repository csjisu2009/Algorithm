//time   : 0h 10m

/*review : 
*/ 
#include <stdio.h>

void mountain(int n){
    if(n == 1){
        printf("1");
        return;
    }
    mountain(n-1);
    printf("%d", n);
    mountain(n-1);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    mountain(n);
    return 0;
}