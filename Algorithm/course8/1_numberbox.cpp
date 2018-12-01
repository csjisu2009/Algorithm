//time   : 0h 20m

/*review : 1. 4 kinds of method
            1) naive method - O(N^2) : fucking slow..
            2) O(N) x 2 
            3) use 2 stacks (stack permutation?? not sure..)
            4) use 1 circular queue

           2. naive method - O(N^2)

*/

//2) O(N) x 2 method
#include <stdio.h>

#define MAX 1000000

int N, M;

int main() {
	bool numInBox[MAX + 1];//positive numbers array [0, 1000000]
    bool numInBox_neg[MAX];//negative numbers array [-1000000, -1]
	int numInTest[MAX/2 + 1];
	for (int i = 0; i < MAX+1; i++)
		numInBox[i] = false;
    for(int i = 0 ; i < MAX ; i++)
        numInBox_neg[i] = false;

	scanf("%d", &N);
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
        if(0 <= temp)
		    numInBox[temp] = true;
        else
            numInBox_neg[temp + MAX] = true;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
		scanf("%d", &numInTest[i]);

	for (int i = 0; i < M; i++) {
        if(0 <= numInTest[i]){
            if (numInBox[ numInTest[i] ])
                printf("1\n");
            else
                printf("0\n");
        }
        else{
            if (numInBox_neg[numInTest[i] + MAX])
                printf("1\n");
            else
                printf("0\n");
        }
	}
	return 0;
}