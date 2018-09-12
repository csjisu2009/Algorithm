#include <stdio.h>

int main(){
	int classes[1000][5];//[studentNo][grade]
	bool bFriends[1000][1000];//[studentNo][studentNo]
	int friendsCount[1000];
	int nStudent;
	scanf("%d", &nStudent);
	
	for(int j = 0 ; j < 1000 ; j++)
		for(int i = 0 ; i < 1000 ; i++)
			bFriends[j][i] = false;
			
	for(int i = 0 ; i < 1000 ; i++)
		friendsCount[i] = 0;
	
	for(int j = 0 ; j < nStudent ; j++)//studentNo
		for(int i = 0 ; i < 5 ; i++){//grade
			scanf("%d", &classes[j][i]);
		}
		
	for(int m = 0 ; m < nStudent ; m++){//mainStudent
		for(int g = 0 ; g < 5 ; g++){//grade
			for(int s = 0 ; s < nStudent ; s++){//subStudent
				if(m == s) continue;
				if(classes[m][g] == classes[s][g]){
					bFriends[m][s] = true;
					bFriends[s][m] = true;
				}
			}
		}
	}
	
	for(int m = 0 ; m < nStudent ; m++)
		for(int s= 0 ; s < nStudent ; s++){
			if(bFriends[m][s])
				friendsCount[m]++;
		}
	
	int countFriendLess = 0;//나보다 친구적은 친구들의 수 
	for(int j = 0 ; j < nStudent ; j++){
		for(int i = 0 ; i < nStudent ; i++){
			if(j == i) continue;
			if(friendsCount[i] <= friendsCount[j])
				countFriendLess++; 
		}
		if(countFriendLess == nStudent-1){
			printf("%d", j+1);
			return 0;
		}
		countFriendLess = 0;
	}
	
	return 0;
}