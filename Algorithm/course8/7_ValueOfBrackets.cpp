#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX 30

char str[MAX+1];
int sum, temp;

bool checkGrammer(){
    stack<char> sBrackets;
    int size = strlen(str);
    for(int i = 0 ; i < size ; i++){
        if(str[i] == '(' || str[i] == '[')
            sBrackets.push(str[i]);
        else{
            if(sBrackets.empty())
                return false;
            else if(str[i] == ')' && sBrackets.front() == '[')
                return false;
            else if(str[i] == ']' && sBrackets.front() == '(')
                return false;
            else
                sBrackets.pop();
        }
    }
    return sBrackets.empty();
}

 void calcBrackets(){
    stack<char> sBrackets;
    int size = strlen(str);
    sum = 0;
    for(int i = 0 ; i < size ; i++){
        if(str[i] == '(' || str[i] == '[')
            temp = 1;
        else{
            if(str[i] == ')')
                temp = temp*2;
            else if(str[i] == ']')
                temp = temp*3;
            if(i != size-1 && (str[i+1] == '(' || str[i+1] == '['))
                sum += temp;
        }
    }
}

int main(){
    cin >> str;
    if(checkGrammer()){
        cout << '0' << endl;
        return 0;
    }
    calcBrackets();
    cout << sum << endl;
    return 0;
}