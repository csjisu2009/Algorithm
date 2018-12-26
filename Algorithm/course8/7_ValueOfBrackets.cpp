//time   : 3h 0m

/*review : 1. 1 kinds of method
            1) complicate method : 80 points..
            2) add number at every step method

           2. sometimes you should think the whole process again!!

*/

// 2) add number at every step method
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX 30

char str[MAX + 1];
int sum = 0;//psum is a part of sum

stack<char> sBrackets;

bool checkGrammer() {
	int size = strlen(str);
	for (int i = 0; i < size; i++) {
		if (str[i] == '(' || str[i] == '[')
			sBrackets.push(str[i]);
		else {
			if (sBrackets.empty())
				return false;
			else if (str[i] == ')' && sBrackets.top() == '[')
				return false;
			else if (str[i] == ']' && sBrackets.top() == '(')
				return false;
			else
				sBrackets.pop();
		}
	}
	return sBrackets.empty();
}

void calcBrackets() {
	int size = strlen(str);
	int num = 1;
	for (int i = 0; i < size; i++) {
		if (str[i] == '(') {
			sBrackets.push('(');
			num *= 2;
			if (i + 1 < size && str[i + 1] == ')')
				sum += num;
		}
		else if (str[i] == '[') {
			sBrackets.push('[');
			num *= 3;
			if (i + 1 < size && str[i + 1] == ']')
				sum += num;
		}
		else if (str[i] == ')') {
			sBrackets.pop();
			num /= 2;
		}
		else if (str[i] == ']') {
			sBrackets.pop();
			num /= 3;
		}
	}
}

int main() {
	cin >> str;
	if (!checkGrammer()) {
		cout << '0' << endl;
		return 0;
	}
	calcBrackets();
	printf("%d\n", sum);
	return 0;
}


//80 points
/*
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX 30

char str[MAX + 1];
int psum = 1, sum = 0;//psum is a part of sum

class Bracket {
public:
	char bracket;
	int number;
	Bracket() {}
	Bracket(char bracket) {
		this->bracket = bracket;
		if (bracket == '(')  this->number = 2;
		else if (bracket == '[')  this->number = 3;
	}
};

bool checkGrammer() {
	stack<char> sBrackets;
	int size = strlen(str);
	for (int i = 0; i < size; i++) {
		if (str[i] == '(' || str[i] == '[')
			sBrackets.push(str[i]);
		else {
			if (sBrackets.empty())
				return false;
			else if (str[i] == ')' && sBrackets.top() == '[')
				return false;
			else if (str[i] == ']' && sBrackets.top() == '(')
				return false;
			else
				sBrackets.pop();
		}
	}
	return sBrackets.empty();
}

stack<Bracket> sB;
stack<int> sSum;//if(sB.empty()); sSum.push(sum); and add the sum of sSum in the end!!
void calcBrackets() {
	Bracket bTop;
	int size = strlen(str);
	for (int i = 0; i < size; i++) {
		//push
		if (str[i] == '(' || str[i] == '[')
			sB.push(Bracket(str[i]));
		//pop
		else {
			bTop = sB.top();
			sB.pop();

			//when stack of Bracket is empty
			//calculate psum
			if (!sB.empty()) {
				psum *= bTop.number;
				//add psum to sum, when bracket start with '(' or '['
				if (i + 1 < size && (str[i + 1] == '(' || str[i + 1] == '[')) {
					sum += psum;
					psum = 1;
				}
			}
			//when stack of Bracket is empty
			//calculate sum
			else {
				//when there are just one pair of bracket    ; e) ()[]()
				if (psum == 1) {
					psum *= bTop.number;
					sum += psum;
				}
				else {
					sum += psum;
					sum *= bTop.number;
				}
				sSum.push(sum);
				sum = 0;
				psum = 1;
			}
		}
	}
}

//calculate sum of sSum
int calcSum() {
	int result = 0;
	while (!sSum.empty()) {
		result += sSum.top();
		sSum.pop();
	}
	return result;
}

int main() {
	cin >> str;
	if (!checkGrammer()) {
		cout << '0' << endl;
		return 0;
	}
	calcBrackets();
	cout << calcSum() << endl;
	return 0;
}
*/

//(([](([]))))
//60