#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int main() {
	stack <int> sNumbers;
	int n, m;
	scanf("%d %d", &n, &m);
	
	int action, num;
	for (int i = 0; i < m; i++) {
		scanf("%d", &action);
		if (action == 1) {
			scanf("%d", &num);
			if (sNumbers.size() < n)
				sNumbers.push(num);
			else
				printf("Overflow\n");
		}
		else if (action == 2) {
			if (0 < sNumbers.size())
				sNumbers.pop();
			else
				printf("Underflow\n");
		}
		else {
			if (0 < sNumbers.size())
				printf("%d\n", sNumbers.top());
			else
				printf("NULL\n");
		}
	}
	return 0;
}