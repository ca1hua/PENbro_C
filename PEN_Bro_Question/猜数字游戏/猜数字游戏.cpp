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
		printf("�㻹�� %d �λ���\n", count);
		printf("������Ҫ�µ�����:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("��С��\n");
		}
		else if (guess > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�������:%d\n", ret);
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("���ź�����λ���ʹ���꣬��սʧ�ܣ�������ǣ�%d\n", ret);
	}
}

int main()
{

	int input;
	
	do
	{
		printf("��������Ҫѡ���ģʽ\n");
		printf("*********************\n");
		printf("***  1 ��ʼ��Ϸ   ***\n");
		printf("***  0 �˳���Ϸ   ***\n");
		printf("*********************\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("��ʼ��Ϸ\n");
			game();
			break;
		}
		
		case 0:
		{
			printf("�˳���Ϸ\n");
			break;
		}
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);//input����������
	return 0;
}