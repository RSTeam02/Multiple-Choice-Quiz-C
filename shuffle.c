#include "shuffle.h"

//random int output without repeat as array
int *randomPos(size_t numOfElement, bool shuffle){
    srand(time(0));    
    int *intArr = malloc(numOfElement * sizeof(int));

    for(int i = 0; i < numOfElement; i++){
        intArr[i] = i;
    } 
    if(shuffle){
        for(int i = (numOfElement -1); i >= 0; i--){
            int j = (rand()%(i+1));
            int tmp = intArr[i];
            intArr[i] = intArr[j];
            intArr[j] = tmp;
        }
    }
    return intArr;
}