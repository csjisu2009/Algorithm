//time   : 0h 30m

//review : think simple!! solve one value and then solve them all!!

#include <stdio.h>

int s[1000][1000], a[1000];

int main(){
    int n;
    scanf("%d", &n);

    for(int j = 0 ; j < n ; j++)
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &s[j][i]);
        }
    a[0] = (s[0][1] + s[0][2] - s[1][2])/2;

    for(int i = 1 ; i < n ; i++)
        a[i] = s[0][i] - a[0];

    for(int i = 0 ; i < n ; i++){
        printf("%d", a[i]);
        if(i == n-1) printf("\n");
        else printf(" ");
    }
    return 0;
}