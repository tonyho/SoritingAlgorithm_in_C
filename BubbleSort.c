#include<stdio.h>
#include<stdlib.h>

static int swap_count = 0;
static int cmp_count = 0;
void swap(int *ua, int i, int j){
    int temp = ua[i];
    ua[i] = ua[j];
    ua[j] = temp;
    swap_count  ++;
}

void BubbleSort_2(int *ua,int len){
    int sorted = 1;
    for(int i=0; i<len; i++) {
        for(int j=len-1; j>=1+i; j--) {
            cmp_count  ++;
            if(ua[j] < ua[j-1]) {
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
        for(int j=len-1; j>=1+i; j--) {
            cmp_count  ++;
            if(ua[j] < ua[j-1]) {
                swap(ua, j, j-1);
            }
        }
    }
}

void BubbleSort(int *ua,int len){
    for(int i=0; i<len; i++) {
        for(int j=len-1; j>=1; j--) {
            if(ua[j] < ua[j-1]) {
                swap(ua, j, j-1);
            }
        }
    }
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

int main(){
    //int ua[10] = {10,9,8,7,6,5,4,3,2,1};
    int ua[10] = {10,7,9,7,6,5,4,3,2,1};

    printf("-----------------\n");
    printf("Ori\n");
    printArray(ua, 10);

    //BubbleSort(ua,10);
    BubbleSort_1(ua,10);

    printf("Sorted\n");
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
