#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 256 // 假定最多有256个字符，即叶子节点的数量

// 定义一个结构体来存储赫夫曼树的节点
typedef struct {
    int weight;   // 权值
    int parent;   // 双亲位置
    int lchild;   // 左孩子位置
    int rchild;   // 右孩子位置
} HuffmanNode;

// 初始化赫夫曼树
void initHuffmanTree(HuffmanNode huffmanTree[], int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        huffmanTree[i].weight = 0;
        huffmanTree[i].parent = -1;
        huffmanTree[i].lchild = -1;
        huffmanTree[i].rchild = -1;
    }
}

// 选择两个权值最小且未被选择的节点
void selectTwoMin(HuffmanNode huffmanTree[], int n, int* min1, int* min2) {
    int minWeight1 = INT_MAX, minWeight2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (huffmanTree[i].parent == -1) {
            if (huffmanTree[i].weight < minWeight1) {
                minWeight2 = minWeight1;
                *min2 = *min1;
                minWeight1 = huffmanTree[i].weight;
                *min1 = i;
            }
            else if (huffmanTree[i].weight < minWeight2) {
                minWeight2 = huffmanTree[i].weight;
                *min2 = i;
            }
        }
    }
}

// 创建赫夫曼树
void createHuffmanTree(HuffmanNode huffmanTree[], int weight[], int n) {
    initHuffmanTree(huffmanTree, n);
    for (int i = 0; i < n; i++) {
        huffmanTree[i].weight = weight[i];
    }

    for (int i = n; i < 2 * n - 1; i++) {
        int min1, min2;
        selectTwoMin(huffmanTree, i, &min1, &min2);
        huffmanTree[min1].parent = i;
        huffmanTree[min2].parent = i;
        huffmanTree[i].lchild = min1;
        huffmanTree[i].rchild = min2;
        huffmanTree[i].weight = huffmanTree[min1].weight + huffmanTree[min2].weight;
    }
}

// 从叶子节点到根节点逆向生成编码，存储在编码数组中
void generateCodes(HuffmanNode huffmanTree[], int n, char codes[][MAX_NODES]) {
    char code[MAX_NODES];
    code[n - 1] = '\0';

    for (int i = 0; i < n; i++) {
        int start = n - 2;
        int curnode = i;
        int parent = huffmanTree[i].parent;
        while (parent != -1) {
            if (huffmanTree[parent].lchild == curnode) {
                code[start--] = '0';
            }
            else {
                code[start--] = '1';
            }
            curnode = parent;
            parent = huffmanTree[parent].parent;
        }
        strcpy(codes[i], &code[start + 1]);
    }
}

// 输出赫夫曼编码，逆序输出
void printCodes(char codes[][MAX_NODES], int n) {
    for (int i = 0; i < n; i++) {
        printf("Code for node %d is %s\n", i, codes[i]);
    }
}

int main() {
    int n = 4; // 假设有4个字符
    int weights[] = { 7, 5, 2, 4 }; // 字符的权值数组

    HuffmanNode huffmanTree[2 * MAX_NODES]; // 赫夫曼树数组
    char codes[MAX_NODES][MAX_NODES]; // 赫夫曼编码数组

    createHuffmanTree(huffmanTree, weights, n);
    generateCodes(huffmanTree, n, codes);
    printCodes(codes, n);

    return 0;
}
