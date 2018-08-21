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
#ifdef SWAP_DEBUG_LOG
    printf("swap %2d and %2d \n", i, j);
#endif
}

// If i < j, return 0; return -1 when equal
int compare_little(int i, int j){
    int ret = 1;
    cmp_count  ++;
    if (i < j) {
        ret = 0;
    } else if(i == j) {
        ret = -1;
    }
#ifdef CMP_DEBUG_LOG
    printf("cmp \t%2d and \t%2d , ret = \t%2d\n", i, j, ret);
#endif
    return ret;
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
