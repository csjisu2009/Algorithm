//time   : 1h 0m

/*review : 1. quick sort
           2. binary search
*/

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_N 300000
#define MAX_M 500000 

int partition(int* arr, int lo, int hi){
    int pivot = arr[hi-1];
    int pIndex = lo;
    for(int i = lo ; i < hi-1 ; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[hi-1]);
    return pIndex;
}

void quickSort(int* arr, int lo, int hi){
    if(lo < hi){
        int pIndex = partition(arr, lo, hi);
        quickSort(arr, lo, pIndex);//[, ) !! that why pIndex-1 -> pIndex
        quickSort(arr, pIndex+1, hi);
    }
}


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
    int N, M;
    int arrBox[MAX_N];
    int arrTest[MAX_M];
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &arrBox[i]);
    
    quickSort(arrBox, 0, N);

    int indexInBox;
    scanf("%d", &M);
    for(int i = 0 ; i < M ; i++){
        scanf("%d", &arrTest[i]);
        indexInBox = binSearch(arrBox, arrTest[i], 0, N);
        if(indexInBox != -1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}