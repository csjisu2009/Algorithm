//time   : 0h 9m
 
/*review : 
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(){
    bool bDifferent = false;
    char str[MAX+1];
    scanf("%[^\n]", &str);//gets(str);
    int len = strlen(str);
    for(int i = 0 ; i < len/2 ; i++){//0 1 2 3     0 1 2    0 1 2 3 4 5 6 7 8 
        if(str[i] != str[len-i-1]){
            bDifferent = true;
            break;
        }
    }
    if(bDifferent)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}