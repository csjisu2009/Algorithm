//time   : 1h 0m
 
/*review : Euclidean algorithm(유클리드 호제법),
           you do not have to use loop!!!! to solve this problem!!!!(n^2-loop -> n-loop -> no-loop)
*/

#include <stdio.h>

#define MAX 100000

int pos[MAX];

int max(int a, int b){
    if(a <= b) return b;
    else return a;
}

int min(int a, int b){
    if(a <= b) return a;
    else return b; 
}

int gcd(int num1, int num2){
    int remainder = -1;
    if(num1 < num2){
        int temp = min(num1, num2);
        num1 = max(num1, num2);
        num2 = temp;
    }
    while(remainder != 0){
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }
    return num1;
}

int main(){
    //common: common tree distance
    int N, common;
    int fullCount, count;//count : how many tree you will plant
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &pos[i]);
        if(i == 1)
            common = pos[i] -pos[i-1];
        if(2 <= i){
            common = gcd(common, pos[i] - pos[i-1]);
        }
    }
    fullCount = (pos[N-1] - pos[0])/common + 1;
    count = fullCount - N;
    printf("%d\n", count);

    return 0;
}