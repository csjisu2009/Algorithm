//time   : 0h 30m

/*review : 1. Read the text exactly!!
              same height tower can't receive radar!!
              e)
              input:
              10
              1 1 1 1 1 1 1 1 1 1
              ouput:
              0 0 0 0 0 0 0 0 0 0
*/

#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

#define MAX 500000

class Tower {
public:
	int index;
	int height;
	Tower(int _index, int _height) {
		this->index = _index;
		this->height = _height;
	}
};

int N;
int hTower[MAX];
int rReTower[MAX];//radar received tower
stack<Tower> sHigher;

int main() {
	//input
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &hTower[i]);

	for (int i = 0; i < N; i++) {

		if (sHigher.empty()) {
			sHigher.push(Tower(i + 1, hTower[i]));
			rReTower[i] = 0;
		}
		else if (sHigher.top().height > hTower[i]) {
			rReTower[i] = sHigher.top().index;
			sHigher.push(Tower(i + 1, hTower[i]));
		}
		else if (sHigher.top().height <= hTower[i]) {
			while(!sHigher.empty() && sHigher.top().height <= hTower[i])
				sHigher.pop();
			if(sHigher.empty())
				rReTower[i] = 0;
			else
				rReTower[i] = sHigher.top().index;
			sHigher.push(Tower(i + 1, hTower[i]));
		}
	}

	//output
	for (int i = 0; i < N; i++) {
		printf("%d", rReTower[i]);
		if (i == N - 1) printf("\n");
		else printf(" ");
	}

	return 0;
}

/*
//naive method
#include <stdio.h>

#define MAX 500000
int N;
int hTower[MAX];
int rReTower[MAX];//radar received tower

int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &hTower[i]);

    rReTower[0] = 0;
    for(int i = N-1 ; 1 <= i ; i--){
        for(int j = i-1 ; 0 <= j ; j--){
            if(hTower[j] > hTower[i]){ // >= is wrong logic!!
                rReTower[i] = j + 1;
                break;
            }
            if(j == 0)//if can not find radar received tower
                rReTower[i] = 0;
        }
    }

    for(int i = 0 ; i < N ; i++){
        printf("%d", rReTower[i]);
        if(i == N-1) printf("\n");
        else printf(" ");
    }

    return 0;
}
*/