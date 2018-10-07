//time   : 1h 0m

/*review : 1. read carefully!! input without spacebar!! how to do this?
           2. read carefully!! print output ascending!!
*/

#include <stdio.h>

#define MAX 25
int N;
int cnt = 0;
int index = 0;
int board[MAX][MAX];
bool boardDefined[MAX][MAX];//board is defined or not
int cntDanji[13*13];

void insertsionSort(){
    int temp;
    int size = index;
    for(int i = 1 ; i <= size ; i++){
        int j = i;
        while(0 < j && cntDanji[j] < cntDanji[j-1]){
            temp = cntDanji[j];
            cntDanji[j] = cntDanji[j-1];
            cntDanji[j-1] = temp;
            j--;
        }
    }
}

void defineDanjiNum(int y, int x){
    if(boardDefined[y][x] || board[y][x] == 0) return;
    if(y < 0 || N <= y) return;
    if(x < 0 || N <= x) return;
    if(!boardDefined[y][x] 
       && board[y][x] == 1){
           cnt++;
           boardDefined[y][x] = true;
    }
    defineDanjiNum(y+1, x);//up
    defineDanjiNum(y-1, x);//down
    defineDanjiNum(y, x-1);//left
    defineDanjiNum(y, x+1);//right
}

void searchMap(){
    for(int j = 0 ; j < N ; j++){
        for(int i = 0 ; i < N ; i++){
            cnt = 0;
            if(board[j][i] == 1 & !boardDefined[j][i]){
                defineDanjiNum(j, i);
                if(cnt)
                    cntDanji[++index] = cnt;
            }
        }
    }
}

int main(){
    char ch[MAX];
    scanf("%d", &N);
    for(int j = 0 ; j < N ; j++){
        scanf("%s", &ch);
        for(int i = 0 ; i < N ; i++){
            if(ch[i] == '0') board[j][i] = 0;
            else board[j][i] = 1;
        }
    }

    for(int j = 0 ; j < N ; j++)
        for(int i = 0 ; i < N ; i++)
            boardDefined[j][i] = false;
    
    searchMap();

    printf("%d\n", index);

    insertsionSort();

    for(int i = 1 ; i <= index ; i++)
        printf("%d\n", cntDanji[i]);

    return 0;
}