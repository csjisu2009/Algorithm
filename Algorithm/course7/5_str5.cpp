//time   : 0h 30m
 
/*review : read the text carefully!!!
           e)
           input:  AABBAA
           output: 2A2B2A (right!!)
           output: 4A2B   (wrong!!)

*/

#include <stdio.h>
#include <string.h>

#define MAX 10000

int main(){
    char str[MAX+1];
    int cntAlphabet = 0;
    gets(str);

    int len = strlen(str);
    int index = 0;
    while(index < len && str[index] != '\0'){
        cntAlphabet++;
       // printf("cntAlphabet : %d\n", cntAlphabet);
        if(str[index] != str[index+1]){
            if(cntAlphabet == 1)
                printf("%c", str[index]);
            else if(1 < cntAlphabet)
                printf("%d%c", cntAlphabet, str[index]);
            cntAlphabet = 0;
        }
        index++;
    }
    return 0;
}
/*
//print result from 'A' to 'Z'
int main(){
    char str[MAX+1];
    int cntAlphabet[26];//count 'A' ~ 'Z'

    for(int i = 0 ; i < 26 ; i++)
        cntAlphabet[i] = 0;

    gets(str);//scanf("%[^\n]", &str);
    int len = strlen(str);
    for(int i = 0 ; i < len ; i++)
        cntAlphabet[str[i] - 65]++;
    
    for(int i = 0 ; i < 26 ; i++)
        if(cntAlphabet[i] != 0){
            if(cntAlphabet[i] == 1)
                printf("%c", i+65);
            else
                printf("%d%c", cntAlphabet[i], i+65);
        }
    printf("\n");
    return 0;
}
*/