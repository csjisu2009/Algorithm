/*remember : when you wannna solve shortest path problem, bfs is proper
             you must think clearly when use dfs and when use bfs
             you know when dfs and bfs are same same?? -- when you wanna check all the situation!! they are same same!!
*/
 
//time   : 2h 0m
 
/*review : 1. bfs !!(board[][] or bDiscovered[][].. just choose one!!)
           2. think out of the box!! think about a "line"!!(not a "square")
           3. boundary bug in bfs!!
               0 < vp.y-1
               0 < vp.x-1
               
               testCase:
               input:
               3 2 3
               0 1 1 2
               0 1 0 1
               0 1 0 2
               
               output:
               1
               5
*/
 
#include <stdio.h>
#include <queue>
using namespace std;
 
#define MAX 100
 
int Y, X, K;
class Point {
public:
    int y;
    int x;
 
    Point() {}
    Point(int y, int x) {
        this->y = y;
        this->x = x;
    }
};
bool bDiscovered[MAX+1][MAX+1];
int sArray[MAX*MAX];
int sIndex = 0;
int s = 0;
void bfs(Point p) {
    bDiscovered[p.y][p.x] = true;
    s++;
    queue<Point> qNotVistedYet;
    qNotVistedYet.push(p);
    Point vp;
    while (!qNotVistedYet.empty()) {
        vp = qNotVistedYet.front();
        qNotVistedYet.pop();
 
        //check Up-Coordinate
        if (vp.y + 1 < Y && !bDiscovered[vp.y + 1][vp.x]) {
            bDiscovered[vp.y + 1][vp.x] = true;
            qNotVistedYet.push(Point(vp.y+1, vp.x));
            s++;
        }
        //check Right-Coordinate
        if (vp.x + 1 < X && !bDiscovered[vp.y][vp.x+1]) {
            bDiscovered[vp.y][vp.x+1] = true;
            qNotVistedYet.push(Point(vp.y, vp.x+1));
            s++;
        }
        //check Down-Coordinate
        if (0 <= vp.y-1 && !bDiscovered[vp.y-1][vp.x]) {//bug : 0 < vp.y-1
            bDiscovered[vp.y-1][vp.x] = true;
            qNotVistedYet.push(Point(vp.y-1, vp.x));
            s++;
        }
        //check Left-Coordinate
        if (0 <= vp.x-1 && !bDiscovered[vp.y][vp.x-1]) {//bug : 0 < vp.x-1
            bDiscovered[vp.y][vp.x-1] = true;
            qNotVistedYet.push(Point(vp.y, vp.x-1));
            s++;
        }
    }
    sArray[sIndex] = s;
    s = 0;
    sIndex++;
    return;
}
 
//quick sort
int partition(int* A, int start, int end) {
    int pivot = A[end];
    int pIndex = start;
 
    for (int i = start; i < end; ++i)
        if (A[i] <= pivot) {
            swap(A[i], A[pIndex]);
            ++pIndex;
        }
    swap(A[pIndex], A[end]);
    return pIndex;
}
 
void quickSort(int* A, int start, int end) {
    if (start < end) {
        int pIndex = partition(A, start, end);
        quickSort(A, start, pIndex - 1);
        quickSort(A, pIndex + 1, end);
    }
}
 
int main() {
    scanf("%d %d %d", &Y, &X, &K);
    //initialize board[][] as 1
    for(int j = 0 ; j < Y ; j++)
        for (int i = 0; i < X; i++)
            bDiscovered[j][i] = false;
    //declare square's leftDown coordinates and rightUp coordinates
    int yDown, xDown, yUp, xUp;
    //fill the board's square area with 0
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d %d", &xDown, &yDown, &xUp, &yUp);
        if(xDown == xUp || yDown == yUp) continue;//consider the "line" situation!!
        for (int y = yDown; y < yUp; y++)
            for (int x = xDown; x < xUp; x++)
                bDiscovered[y][x] = true;
    }
     
    for(int j = 0 ; j < Y ; j++)
        for (int i = 0; i < X; i++) {
            if (!bDiscovered[j][i])
                bfs(Point(j, i));
        }
 
    printf("%d\n", sIndex);
    quickSort(sArray, 0, sIndex-1);//becareful!! [start, end], not [start, end)
    if(sIndex == 0) printf("0\n");
    else
        for (int i = 0; i < sIndex; i++) {
            printf("%d", sArray[i]);
            if (i == sIndex - 1) printf("\n");
            else printf(" ");
        }
    return 0;
}