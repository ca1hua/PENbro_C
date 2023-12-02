#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swapArrays(int *arrayA, int *arrayB, int size) {
    for(int i = 0; i < size; i++) {
        int temp = arrayA[i];
        arrayA[i] = arrayB[i];
        arrayB[i] = temp;
    }
}

int main() {
    const int SIZE = 5; // 假设数组大小为5
    int arrayA[SIZE] = {1, 2, 3, 4, 5};
    int arrayB[SIZE] = {6, 7, 8, 9, 10};

    // 输出交换前的数组内容
    printf("交换前:\n");
    printf("Array A: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arrayA[i]);
    }
    printf("\nArray B: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arrayB[i]);
    }
    printf("\n");

    // 调用函数交换两个数组的内容
    swapArrays(arrayA, arrayB, SIZE);

    // 输出交换后的数组内容
    printf("交换后:\n");
    printf("Array A: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arrayA[i]);
    }
    printf("\nArray B: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arrayB[i]);
    }
    printf("\n");

    return 0;
}
