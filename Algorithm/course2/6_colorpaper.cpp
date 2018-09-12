#include <stdio.h>
 
int board[101][101];
 
int main(){
    
    int N;
    int x, y, xSize, ySize;
    int area[100];
    scanf("%d", &N);
    
    y = y-1;
    x = x-1;
    
    for(int j = 0 ; j < 101 ; j++)
        for(int i = 0 ; i < 101 ; i++)
            board[j][i] = 0;
            
    for(int n = 0 ; n < N ; n++){
        scanf("%d %d %d %d", &x, &y, &xSize, &ySize);
        for(int j = y ; j < y+ySize ; j++)
            for(int i = x ; i < x+xSize ; i++)
                board[j][i] = n+1;
    }
    
    int countArea = 0;
    for(int n = 0 ; n < N ; n++){
        for(int j = 0 ; j < 101 ; j++){
            for(int i = 0 ; i < 101 ; i++){
                if(board[j][i] == n+1)
                    countArea++;
            }
        }
        area[n] = countArea;
        countArea = 0;
    }
    
    for(int i = 0 ; i < N ; i++)
        printf("%d\n", area[i]);
        
    return 0;
}