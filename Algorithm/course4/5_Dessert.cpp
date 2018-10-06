//time   : 5h 0m

/*review : 1. initilization is important!!! it causes bug!!(line23, line 35)
           2. you do not have to count sign!!! I thought if(countPlus == 0 || countMinus == 0) formulaEqualZero() return false;
              but it was fault!!
              e) 1.2-3-4-5
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int N;
int cnt = 0;//count formulas
char signs[15];

bool formulaEqualZero(){
    int countPlus = 0, countMinus = 0;

    //calculate formula
    int dotNum;//the number include '.'
    int dotIndex = -1;//signs[m] == '.', 'm' is dotIndex
    int sum = 1;//initilization is important!!! it causes bug!!
    for(int i = 1 ; i < N ; i++){//for-loop of signs[15]
        if(i < dotIndex) continue;
        if(signs[i] == '+'){
            sum += i+1;
        }

        else if(signs[i] == '-'){
            sum -= (i+1);
        }
        
        else if(signs[i] == '.'){
            char preSign = ' ';//initilization is important!!! it causes bug!!
            dotNum = i;
            dotIndex = i;

            if(i != 1){
                preSign = signs[i-1];
                if(preSign == '+') sum -= dotIndex;
                else if(preSign == '-') sum += dotIndex;
            }
            
            while(signs[dotIndex] == '.'){
                if(dotIndex+1 < 10)
                    dotNum *= 10;
                else//added after test N = 10;
                    dotNum *= 100;
                dotNum += (dotIndex+1);
                dotIndex++;
            }
            //calculate final sum after dotNum, when dot is end
            if(preSign == '+') sum += dotNum;
            else if(preSign == '-') sum -= dotNum;
            else{//sign[1] == '.'
                sum = dotNum;
            }
        }
    }
    if(sum == 0)
       return true;
    return false;
}

void inputSigns(int n){
    //print result if the sum is 0, when formula is fully filled
    if(n == 0){
        if( formulaEqualZero() ){
            if(cnt < 20){
                for(int i = 1 ; i < N ; i++)
                    printf("%d %c ", i, signs[i]);
                printf("%d\n", N);
            }
            cnt++;
        }
        return;
    }

    //fill the formula within +, -, .
    signs[N-n] = '+';
    inputSigns(n-1);
    signs[N-n] = '-';
    inputSigns(n-1);
    signs[N-n] = '.';
    inputSigns(n-1);
}

int main(){
    scanf("%d", &N);
    inputSigns(N-1);
    printf("%d\n", cnt);
    
    return 0;
}