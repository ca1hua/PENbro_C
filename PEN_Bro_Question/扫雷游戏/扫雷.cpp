#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10


//��������

//���̳�ʼ���ĺ���
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void DisplayBoard(char arr[ROWS][COLS], int row, int col);


//������
void SetMine(char arr[ROWS][COLS], int row, int col);

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

void menu()
{
	printf("**********************\n");
	printf("***** 1. play    *****\n");
	printf("***** 0. exit    *****\n");
	printf("**********************\n");
}

void game()
{
	//���ɨ����Ϸ
	//mine�����д�Ų��úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//����ȫ����ʼ��Ϊ'0'

	//show�����д���Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����ȫ����ʼ��Ϊ'*'

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//������
	//��9*9���������������10����
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//��ӡ����
	DisplayBoard(show, ROW, COL);

	//�Ų���
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);//1 0 x
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�������˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}





void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	//��ӡ�к�
	printf("------ɨ����Ϸ------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}

//static int GetMineCount(char mine[ROWS][COLS],int x, int y)
//{
//	return mine[x - 1][y] + 
//		mine[x - 1][y - 1] + 
//		mine[x][y - 1] + 
//		mine[x + 1][y - 1] +
//		mine[x + 1][y] + 
//		mine[x + 1][y + 1] + 
//		mine[x][y + 1] + 
//		mine[x - 1][y + 1] - 8*'0';
//}

 int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int i = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
		{
			count += (mine[i][j] - '0');
		}
	}
	return count;
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("������Ҫ�Ų������:");
		scanf("%d %d", &x, &y);
		//�ж��������Ч��
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					//�����겻���ף��͵�ͳ��������Χ�м�����
					int count = GetMineCount(mine, x, y);
					show[x][y] = count + '0';
					DisplayBoard(show, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("�������Ѿ����Ų��ˣ�������������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}