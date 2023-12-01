#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 256 // �ٶ������256���ַ�����Ҷ�ӽڵ������

// ����һ���ṹ�����洢�շ������Ľڵ�
typedef struct {
    int weight;   // Ȩֵ
    int parent;   // ˫��λ��
    int lchild;   // ����λ��
    int rchild;   // �Һ���λ��
} HuffmanNode;

// ��ʼ���շ�����
void initHuffmanTree(HuffmanNode huffmanTree[], int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        huffmanTree[i].weight = 0;
        huffmanTree[i].parent = -1;
        huffmanTree[i].lchild = -1;
        huffmanTree[i].rchild = -1;
    }
}

// ѡ������Ȩֵ��С��δ��ѡ��Ľڵ�
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

// �����շ�����
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

// ��Ҷ�ӽڵ㵽���ڵ��������ɱ��룬�洢�ڱ���������
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

// ����շ������룬�������
void printCodes(char codes[][MAX_NODES], int n) {
    for (int i = 0; i < n; i++) {
        printf("Code for node %d is %s\n", i, codes[i]);
    }
}

int main() {
    int n = 4; // ������4���ַ�
    int weights[] = { 7, 5, 2, 4 }; // �ַ���Ȩֵ����

    HuffmanNode huffmanTree[2 * MAX_NODES]; // �շ���������
    char codes[MAX_NODES][MAX_NODES]; // �շ�����������

    createHuffmanTree(huffmanTree, weights, n);
    generateCodes(huffmanTree, n, codes);
    printCodes(codes, n);

    return 0;
}
