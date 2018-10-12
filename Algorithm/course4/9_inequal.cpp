//time   : 1h 10m

/*review : ruecursion with array!!
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int K;
char inequalitySigns[9];
int numbers[10];
bool bNumberUsed[10];
bool bFindAready = false;

bool inequalitiesCorrect(){
    int countCorrects = 0;
    for(int i = 0 ; i < K ; i++){
        if(inequalitySigns[i] == '<'){
            if(numbers[i] < numbers[i+1])
                countCorrects++;
        }
        else if(inequalitySigns[i] == '>'){
            if(numbers[i] > numbers[i+1])
                countCorrects++;

        }
    }
    if(countCorrects == K){
        bFindAready = true;
        return true;
    }
    else return false;
}

void inputNumbersDescending(int n){
    if(bFindAready) return;
    if(n == 0){
        if(inequalitiesCorrect()){
            for(int i = 0 ; i < K+1 ; i++)
                printf("%d", numbers[i]);
            printf("\n");
        }
        return;
    }

    for(int i = 9 ; 0 <= i ; i--){
        if(!bNumberUsed[i]){
            bNumberUsed[i] = true;
            numbers[(K+1)-n] = i;
            inputNumbersDescending(n-1);
        }
        else
            continue;
        bNumberUsed[i] = false;
    }
}

void inputNumbersAscending(int n){
    if(bFindAready) return;
    if(n == 0){
        if(inequalitiesCorrect()){
            for(int i = 0 ; i < K+1 ; i++)
                printf("%d", numbers[i]);
            printf("\n");
        }
        return;
    }

    for(int i = 0 ; i < 10 ; i++){
        if(!bNumberUsed[i]){
            bNumberUsed[i] = true;
            numbers[(K+1)-n] = i;
            inputNumbersAscending(n-1);
        }
        else
            continue;
        bNumberUsed[i] = false;
    }
}

int main(){
    scanf("%d", &K);
    for(int i = 0 ; i < K ; i++)
        cin >> inequalitySigns[i];
        //scanf("%c", &inequalitySigns[i]);

    //test
    /*
    for(int i = 0 ; i < K ; i++)
        printf("%c", inequalitySigns[i]);
    */
    //
    for(int i = 0 ; i < 10 ; i++)
        bNumberUsed[i] = false;

    inputNumbersDescending(K+1);
    bFindAready = false;
    inputNumbersAscending(K+1);
    return 0;
}