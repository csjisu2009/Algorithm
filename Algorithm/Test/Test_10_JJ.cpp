//time   : 1h 0m

/*review : 1. naive method : 60 points

           2. do not forget "return" !! in "if(r == 0)" logic

*/

#include <stdio.h>

char str[27];
bool bChar[27];//a(97) ~ z(122); used - true, unused - false
int numChar, numElement;

void dictionaryStr(int r){
    if(r == 0){
        for(int i = 0 ; i < numElement ; i++)
            printf("%c", str[i]);
        printf("\n");
        return;//do not forget this line!! else "14 1" case is "Time Limit Exceeded"
    }
    for(int i = 0 ; i < numChar ; i++){
        if(!bChar[i]){
            str[numElement-r] = i+97;//str[i] = i+97;
            bChar[i] = true;
            dictionaryStr(r-1);
            str[numElement-r] = 0;//str[i] = 0;
            bChar[i] = false;
        }
    }
    return;
}

int main(){
    scanf("%d %d", &numChar, &numElement);
    for(int i = 0 ; i < numChar ; i++)
        bChar[i] = false;

    dictionaryStr(numElement);

    return 0;
}