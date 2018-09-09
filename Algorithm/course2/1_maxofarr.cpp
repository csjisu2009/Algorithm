#include <iostream>
using namespace std;
 
int arr[9][9];
 
int main(){
    int maxNum = 0;
    
    for(int j = 0 ; j < 9 ; ++j)
        for(int i = 0 ; i < 9 ; ++i)
            cin >> arr[j][i];
    
    for(int j = 0 ; j < 9 ; ++j)
        for(int i = 0 ; i < 9 ; ++i){
            if(maxNum < arr[j][i])
                maxNum = arr[j][i];
        }
        
    for(int j = 0 ; j < 9 ; ++j)
        for(int i = 0 ; i < 9 ; ++i){
            if(maxNum == arr[j][i]){
                cout << maxNum << endl << j+1 << " " << i+1 << endl;
                return 0;
            }
        }
    
    return 0;
}