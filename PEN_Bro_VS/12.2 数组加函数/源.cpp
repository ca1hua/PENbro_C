#define _CRT_SECURE_NO_WARNINGS 1
//�������Բ���������������һ��Ҫ��
//%p ��ӡ��ַ
#include <stdio.h>

//int main() 
//{
//	char ch[5][8];
//	float math[4][20];
//
//	return 0;
//}

//int main()
//{
//	//int data[3][5] = {1,2,3};
//	//int data[3][5] = {0};
//	//int data[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	//int data[3][5] = { {1,2},{3,4}, {5,6} };
//	int arr5[][5] = { 1,2,3 };//1��
//	int arr6[][5] = { 1,2,3,4,5,6,7 };//2��
//	int arr7[][5] = { {1,2}, {3,4}, {5,6} };//
//
//	return 0;
//}

//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	printf("%d\n", arr[1][3]);
//	return 0;
//}

//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	//��ӡ����Ԫ��
//	int i = 0;//��
//	for (i = 0; i < 3; i++)
//	{
//		//��
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[3][5] = { 0 };
//	//����ֵ
//	int i = 0;//��
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	//��ӡ����Ԫ��
//	for (i = 0; i < 3; i++)
//	{
//		//��
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//

//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//	//��ӡ����Ԫ��
//	int i = 0;//��
//	for (i = 0; i < 5; i++)
//	{
//		//��
//		int j = 0;
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[3][5] = {0};
//	//������ÿ��Ԫ�صĵ�ַ��ӡ����
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("&arr[%d][%d] = %p\n",i,j, &arr[i][j]);
//		}
//	}
//	return 0;
//}
//
//
//

//C99֮ǰ����Ĵ�Сֻ��ʹ�ó������߳������ʽָ��
//int main()
//{
//	int arr1[5];
//	int arr2[3 + 5];
//	int arr3[8];
//	int arr4[] = { 1,2,3,4 };
//	int arr5[] = { 0 };//
//#define n 10
//
//	int arr6[n];//����ʹ�ñ���
//
//	return 0;
//}
//��C99�������˱䳤����ĸ����ʱ���������ʱ�����ʹ�ñ�����ָ����С
//�����ź���ʱVS�в�֧�ֱ䳤����
//
//С��èC++ ʹ����gcc���������
//gcc ��֧�ֱ䳤�����
//

//welcome to bit!!!!!!
//********************
//w******************!
//we****************!!
//wel**************!!!
//...
//welcome to bit!!!!!!
//
//
//#include <string.h>
//#include <windows.h>
//#include <stdlib.h>
//
//int main()
//{
//	//char arr[] = "abc";//[a b c \0] 
//	//                      0 1 2
//	//
//	char arr1[] = "welcome to bit!!!!!!";
//	char arr2[] = "********************";
//
//	int left = 0;
//	int right = strlen(arr1)-1;
//
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(100);//��λ�Ǻ���
//		system("cls");//������Ļ�ϵ���Ϣ
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 17;//�������в���7
//
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int flag = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("�ҵ���,�±���:%d", i);
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("�Ҳ�����\n");
//	}
//	return 0;
//}

//git ѧϰһ��~
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;//�������в���7
//
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int flag = 0;
//
//	int left = 0;
//	int right = sz-1;
//
//	while (left <= right)
//	{
//		//int mid = (left + right) / 2;
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			flag = 1;
//			printf("�ҵ��ˣ��±���%d\n", mid);
//			break;
//		}
//	}
//	if (flag == 0)
//		printf("�Ҳ�����\n");
//
//	return 0;
//}
//




//#include <math.h>
//
//int main()
//{
//	double ret = sqrt(100);
//	printf("%lf\n", ret);
//	return 0;
//}
//


//
//int main()
//{
//	char arr[] = "abcdef";//[a b c d e f \0]
//	//                       0 1 2 3 4 5
//	//
//	int right1 = strlen(arr)-1;//
//	int right2 = sizeof(arr) / sizeof(arr[0]) - 2;
//	printf("%d\n", right1);
//	printf("%d\n", right2);
//
//}

