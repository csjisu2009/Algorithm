//time   : 1h 30m
 
//review : can't solve if you just use for-loop, you should use recursion

#include <stdio.h>

void countTwoFive(int endNum, int& count5, int& count2){
    int num;
    for(int i = 1 ; i <= endNum ; i++){
        //count 5
        num = i;
        while(true){
            if(num % 10 == 0 || num % 5 == 0){
                num = num/5;
                count5++;
            }
            else if(num % 10 == 0 || num % 2 == 0){
                num = num/2;
                count2++;
            }
            else break;
        }
    }
}

int countZero(int countM5, int countM2, int countS5, int countS2){
    if(countS5 < countM5 && countS2 < countM2){
        if(countM5-countS5 <= countM2-countS2)
            return countM5-countS5;
        else return countM2-countS2;
    }
    return 0;
}

int main(){
    int countMom5 = 0, countMom2 = 0;
    int countSon5 = 0, countSon2 = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    countTwoFive(n, countMom5, countMom2);
    countTwoFive(m, countSon5, countSon2);
    countTwoFive(n-m, countSon5, countSon2);

    int result = countZero(countMom5, countMom2, countSon5, countSon2);
    printf("%d\n", result);
    return 0;
}