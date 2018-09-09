#include <iostream>
using namespace std;
 
int gcd(int num1, int num2){
    int remainder = -1;
    int temp;
    if(num1 < num2){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    while(remainder != 0){
        remainder = num1%num2;
        num1 = num2;
        num2 = remainder;
    }
    return num1;
}
 
int main(){
    int num1, num2;
    cin >> num1 >> num2;
    
    cout << gcd(num1, num2) << endl << num1*num2/gcd(num1, num2) << endl;
    return 0;
}