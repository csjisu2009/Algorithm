//time   : 0h 15m

/*review : do not think you must store prime!!! think out of the box!!!
*/ 

#include <stdio.h>
#define MAX 10000000

int main(){
    int N;
    scanf("%d", &N);

    while(N != 1){
        for(int i = 2 ; i <= MAX ; i++){
            if(N%i == 0){
                printf("%d\n", i);
                N = N/i;
                break;
            }
        }
    }
    return 0;
}