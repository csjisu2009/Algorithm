//time   : 0h 30m
 
/*review : 1. %s : print string
              %c : print a character
           2. remember what %[^\n] mean in c
              reference: 1) https://stackoverflow.com/questions/39431924/what-does-n-mean-in-c
                         2) https://www.studytonight.com/c/string-and-character-array.php
*/
#include <stdio.h>
#include <string.h>

#define MAX 100000

int main(){
    char str[MAX+1];
    scanf("%[^\n]", &str);//scanf("%s", &str);//gets(str);
    int len = strlen(str);

    for(int i = 0 ; i < len ; i++){
        if(str[i] == ' ') continue;
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}