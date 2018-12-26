

//naive method

#include <iostream>//#include <stdio.h>

using namespace std;

enum Direction{UP, DOWN};
int moveArr[2];

int main(){
    int a, b, v, hMove = 0;
    int day = 1;// yamae 
    int day = 0;
    cin >> a >> b >> v;//scanf("%d %d %d", &a, &b, &v);
    moveArr[UP] = a;
    moveArr[DOWN] = b;
    
    while(hMove < v){
       day++; 
       hMove += moveArr[UP];
       if(v <= hMove) break;
       hMove -= moveArr[DOWN];
       //day++;
    }
    cout << day << endl;//printf("%d\n", day);
    return 0;
}


/*
2
1

3
2

4
3

5
*/