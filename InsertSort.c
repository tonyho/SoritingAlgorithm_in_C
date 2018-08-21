#include<stdio.h>
#include<stdlib.h>

#include "common.h"

void moveBackForwad(int *ua,int j){
    ua[j+1] = ua[j];
    printf("moveBackForwad \t%2d --> \t%2d\n", j, j+1);
}
// 分类 ------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
// Image the cards, insert the elements into sorted elements array by
//  move back the largers
void InsertSort(int *ua,int len){
    // 1 elemnt is in-order
    for(int i=1; i<len; i++) {
        // must be the j=i not the j=0, otherwise the min would be selected at every round
        int temp = ua[i-1+1]; // Sort from the element after the sorted i
        for(int j=i-1; j>=0; j--) {
            printf("temp element is %2d, i=%2d,j=%2d\n", temp, i,j);
            if (0 == compare_little(temp, ua[j]) && j != 0) {
                moveBackForwad(ua,j);
            } else if (0 == compare_little(temp, ua[j]) && j == 0) {
                moveBackForwad(ua,j);
                ua[j] = temp;
                break;
            } else if (0 != compare_little(temp, ua[j])) {
                ua[j+1] = temp;
                break;
            }
        }
    }
}

void InsertSort_1(int *ua,int len){
    for (int i=1; i<len; i++) {
        int j = i -1;
        int temp = ua[i];
        while (compare_little(temp, ua[j]) == 0 && j>=0) {
            moveBackForwad(ua, j);
            j--;
        }
        ua[j+1] = temp;
    }
}

int main(){
    //int ua[10] = {10,9,8,7,6,5,4,3,2,1};
    int ua[10] = {10,8,9,7,6,5,4,3,2,1};

    printf("-----------------\n");
    printf("Original array\n");
    printArray(ua, 10);

    //BubbleSort(ua,10);
    InsertSort_1(ua,10);

    printf("Sorted array\n");
    printArray(ua, 10);

    printSwapCount();
    printCmpCount();

    return 0;
}
