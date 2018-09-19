#include <stdio.h>
#include <string.h>

#define MAX 1000000
int cache[MAX+1][MAX+1];

int combination(int n, int m){
    if(n == m || m == 0) return 1;
    int& ret = cache[n][m];
    if(ret != -1) return ret;
    return cache[n][m] = combination(n-1, m-1) + combination(n-1, m-1); 
}

int main(){
    memset(cache, -1, sizeof(cache));
    int n, m;
    scanf("%d %d", &n, &m);

    return 0;
}


/*
#include <stdio.h>

int five,

void countTwoFive(int startNum, int endNum){

}

int main(){
    int countMom5 = 0, countMom2 = 0;
    int countSon5 = 0, countSon2 = 0;


    return 0;
}
*/