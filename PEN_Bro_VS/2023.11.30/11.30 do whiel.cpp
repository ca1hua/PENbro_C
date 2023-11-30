#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//使用 do while 循序在屏幕上打印1~10的值

//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	} while (i<=10);
//
//	return 0;
//}


//int main()
//{
//
//	return 0;
//}
//

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);//12
//	int count = 0;//计数
//
//	//n = 0
//	do
//	{
//		count++;//2
//		n = n / 10;
//	} while (n);
//
//	printf("%d\n", count);
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = {0};
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n",arr[i]);
//	}
//	return 0;
//}

//使用while在屏幕上打印1~10

//int main()
//{
//	int i = 1;
//	while (i<=10)
//	{
//		i++;
//		if (i == 5)
//			continue;
//
//		printf("%d ", i);
//	}
//
//	return 0;
//}
//
//continue 是用于跳过本次循环的continue后边的代码，直接去判断部分，看是否进行下一次判断
//

//使用for在屏幕上打印1~10

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//
//	return 0;
//}
//


#include <stdio.h>

//int main()
//{
//    int i = 1;
//    do
//    {
//        if (i == 5)
//            continue;
//        printf("%d ", i);
//        i = i + 1;
//    } while (i <= 10);
//
//    return 0;
//}
//
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否是素数
//		//如果是素数，就打印，不是素数就跳过
//		//拿2~i-1之间的数字去挨个试除i，如果其中有一个数字整除了i，i就不是素数
//		//如果所有的数字都不能整除i，i就是素数
//		int j = 0;
//		int flag = 1;//假设i是素数
//		for (j = 2; j <= i - 1; j++)//2~8
//		{
//			if (i % j == 0)
//			{
//				flag = 0;//证明不是素数
//				break;
//			}
//		}
//		if (flag == 1)//是素数
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}
//
//
//

//void test()
//{
//}
//
//int main()
//{
//zhangsan:
//	printf("hehe\n");
//	printf("hehe\n");
//	printf("hehe\n");
//	printf("hehe\n");
//	printf("hehe\n");
//	goto zhangsan;
//
//	return 0;
//}

#include <stdlib.h>
#include <time.h>

//int main()
//{
//	//RAND_MAX;//32,767
//	srand((unsigned int)time(NULL));
//	//0~99
//	//1~100
//	printf("%d\n", rand() % 100+1);
//	printf("%d\n", rand() % 100+1);
//	printf("%d\n", rand() % 100+1);
//	printf("%d\n", rand() % 100+1);
//	printf("%d\n", rand() % 100+1);
//
//	return 0;
//}
//
//
//
//void menu()
//{
//	printf("***********************\n");
//	printf("***     1. play     ***\n");
//	printf("***     0. exit     ***\n");
//	printf("***********************\n");
//}
//
void game()
{
	int guess = 0;
	//1. 生成随机数
	int ret = rand() % 100 + 1;
	//printf("%d\n", ret);
	//2. 猜数字
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
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);//1 0 
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n");
//			break;
//		}
//		//...
//	} while (input);
//
//	return 0;
//}
//
//


//int main()
//{
//	int data[10];//
//	char ch[5];
//	double arr[8];
//
//	return 0;
//}

//数组的初始化
//int main()
//{
//	int data1[10] = {0};//
//	int data2[10] = { 1,2,3 };//
//	int data3[10] = { 1,2,3,4,5,6,7,8,9,10 };//
//	//int data4[10] = { 1,2,3,4,5,6,7,8,9,10,11 };//err
//
//
//
//	char ch[5] = {'a', 'b'};
//	double arr[8] = {1.0, 2.0};
//
//	return 0;
//}
//


//int main()
//{
//	int arr[10];
//	int n;
//	return 0;
//}
//

//
//int main()
//{
//	int arr1[10] = { 0 };
//	char arr2[5] = {0};
//	printf("%zu\n", sizeof(arr2));//?
//	printf("%zu\n", sizeof(char [5]));
//
//	//printf("%zd\n", sizeof(arr1));//
//	//printf("%zd\n", sizeof(int [10]));//
//
//
//	return 0;
//}
//



//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//
//	printf("%d\n", arr[5]);
//	return 0;
//}


//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	           //0 1 2 3 4 5 6 7 8 9 
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	//printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
//	return 0;
//}
//

//
//int main()
//{
//	int arr[5] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//输入
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//输出
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//求数组的元素个数
//int main()
//{
//	int arr[10] = {0};
//	printf("%zd\n", sizeof(arr));//40  - 计算的是数组的总大小，单位是字节
//	printf("%zd\n", sizeof(arr[0]));//4 - 计算的是数组一个元素的大小，单位是字节
//	printf("%zd\n", sizeof(arr) / sizeof(arr[0]));//计算的是数组的元素个数
//
//	return 0;
//}
//

//%p - 专门用来打印地址

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d] = %p\n", i, &arr[i]);//& - 取地址操作
//	}
//	return 0;
//}