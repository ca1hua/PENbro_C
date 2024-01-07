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


//声明函数

//棋盘初始化的函数
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisplayBoard(char arr[ROWS][COLS], int row, int col);


//布置雷
void SetMine(char arr[ROWS][COLS], int row, int col);

//排查雷
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
	//完成扫雷游戏
	//mine数组中存放布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//数组全部初始化为'0'

	//show数组中存放排查出的雷的信息
	char show[ROWS][COLS] = { 0 };//数组全部初始化为'*'

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//布置雷
	//就9*9的棋盘上随机布置10个雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//打印棋盘
	DisplayBoard(show, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);//1 0 x
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束，退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
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
	//打印列号
	printf("------扫雷游戏------\n");
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
		printf("请输入要排查的坐标:");
		scanf("%d %d", &x, &y);
		//判断坐标的有效性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					//该坐标不是雷，就得统计坐标周围有几个雷
					int count = GetMineCount(mine, x, y);
					show[x][y] = count + '0';
					DisplayBoard(show, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("该坐标已经被排查了，重新输入坐标\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}