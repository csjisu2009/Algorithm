//Euclidean algorithm(유클리드 호제법)

#include <stdio.h>
 
long long int gcd(long long int num1, long long int num2){
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

long long int lcm(long long int num1, long long int num2, long long int gcd){
    return num1*num2/gcd;
}
 
int main(){
    long long int num1, num2, gcdNum;
    scanf("%lli %lli", &num1, &num2);
    
    gcdNum = gcd(num1, num2);
    printf("%lli\n", lcm(num1, num2, gcdNum));
    return 0;
}