#include <iostream>//#include <stdio.h>

using namespace std;

enum Direction{UP, DOWN};
long long int move[2];

int main(){
    long long int a, b, v, hMove = 0;
    long long int day = -1;
    cin >> a >> b >> v;//scanf("%d %d %d", &a, &b, &v);
    move[UP] = a;
    move[DOWN] = b;

    while(hMove <= v){
        day++;
        hMove += move[UP];
        if(v < hMove) break;
        hMove -= move[DOWN];
        
    }
    cout << day << endl;//printf("%d\n", day);
    return 0;
}