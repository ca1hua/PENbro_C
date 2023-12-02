#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//void han(int n,char begin,char mid,char end)
//{
//	if (n == 1)
//	{
//		printf("%c->%c\n", begin, end);
//	}
//	else
//	{
//		han(n-1, begin, end, mid);
//		printf("%c->%c\n", begin, end);
//		han(n-1, mid,begin, end);
//	}
//}
//
//int main()
//{
//	han(3,'X','Y','Z');
//
//}



//int main()
//{
//	char ch = 'a';
//	scanf("% c",&ch);
//	printf("%c",ch);
//	return 0;
//}
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	for (a = 1, b = 1; a <= 100; a++)
	{
		if (b >= 20) break;
		if (b % 3 == 1)
		{
			b = b + 3;
			continue;
		}
		b = b - 5;
	}
	printf("%d\n", a);
	return 0;
}