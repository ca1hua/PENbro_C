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
			huffmanTree[i].weight = 0;//问问张子颜
			huffmanTree[i].parent = -1;
			huffmanTree[i].left_child = -1;
			huffmanTree[i].right_child = -1;
		}

		printf("输入权值：\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", &huffmanTree[i].weight);
		}

		//开始造树
		for (int i = n;i < 2 * n-1; i++)
		{ 
			int x1 = -1, x2 = -1;
			int min1 = 100000, min2 = 100000;//俩个最小
			//找出两个最小权值
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
			}//老是最后一位出错，我直接加一个swap


			// 合并两个最小节点
			huffmanTree[x1].parent = i;
			huffmanTree[x2].parent = i;
			huffmanTree[i].left_child = x1;
			huffmanTree[i].right_child = x2;
			huffmanTree[i].weight = huffmanTree[x1].weight + huffmanTree[x2].weight;
		}
}


      // 逆序打印赫夫曼编码
      void printHuffmanCode(int s[], int top) {
	for (int i = top - 1; i >= 0; i--) {
		printf("%d", s[i]);
	}
	printf("\n");
}

	  void putHuffmanCode(HuffmanNode huffmanTree[], int n)
	  {

		  int code[MAX_TREE_SIZE]; // 用来保存路径（逆序）
		  int top;                // 栈顶指针，老规矩，伪栈 
		  //对每个叶子分析
		  for (int i = 0; i < n; i++)
		  {
			  top = 0;
			  int current = i;
			  int parent = huffmanTree[i].parent;
			  // 从叶子到根节点逆向遍历
			  while (parent != -1) {
				  if (huffmanTree[parent].left_child == current) {
					  code[top++] = 0; // 左孩子赋值0
				  }
				  else {
					  code[top++] = 1; // 右孩子赋值1
				  }
				  current = parent;
				  parent = huffmanTree[parent].parent;//往上面一层,继续进行循环

			  }
			  // 逆序打印编码
			  printf("节点权值 %d 的编码为: ", huffmanTree[i].weight);
			  printHuffmanCode(code, top);

		  }
	  }

int main()
{
	int n;//放节点数量
	printf("请输入节点数量：");
	scanf("%d",&n);
	createHuffmanTree(huffmanTree,n);

	putHuffmanCode(huffmanTree, n);
	return 0;
}