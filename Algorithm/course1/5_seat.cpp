#include <iostream>
using namespace std;
 
int main() {
    int ySize, xSize, numWait;//careful!! C == ySize, R == xSize
    cin >> ySize >> xSize;
    cin >> numWait;
 
    //seats are fully filled already
    if (xSize*ySize < numWait) {
        cout << 0 << endl;
        return 0;
    }
 
    int y = 0, x = -1;
    
    int lenFlowR = xSize;
    int r=0;
    int lenFlowD = ySize-1;
    int d=0;
    int lenFlowL = xSize-1;
    int l=0;
    int lenFlowU = ySize-2;
    int u=0;
    
    if(numWait == 1){
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    
    for (int num = 1; num <= numWait ; ++num) {
    
        if (r < lenFlowR) {
            r++;
            x++;
        }
        //down flow
        else if (d < lenFlowD) {
            d++;
            y++;
        }
        //left flow
        else if (l < lenFlowL) {
            l++;
            x--;
        }
        //up flow
        else if (u < lenFlowU) {
            u++;
            y--;
        }
        
        if(u == lenFlowU){
            if(r == lenFlowR){
                lenFlowR -= 2;
                r = 0;
            }
            if(d == lenFlowD){
                lenFlowD -= 2;
                d = 0;
            }
            if(l == lenFlowL){
                lenFlowL -= 2;
                l = 0;
            }
            
            lenFlowU -= 2;
            u = 0;
        }
        
        //print seats
        if (numWait == num) {
            cout << y+1 << " " << x+1 << endl;
            return 0;
        }
    }
 
    return 0;
}