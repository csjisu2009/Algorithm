//time   : 

//review : you should use memoization

#include <stdio.h>
#include <string.h>

int cache[45+1];

int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

	int& ret = cache[n];
	if(ret != -1) return ret;
	return ret = fibo(n-1) + fibo(n-2);
}

int main(){
	memset(cache, -1, sizeof(cache));
    int n;
    scanf("%d", &n);
    printf("%d\n", fibo(n));

    return 0;
}