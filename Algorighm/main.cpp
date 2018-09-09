#include <iostream>
using namespace std;

int board[8][8];
 
int main(){
    int yKing, xKing;
    int yRook[2], xRook[2];
    int result[2];
    
    for(int i = 0 ; i < 2; i++){
        yRook[i] = -1;
        xRook[i] = -1;
        result[i] = -1;
    }
    
    for(int j = 0 ; j < 8 ; j++)
        for(int i = 0 ; i < 8 ; i++)
            cin >> board[j][i];
    
    //scan position of king and rook
    int r = 0;
    for(int j = 0 ; j < 8 ; j++)
        for(int i = 0 ; i < 8 ; i++){
            if(board[j][i] == 1){
                yKing = j;
                xKing = i;
            }
            
            if(board[j][i] == 2){
                yRook[r] = j;
                xRook[r] = i;
                r++;
            }
        }

    //count rook 
    int nRook;
    if(xRook[0] == -1){
        cout << 0 << endl;
        return 0;
    }
    else if(xRook[1] == -1)
        nRook = 1;
    else nRook = 2;
    
    //calculate the possibility
    int countYEmp, countXEmp;//count '0' between king and rook
    int yDisKR, xDisKR;//distance of king and rook
    int xMin, xMax;
    int yMin, yMax;
    
    //calculate the y/x distance of king and rook
    for(int r = 0 ; r < nRook ; r++){
        if(yKing < yRook[r]) yDisKR = yRook[r]-yKing-1;
        else yDisKR = yKing-yRook[r]-1;
        
        if(xKing < xRook[r]) xDisKR = xRook[r]-xKing-1;
        else xDisKR = xKing-xRook[r]-1;
        
        if(yKing == yRook[r]){
            if(xKing < xRook[r]){
                xMin = xKing;
                xMax = xRook[r];
            }
            else{
                xMin = xRook[r];
                xMax = xKing;
            }

            countXEmp = 0;
            for(int i = xMin+1 ; i < xMax ; i++){
                if(board[yKing][i] == 0) countXEmp++;
            }
        }
        else if(xKing == xRook[r]){
            if(yKing < yRook[r]){
                yMin = yKing;
                yMax = yRook[r];
            }
            else{
                yMin = yRook[r];
                yMax = yKing;
            }

            countYEmp = 0;
            for(int j = yMin+1 ; j < yMax ; j++){
                if(board[j][xKing] == 0) countYEmp++;
            }
        }
        else{
            result[r] = 0;
        }
        
        if(countYEmp == yDisKR)
            result[r] = 1;
        else if(countYEmp+1 == yDisKR)
            result[r] = 1;
        else if(countXEmp == xDisKR)
            result[r] = 1;
        else if(countXEmp+1 == xDisKR)
            result[r] = 1;
        else
            result[r] = 0;
    }

    //return results
    if(nRook == 1)
        cout << result[0] << endl;
    else{
        if(result[0] == 1 || result[1] ==1)
            cout << 1 << endl;
        else 
            cout << 0 << endl;
    }
    return 0;
}
 
/*
#include <iostream>
using namespace std;
 
int main(){
    
    return 0;
}
*/
 
 
/*
0 3 0 0 0 0 0 0
3 1 0 0 0 2 0 0
0 3 0 0 0 0 0 0
0 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0


0 3 0 0 0 0 0 0
3 1 0 0 0 0 0 0
0 3 0 0 0 0 0 0
2 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0


0 3 0 0 0 0 0 0
3 1 0 0 3 2 0 0
0 3 0 0 0 2 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

0 3 0 0 0 0 0 0
3 0 0 0 3 0 0 0
0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2
0 0 0 0 0 0 2 1


0 3 0 0 0 0 0 0
3 0 0 0 3 0 0 0
0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 1

0 3 0 0 0 0 0 0
3 0 0 0 3 0 0 0
0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1



0 3 0 0 0 0 0 0
3 1 3 3 3 0 0 2
0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2


0 3 0 0 0 0 0 0
3 1 3 0 2 0 0 2
0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/