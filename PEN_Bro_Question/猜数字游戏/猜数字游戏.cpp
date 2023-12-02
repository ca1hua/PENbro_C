#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void game()
{
	srand((unsigned int)time(NULL));
	int guess = 0;
	int ret = rand() % 100 + 1;
	int count = 5;
	while (count)
	{
		printf("你还有 %d 次机会\n", count);
		printf("请输入要猜的数字:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了，数字是:%d\n", ret);
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("很遗憾，五次机会使用完，挑战失败，随机数是：%d\n", ret);
	}
}

int main()
{

	int input;
	
	do
	{
		printf("请输入你要选择的模式\n");
		printf("*********************\n");
		printf("***  1 开始游戏   ***\n");
		printf("***  0 退出游戏   ***\n");
		printf("*********************\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("开始游戏\n");
			game();
			break;
		}
		
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);//input不能在外面
	return 0;
}