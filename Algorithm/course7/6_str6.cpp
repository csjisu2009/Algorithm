//time   : 0h 10m
 
/*review : 
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

void printStrInclude(char* a, char* b, int aSize, int bSize){
    int bInclude = false;
    for(int i = 0 ; i < aSize ; i++){
        for(int j = 0 ; j < bSize ; j++){
            if(a[i+j] != b[j])
                break;
            if(j == bSize-1 && a[i+j] == b[j]){
                bInclude = true;
                break;
            }
        }
        if(bInclude)
            break;
    }
    if(bInclude)
        printf("YES\n");
    else
        printf("NO\n");
    return;
}

int main(){
    char strA[MAX+1];
    char strB[MAX+1];
    scanf("%[^\n]", &strA);//gets(strA);
    scanf(" %[^\n]", &strB);//gets(strB);
    int aLen = strlen(strA);
    int bLen = strlen(strB);
    printStrInclude(strA, strB, aLen, bLen);
    return 0;
}