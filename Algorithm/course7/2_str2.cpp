#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(){
    char str[MAX+1];
    gets(str);//scanf("%[^\n]", &str);
    int len = strlen(str);
    for(int i = 0 ; i < len ; i++){
        if(65 <= str[i] && str[i] <= 90)
            printf("%c", str[i]+32);
        else if(97 <= str[i] && str[i] <= 122)
            printf("%c", str[i]-32);
        else
            printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}