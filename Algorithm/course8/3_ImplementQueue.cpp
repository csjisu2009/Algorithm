//time   : 5h 0m

/*review : 1. if you implement Queue using array,
			  you can know why we call 'Circular Queue'
			  (I did not thought about that because I imaginally implemented Queue with List)
		   2. front pointer == rear pointer
		   	  means no element in Queue
		   3. error : I did not thought about the "frontIndex == rearIndex" situation!!
		        	  in "pop" and "front" action
*/

#include <stdio.h>

using namespace std;
#define MAX 100

int arr[MAX];
int n, m;

int main() {
	int actionNum;//1 - push ; 2 - pop ; 3 - print front
	int numPushed;
	int frontIndex = 0, rearIndex = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &actionNum);
		if(actionNum == 1) {
			scanf("%d", &numPushed);
			if (rearIndex == n)
				printf("Overflow\n");
			else {
				arr[rearIndex] = numPushed;
				rearIndex++;
			}
		}
		else if(actionNum == 2) {
			if (frontIndex == n || frontIndex == rearIndex)//do not forget the "frontIndex == rearIndex" situation!!
				printf("Underflow\n");
			else
				frontIndex++;
		}
		else if (actionNum == 3) {
			if (frontIndex == n || frontIndex == rearIndex)// do not forget the "frontIndex == rearIndex" situation!!
				printf("NULL\n");
			else
				printf("%d\n", arr[frontIndex]);
		}
	}

	return 0;
}