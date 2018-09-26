//time   : 0h 20m
 
//review : https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4

#include <stdio.h>

bool isPrime[1001];

void checkPrime(int n){
    isPrime[0] = false;
    isPrime[1] = false;

    if(n <= 1)
        return;
    
    for(int i = 2 ; i <= n ; i++)
        isPrime[i] = true;
    for(int i = 2 ; i*i <= n ; i++){
        if(isPrime[i])
            for(int j = i*i ; j <= n ; j += i)
                isPrime[j] = false;
    }
    return;
}
int main(){
    checkPrime(1000);

    int n, num, count = 0;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &num);
        if(isPrime[num])
            count++;
    }

    printf("%d\n", count);

    return 0;
}