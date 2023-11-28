#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int arr[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d",&arr[i]);
	}
	int j;
	int t=arr[0];
	for (i = 0; i <9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (arr[j] < arr[j+1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	printf("%d",arr[0]);
	return 0;
}