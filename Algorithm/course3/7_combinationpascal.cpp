//time   : 
 
//review : can't solve if you just use for-loop, you should use recursion
 
#include <stdio.h>
#include <string.h>
 
int cache[31][31];
int combination(int n, int m){
    if(m == 0 || n == m) return 1;
    int& ret = cache[n][m];
    if(ret != -1) return ret;
    return cache[n][m] = combination(n-1, m-1) + combination(n-1, m);   
}
 
int main(){
    memset(cache, -1, sizeof(cache));
 
    int n, m;
    scanf("%d %d", &n, &m);
 
    printf("%d\n", combination(n, m));
    return 0;
}