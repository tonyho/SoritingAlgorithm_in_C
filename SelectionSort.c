#include<stdio.h>
#include<stdlib.h>

#include "common.h"

void SelectionSort(int *ua,int len){
    for(int i=0; i<len; i++) {
        int min = i;
        // must be the j=i not the j=0, otherwise the min would be selected at every round
        for(int j=i; j<len; j++) {
            if (0 == compare_little(ua[j], ua[min])) {
                min = j;
            }
        }
        // Increase the number of compare
        if(-1 != compare_little(i, min)) {// not equal
            printf("Round %d, find the min index is:%d\n", i, ua[min]);
            swap(ua, i, min); //reduce the swap times
        }
    }
}

int main(){
    //int ua[10] = {10,9,8,7,6,5,4,3,2,1};
    int ua[10] = {10,8,9,7,6,5,4,3,2,1};

    printf("-----------------\n");
    printf("Original array\n");
    printArray(ua, 10);

    //BubbleSort(ua,10);
    SelectionSort(ua,10);

    printf("Sorted array\n");
    printArray(ua, 10);

    printSwapCount();
    printCmpCount();

    return 0;
}
