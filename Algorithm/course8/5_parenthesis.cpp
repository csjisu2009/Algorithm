//time   : 0h 29m

/*review : 1. 4 kinds of brackets
			1) () parenthesis
			2) [] square brackets
			3) {} curly brackets
			4) <> angle brackets

		   2. why cin >> str is correct,
              and gets(str) / scanf("%[^\n]", str) are wrong??

*/
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>

#define MAX 50

using namespace std;

char str[MAX + 1];

bool checkBracketsPair(char* ch) {
	int chLen = strlen(ch);
	stack<char> sLeftBrackets;
	for (int i = 0; i < chLen; i++) {
		if (str[i] == '(') sLeftBrackets.push('(');
		else {
			if (sLeftBrackets.empty())
				return false;
			else
				sLeftBrackets.pop();
		}
	}
	return sLeftBrackets.empty();
}

int main() {
	cin >> str;//scanf("%[^\n]", str);//gets(str);
	bool bPair = checkBracketsPair(str);
	if (bPair)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}