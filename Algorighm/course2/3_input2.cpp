#include <iostream>
using namespace std;
 
int board[10][10];
 
int main(){
    int n;
    cin >> n;
    
    for(int j = 0 ; j < 10 ; j++)
        for(int i = 0 ; i < 10 ; i++)
            board[j][i] = 0;
    
    for(int k = 0 ; k < n ; k++){
    
        for(int i = 0 ; i < 10 ; i++)
            if(board[k][i] == 0)        
                board[k][i] = 1;
            else
                board[k][i] = 0;
        for(int j = 0 ; j < 10 ; j++){
            if(j == k) continue;
            if(board[j][k] == 0)
                board[j][k] = 1;
            else
            board[j][k] = 0;
        }
    
    }
    
    for(int j = 0 ; j < 10 ; j++)
        for(int i = 0 ; i < 10 ; i++){
            cout << board[j][i];
            if(i == 9) cout << endl;
            else cout << " ";
        }
    
    return 0;
}