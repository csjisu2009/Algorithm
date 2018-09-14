//looks complicated at first, but just a print out floor problem!!!

#include <stdio.h>

int main(){
    int roomNum;
    scanf("%d", &roomNum);

    int roomSum = 2;
    int iRooms = 0;//room iÃþ 1°³, 6°³, 12°³...


    while(true){
        if(roomNum == 1){
            iRooms = 1;
            break;
        }
        if(roomNum < roomSum)
            break;
        roomSum += 6*iRooms;
        iRooms++;
    }
    printf("%d\n", iRooms);

    return 0;
}