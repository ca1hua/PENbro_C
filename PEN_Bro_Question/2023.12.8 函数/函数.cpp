#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//�����Ķ��壨���캯����
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	//����
//	scanf("%d%d", &a, &b);
//	//�ӷ�
//	//int c = a + b;
//	int c = Add(a, b);//�����ĵ��ã�ʹ�ú�����
//	printf("%d\n", c);
//
//	return 0;
//}

//void print(void)
//{
//	printf("hehe\n");
//}

//void print()
//{
//	printf("hehe\n");
//}
//
//int main()
//{
//	print();
//	print(1);
//	print(1,2);
//
//	return 0;
//}

#include <stdio.h>

//int Add(int x, int y)//��ʽ����������β�
//{
//    return x + y;
//}
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    //����
//    scanf("%d %d", &a, &b);
//    int r = Add(a, b);//a,b����ʵ���ݸ�Add�����Ĳ���
//    //a,b��ʵ�Σ�ʵ�ʲ�����
//    
//    //���
//    printf("%d\n", r);
//    return 0;
//}

//void test(int n)
//{
//	if (n <= 0)
//		return;
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//	printf("%d\n", sum);
//}
//int main()
//{
//	test(5);
//	return 0;
//}

//int test()
//{
//	return 3.14;
//}
//
//int main()
//{
//	int r = test();
//	printf("%d\n", r);
//	return 0;
//}

//���������ж�n����������ż��
//����������1
//��ż������0

//int test(int n)
//{
//	if (n % 2 == 1)
//		return 1;
//	else
//		return 0;
//}
//
//
//int main()
//{
//	int ret = test(6);
//
//	return 0;
//}
//
//
//
//void set_arr(int arr2[10], int sz2)
//{
//	int i = 0;
//	for (i = 0; i < sz2; i++)
//	{
//		arr2[i] = -1;
//	}
//}
//
//void print_arr(int arr2[], int sz2)
//{
//	int i = 0;
//	for (i = 0; i < sz2; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//
//	print_arr(arr1, sz1);
//
//	//дһ��������arr���������ȫ������Ϊ-1
//	set_arr(arr1, sz1);
//
//	//дһ��������arr���������ȫ����ӡ����
//	print_arr(arr1, sz1);
//	return 0;
//}
//

//�������Ǽ���ĳ��ĳ���ж����죿
//1  2  3  4  5  6  7  8  9  10 11 12
//31 28 31 30 31 30 31 31 30 31 30 31
//   29

//int is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//		return 1;//���귵��1
//	else
//		return 0;//�������귵��0
//}

//#include <stdbool.h>
//
//_Bool is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//		return true;//���귵��1
//	else
//		return false;//�������귵��0
//}
//
//int get_days_of_month(int y, int m)
//{
//	int days[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
//	//             0  1  2  3  4  5  6  7  8
//	int day = days[m];
//	if (is_leap_year(y) && m == 2)
//		day += 1;
//
//	return day;
//}
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	scanf("%d %d", &year, &month);//2008 8
//	int days = get_days_of_month(year, month);
//	printf("%d\n", days);
//	return 0;
//}
//
//

//#include <string.h>
//
//int main()
//{
//	printf("%d\n", strlen("abcdef"));
//
//	return 0;
//}
//


//#include <stdio.h>
//int main()
//{
//    printf("%d", printf("%d ", printf("%d ", 43)));
//    //printf("%d\n", 100);
//
//    return 0;
//}
//

//
//#include <stdbool.h>
//
//_Bool is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//	{
//		return true;//���귵��1
//	}
//	else
//	{
//		return false;//�������귵��0
//	}
//}
//
//int main()
//{
//	int y = 0;
//	scanf("%d", &y);
//	bool ret = is_leap_year(y);
//	if (ret)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
//}



//��������
//���Ǹ��߱�������������ʲô������������ʲô������������ʲô
//

//int is_leap_year(int y);
//
//int main()
//{
//    int y = 0;
//    scanf("%d", &y);
//    int r = is_leap_year(y);//��������
//    if (r == 1)
//        printf("����\n");
//    else
//        printf("������\n");
//
//	return 0;
//}
//
////�����Ķ���
//int is_leap_year(int y)
//{
//    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//        return 1;
//    else
//        return 0;
//}


//�ӷ�

//#include "add.h"
//
////���뾲̬��(�˽����)
//#pragma comment(lib, "add.lib") 
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = Add(a, b);
//	printf("%d\n", ret);
//
//	return 0;
//}
//
//
//int a = 10;//ȫ�ֱ���
//
//void test()
//{
//
//}
//
//int main()
//{
//	{
//		printf("1: a = %d\n", a);
//	}
//
//	printf("2: a = %d\n", a);
//
//	return 0;
//}


//int a = 0;
//
//int main()
//{
//	//
//	{
//		//...
//		printf("1: a = %d\n", a);
//	}
//
//	printf("2: a = %d\n", a);
//	//
//	return 0;
//}
//������������� == main��������������

#include <stdio.h>
//static ���ξֲ�����
//void test()
//{
//    static int n = 0;
//    n++;
//    printf("%d ", n);
//}
//
//int main()
//{
//    int i = 0;
//    for (i = 0; i < 5; i++)//5��
//    {
//        test();
//    }
//    return 0;
//}
//


//����
//extern �����������ⲿ���ŵ�

//extern int g_val;
//
//int main()
//{
//	printf("%d\n", g_val);
//
//	return 0;
//}
//


//#include <stdio.h>
//
//extern int Add(int x, int y);
//
//int main()
//{
//    printf("%d\n", Add(7, 3));
//    return 0;
//}
//
//

