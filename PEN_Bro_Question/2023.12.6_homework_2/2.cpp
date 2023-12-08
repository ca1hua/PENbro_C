#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef struct{
	int weight;
	int parent;
	int left_child;
	int right_child;
}HuffmanNode;

HuffmanNode huffmanTree[MAX_TREE_SIZE];

void createHuffmanTree(HuffmanNode huffmanTree[],int n)
{
		for (int i=0; i < 2 * n - 1; i++)
		{
			huffmanTree[i].weight = 0;//����������
			huffmanTree[i].parent = -1;
			huffmanTree[i].left_child = -1;
			huffmanTree[i].right_child = -1;
		}

		printf("����Ȩֵ��\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &huffmanTree[i].weight);
		}

		//��ʼ����
		for (int i = n;i < 2 * n-1; i++)
		{ 
			int x1 = -1, x2 = -1;
			int min1 = 100000, min2 = 100000;//������С
			//�ҳ�������СȨֵ
			for (int j = 0; j < i; j++)
			{
				if (huffmanTree[j].parent == -1 && huffmanTree[j].weight != 0)
				{
					if (huffmanTree[j].weight < min1) {
						min2 = min1;
						x2 = x1;
						min1 = huffmanTree[j].weight;
						x1 = j;
					}
					else if (huffmanTree[j].weight < min2) {
						min2 = huffmanTree[j].weight;
						x2 = j;
					}

				}
			}

			if (huffmanTree[x1].weight > huffmanTree[x2].weight) {
				int temp = x1;
				x1 = x2;
				x2 = temp;
			}//�������һλ������ֱ�Ӽ�һ��swap


			// �ϲ�������С�ڵ�
			huffmanTree[x1].parent = i;
			huffmanTree[x2].parent = i;
			huffmanTree[i].left_child = x1;
			huffmanTree[i].right_child = x2;
			huffmanTree[i].weight = huffmanTree[x1].weight + huffmanTree[x2].weight;
		}
}


      // �����ӡ�շ�������
      void printHuffmanCode(int s[], int top) {
	for (int i = top - 1; i >= 0; i--) {
		printf("%d", s[i]);
	}
	printf("\n");
}

	  void putHuffmanCode(HuffmanNode huffmanTree[], int n)
	  {

		  int code[MAX_TREE_SIZE]; // ��������·��������
		  int top;                // ջ��ָ�룬�Ϲ�أ�αջ 
		  //��ÿ��Ҷ�ӷ���
		  for (int i = 0; i < n; i++)
		  {
			  top = 0;
			  int current = i;
			  int parent = huffmanTree[i].parent;
			  // ��Ҷ�ӵ����ڵ��������
			  while (parent != -1) {
				  if (huffmanTree[parent].left_child == current) {
					  code[top++] = 0; // ���Ӹ�ֵ0
				  }
				  else {
					  code[top++] = 1; // �Һ��Ӹ�ֵ1
				  }
				  current = parent;
				  parent = huffmanTree[parent].parent;//������һ��,��������ѭ��

			  }
			  // �����ӡ����
			  printf("�ڵ�Ȩֵ %d �ı���Ϊ: ", huffmanTree[i].weight);
			  printHuffmanCode(code, top);

		  }
	  }

int main()
{
	int n;//�Žڵ�����
	printf("������ڵ�������");
	scanf("%d",&n);
	createHuffmanTree(huffmanTree,n);

	putHuffmanCode(huffmanTree, n);
	return 0;
}