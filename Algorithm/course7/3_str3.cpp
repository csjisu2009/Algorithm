#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(){
    char str[MAX+1];
    scanf("%[^\n]", str);
    int len = strlen(str);
    for(int i = len-1 ; 0 <= i ; i--)
        printf("%c", str[i]);
    printf("\n");
    return 0;
}