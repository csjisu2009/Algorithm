#include <stdio.h>

//1) naive method
int binSearch(int* arr, int e, int lo, int hi){
    int mi;
    while(lo < hi){
        mi = (lo+hi) >> 1;
        if(e < arr[mi])
            hi = mi;
        else if(arr[mi] < e)
            lo = mi+1;
        else
            return mi;
    }
    return -1;
}

int main(){
    //int arr[5] = {1, 2, 3, 4, 5};
    //printf("%d\n", binSearch(arr, 3, 0, 5));
    return 0;
}