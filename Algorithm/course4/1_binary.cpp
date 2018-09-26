//time   : 0h 9m

/*review : 
*/ 
#include <stdio.h>

void binary(int n){
    if(n == 1){
        printf("1");
        return;
    }
    binary(n/2);
    printf("%d", n%2);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    binary(n);
    return 0;
}