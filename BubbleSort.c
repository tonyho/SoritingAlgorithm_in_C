#include<stdio.h>
#include<stdlib.h>

#include "common.h"


//No swapping means aleady sorted/in-order
void BubbleSort_2(int *ua,int len){
    int sorted = 1;
    for(int i=0; i<len; i++) {
        for(int j=len-1; j>=1+i; j--) {
            if (0 == compare_little(ua[j], ua[j-1])) {
                swap(ua, j, j-1);
                sorted = 0;
            }
        }
        if (sorted == 1) {
            return;
        }
    }
}

void BubbleSort_1(int *ua,int len){
    for(int i=0; i<len; i++) {
        for(int j=len-1; j>=1+i; j--) {// The i elements are already in order
            if (0 == compare_little(ua[j], ua[j-1])) {
                swap(ua, j, j-1);
            }
        }
    }
}

void BubbleSort(int *ua,int len){
    for(int i=0; i<len; i++) {
        for(int j=len-1; j>=1; j--) {
            if (0 == compare_little(ua[j], ua[j-1])) {
                swap(ua, j, j-1);
            }
        }
    }
}


int main(){
    //int ua[10] = {10,9,8,7,6,5,4,3,2,1};
    int ua[10] = {10,7,9,7,6,5,4,3,2,1};

    printf("-----------------\n");
    printf("Original array\n");
    printArray(ua, 10);

    //BubbleSort(ua,10);
    BubbleSort_1(ua,10);

    printf("Sorted array\n");
    printArray(ua, 10);

    printSwapCount();
    printCmpCount();

    printf("-----------------\n");
    printf("Sorted testing\n");
    printArray(ua, 10);
    BubbleSort_2(ua,10);
    printArray(ua, 10);
    printSwapCount();
    printCmpCount();

    return 0;
}
