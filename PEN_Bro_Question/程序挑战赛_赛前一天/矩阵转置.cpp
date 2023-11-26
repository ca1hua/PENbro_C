//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//#define M 3
//#define N 5
//
//void input(int(*b)[N], int m, int n)
//{
//    int i, j;
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//            scanf("%d", (*(b + i) + j));
//    }
//}
//
//
//void Output2(int(*b)[N], int m, int n)
//{
//    int i, j;
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//            printf("%d ", *(*(b + i) + j));
//        printf("\n");
//    }
//}
//
//void Output1(int(*b)[M], int m, int n)
//{
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//            printf("%d ", *(*(b + i) + j));
//        printf("\n");
//    }
//}
//
//void reverse(int a[][N], int(*b)[M], int m, int n)
//{
//    int i, j;
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//        
//            b[j][i] = a[i][j];
//        }
//    }
//
//}
//
//int main()
//{
//    int a[M][N], b[N][M] = {0};
//    input(a, M, N);
//    Output2(a, M, N);
//    reverse(a, b, M, N);
//    Output1(b, M, N);
//    return 0;
//}