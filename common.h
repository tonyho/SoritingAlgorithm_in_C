#ifndef COMMON_H
#define COMMON_H
extern int swap_count;
extern int cmp_count;

void swap(int *ua, int i, int j);

int compare_little(int i, int j);

void printCmpCount(void);

void printSwapCount(void);

void printArray(int *a, int len);

#endif
