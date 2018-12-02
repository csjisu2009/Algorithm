#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	queue<int> qNumbers;
	int n, m;
	scanf("%d %d", &n, &m);
	
	int action, num;
	for (int i = 0; i < m; i++) {
		scanf("%d", &action);
		if (action == 1) {
			scanf("%d", &num);
			if (qNumbers.size() < n)
				qNumbers.push(num);
			else
				printf("Overflow\n");
		}
		else if (action == 2) {
			if (0 < qNumbers.size())
				qNumbers.pop();
			else
				printf("Underflow\n");
		}
		else {
			if (0 < qNumbers.size())
				printf("%d\n", qNumbers.front());
			else
				printf("NULL\n");
		}
	}
	return 0;
}