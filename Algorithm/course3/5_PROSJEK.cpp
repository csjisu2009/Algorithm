//time   : 0h 30m

//review : 

#include <stdio.h>

int a[100], b[100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &b[i]);
    
    a[0] = b[0];
    for(int i = 1 ; i < n ; i++){
        a[i] = (i+1)*b[i];
        for(int j = 0 ; j < i ; j++){
            a[i] = a[i] - a[j];
        }
        
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d", a[i]);
        if(i != n-1) printf(" ");
        else printf("\n");
    }
    return 0;
}