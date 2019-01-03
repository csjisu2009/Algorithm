#include <iostream>
#include <stdio.h>

using namespace std;

#define N_MAX 1000000

int N, M;
int arr[N_MAX];
int H;

int partition(int* arr, int lo, int hi){
    int pivot = arr[hi-1];
    int pIndex = lo;

    for(int i = lo ; i < hi-1 ; i++)
        if(arr[i] < pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    swap(arr[pIndex], arr[hi-1]);
    return pIndex;
}

void quickSort(int* arr, int lo, int hi){
    if(lo < hi){
        int pIndex = partition(arr, lo, hi);
        quickSort(arr, lo, pIndex);
        quickSort(arr, pIndex+1, hi);
    }
}

int binSearch(int* arr, int lo, int hi){
    int mi;
    int cuttedTreeLenSum;
    while(lo < hi){
        mi = (lo+hi) >> 1;
        cuttedTreeLenSum = 0;
        for(int i = mi+1 ; i < N ; i++)//the range standard of cutted tree is not "hi"!!
            cuttedTreeLenSum += (arr[i]-arr[mi]);
        //printf("cuttedTreeLenSum : %d\n", cuttedTreeLenSum);
        if(M < cuttedTreeLenSum)//put the H higher to cut less tree
            lo = mi+1;
        else if(cuttedTreeLenSum < M)//put the H lower to cut more tree
            hi = mi;
        else
            return mi;

    }
    return -1;
}

int main(){
    int index;
    scanf("%d %d", &N, &M);
    for(int i  = 0 ; i < N ; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, N);

    index = binSearch(arr, 0, N);
    H = arr[index];
    printf("%d\n", H);

    return 0;
}

/*
N M : 1 000 000 , 2 000 000 000
1th 2th ... Nth

H : 1 000 000 000

4 7
20 15 10 17

15
*/