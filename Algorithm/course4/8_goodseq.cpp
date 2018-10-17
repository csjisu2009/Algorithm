//time   : 2h 0m

/*review : = and == is different!!! fuck!!!
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 80

int N;
int goodseq[MAX + 1];
bool bIndexFilled[MAX + 1];
bool bFoundGoodSeq = false;

bool judgeGood(int index) {//judge goodseq's (index)th number is good or bad
	if (bFoundGoodSeq) return false;
	int sizeCompare = index / 2;
	if (sizeCompare == 0) return true;

	int countSame;
	int temp_index;
	for (int i = 1; i <= sizeCompare; i++) {
		countSame = 0;
		temp_index = index;
		for (int j = 1; j <= i; j++) {
			if (goodseq[temp_index] == goodseq[temp_index - i])//goodseq[index - j]
				countSame++;
			temp_index--;
		}
		if (countSame == i) return false;
	}
	
	if (index == N) {
		for (int i = 1; i <= N; i++)
			printf("%d", goodseq[i]);
		printf("\n");
		bFoundGoodSeq = true;
	}
    
	return true;
}

void putNumber(int n){//put n numbers
	if (bFoundGoodSeq) return;
	if (n == 0) return;//fucking stupid bug!!!!!! if(n = 0)!!!!
	for (int i = 1; i <= 3; i++) {
		goodseq[N - n + 1] = i;
		if (judgeGood(N - n + 1)) {
			putNumber(n - 1);
		}
	}
	return;
}

int main() {
	scanf("%d", &N);
	putNumber(N);
	return 0;
}