//time   : 1h 15m

/*review : step by step!! print out count first, and then print out numbers
           line-32 is important
*/ 

#include <stdio.h>
#include <iostream>
using namespace std;

int count = 0;
int N;
int num[20];
int pos = 0;

void division(int n, int preMinus){
    if(n < 0) return;
    if(n == 0){
        count++;
        for(int i = 0 ; i < pos ; i++){
            if(i != pos-1)
                printf("%d+", num[i]);
            else
                printf("%d", num[i]);

        }
        printf("\n");
        return;
    }
    for(int i = n ; 0 < i ; i--){
        if(i == N) continue;
        if(preMinus < i) continue;//important!!, 이 것 때문에 중복 피하고,  더하는 수들 내림차순 가능
        num[pos] = i;
        pos++;
        division(n-i, i);
        pos--;
    }
}

int main(){
    scanf("%d", &N);
    division(N, N);

    printf("%d\n", count);

    return 0;
}