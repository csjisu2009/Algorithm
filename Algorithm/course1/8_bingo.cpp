#include <iostream>
using namespace std;
 
int board[25][25];
 
int main(){
    int mcNum[25];
    int countBinggo;
    for(int j = 0 ; j < 5 ; ++j)
        for(int i = 0 ; i < 5 ; ++i)
            cin >> board[j][i];
    for(int i = 0 ; i < 25 ; ++i)
        cin >> mcNum[i];
        
    for(int mc = 0 ; mc < 25 ; ++mc)
        for(int j = 0 ; j < 5 ; ++j)
            for(int i = 0 ; i < 5 ; ++i){
                if(mcNum[mc] == board[j][i])
                    board[j][i] = 0;
                    
                if(12 <= mc ){//min 13 blocks make binggo
                    countBinggo = 0;
                    //count binggo - row
                    if(board[0][0] == board[0][1]
                        && board[0][1] == board[0][2]
                        && board[0][2] == board[0][3]
                        && board[0][3] == board[0][4]
                        && board[0][4] == 0)
                        ++countBinggo;
                    if(board[1][0] == board[1][1] == board[1][2] == board[1][3] == board[1][4] == 0) ++countBinggo;
                    if(board[2][0] == board[2][1] == board[2][2] == board[2][3] == board[2][4] == 0) ++countBinggo;
                    if(board[3][0] == board[3][1] == board[3][2] == board[3][3] == board[3][4] == 0) ++countBinggo;
                    if(board[4][0] == board[4][1] == board[4][2] == board[4][3] == board[4][4] == 0) ++countBinggo;
                    
                    //count binggo - col
                    if(board[0][0] == board[1][0] == board[2][0] == board[3][0] == board[4][0] == 0) ++countBinggo;
                    if(board[0][1] == board[1][1] == board[2][1] == board[3][1] == board[4][1] == 0) ++countBinggo;
                    if(board[0][2] == board[1][2] == board[2][2] == board[3][2] == board[4][2] == 0) ++countBinggo;
                    if(board[0][3] == board[1][3] == board[2][3] == board[3][3] == board[4][3] == 0) ++countBinggo;
                    if(board[0][4] == board[1][4] == board[2][4] == board[3][4] == board[4][4] == 0) ++countBinggo;
                    
                    //count binggo - cross
                    if(board[0][0] == board[1][1] == board[2][2] == board[3][3] == board[4][4] == 0) ++countBinggo;
                    if(board[0][4] == board[1][3] == board[2][2] == board[3][1] == board[4][0] == 0) ++countBinggo;
                    
                    if(countBinggo >= 3){
                        cout << mc+1 << endl;
                        return 0;
                    }
                }
            }
    
    return 0;
}