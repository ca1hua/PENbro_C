#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//ʹ�� do while ѭ������Ļ�ϴ�ӡ1~10��ֵ

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
//	int count = 0;//����
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

//ʹ��while����Ļ�ϴ�ӡ1~10

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
//continue ��������������ѭ����continue��ߵĴ��룬ֱ��ȥ�жϲ��֣����Ƿ������һ���ж�
//

//ʹ��for����Ļ�ϴ�ӡ1~10

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
//		//�ж�i�Ƿ�������
//		//������������ʹ�ӡ����������������
//		//��2~i-1֮�������ȥ�����Գ�i�����������һ������������i��i�Ͳ�������
//		//������е����ֶ���������i��i��������
//		int j = 0;
//		int flag = 1;//����i������
//		for (j = 2; j <= i - 1; j++)//2~8
//		{
//			if (i % j == 0)
//			{
//				flag = 0;//֤����������
//				break;
//			}
//		}
//		if (flag == 1)//������
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
	//1. ���������
	int ret = rand() % 100 + 1;
	//printf("%d\n", ret);
	//2. ������
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
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);//1 0 
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ���������ѡ��\n");
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

//����ĳ�ʼ��
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
//	//����
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//���
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//�������Ԫ�ظ���
//int main()
//{
//	int arr[10] = {0};
//	printf("%zd\n", sizeof(arr));//40  - �������������ܴ�С����λ���ֽ�
//	printf("%zd\n", sizeof(arr[0]));//4 - �����������һ��Ԫ�صĴ�С����λ���ֽ�
//	printf("%zd\n", sizeof(arr) / sizeof(arr[0]));//������������Ԫ�ظ���
//
//	return 0;
//}
//

//%p - ר��������ӡ��ַ

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d] = %p\n", i, &arr[i]);//& - ȡ��ַ����
//	}
//	return 0;
//}