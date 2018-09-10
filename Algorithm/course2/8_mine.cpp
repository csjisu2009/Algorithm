#include <iostream>
using namespace std;

int board[100][100];
int yMine, xMine;
int countMine = 0;
//check the position (y, x) is in the 9 position, countMine++
//1 2 3
//4   5
//6 7 8
void checkMine(int y, int x){
    if((y == yMine-1 || y == yMine+1)
        && (x == xMine-1 || x == xMine || x == xMine+1))
        countMine++;
    else if(y == yMine && 
            (x == xMine-1 || x == xMine+1))
        countMine++;
}

int main(){
    int ySize, xSize;

    cin >> ySize >> xSize;
    cin >> yMine >> xMine;
    yMine-=1;
    xMine-=1;

    for(int j = 0 ; j < ySize ; j++)
        for(int i = 0 ; i < xSize ; i++)
            cin >> board[j][i];
    
    //(yMine, xMine) is a mine
    if(board[yMine][xMine] == 1){
        cout << "game over" << endl;
        return 0;
    }
    //(yMine, xMine) is not a mine
    for(int j = 0 ; j < ySize ; j++)
        for(int i = 0 ; i < xSize ; i++){
            if(board[j][i] == 1)
                checkMine(j, i);
        }
    if(!countMine)
        cout << "game over" << endl;
    else
        cout << countMine << endl;
    return 0;
}