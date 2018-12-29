#include <stdio.h>
#include <iostream>
using namespace std;
//use pivot to return the index of mid value(also put the mid value to the middle of the array)

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

int main(){
    int arr[5] = {6, 3, 2, 10, -10};
    quickSort(arr, 0, 5);
    for(int i = 0 ; i < 5 ; i++)
        printf("%d ", arr[i]);
    return 0;
}