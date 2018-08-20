#include<stdio.h>
#include<stdlib.h>
#include "common.h"

int swap_count = 0;
int cmp_count = 0;
void swap(int *ua, int i, int j){
    int temp = ua[i];
    ua[i] = ua[j];
    ua[j] = temp;
    swap_count  ++;
}

// If i < j, return 0; return -1 when equal
int compare_little(int i, int j){
    cmp_count  ++;
    if (i < j) {
        return 0;
    } else if(i == j) {
        return -1;
    }
    return 1;
}

void printCmpCount(void) {
    printf("cmp_count is %2d \n",cmp_count);
    cmp_count = 0;
}

void printSwapCount(void) {
    printf("swap_count is %2d \n",swap_count);
    swap_count = 0;
}

void printArray(int *a, int len) {
    for (int i=0; i<10; i++) {
        printf("%2d ",a[i]);
    }
    printf("\n");
}
