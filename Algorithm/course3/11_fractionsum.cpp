//time   : 0h 20m
 
//review : gcd

//dinominator numerator

#include <stdio.h>

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
    int numerator1, numerator2, dinominator1, dinominator2;
    int numerator3, dinominator3;
    scanf("%d %d", &numerator1, &dinominator1);
    scanf("%d %d", &numerator2, &dinominator2);

    numerator3 = numerator1*dinominator2 + numerator2*dinominator1;
    dinominator3 = dinominator1*dinominator2;

    int common = gcd(dinominator3, numerator3);
    printf("%d %d\n", numerator3/common, dinominator3/common);

    return 0;
}