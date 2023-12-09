//#define _CRT_SECURE_NO_WARNINGS 1
//#include <string.h>
//#include <stdio.h>
//int main()
//{
//    char arr[100] = { '\0' };
//    gets_s(arr);
//    char arr1[100] = {'\0'};
//    char arr2[100] = { '\0' };
//    int l1, l2, j = 0;
//    int m = strlen(arr);
//    int i = 0;
//    
//
//    for (i = 0; i < m; i = i + 2)
//    {
//
//        arr1[j] = arr[i];
//        j++;
//        l1 = j;
//    }
//    int k = 0;
//    for (i = 1; i < m; i = i + 2)
//    {
//        arr2[k] = arr[i];
//        k++;
//        l2 = k;
//    }
//   
//
//
//    int zhen[100] = { 0 };
//    for (i = 0; i < l1; i++)
//    {
//        zhen[i] = ((int)arr1[i] - 48);
//    }
//    for (i = 0; i < l2; i++)
//    {
//        if (arr2[i] == '+')
//        {
//            zhen[i + 1] = zhen[i] + zhen[i + 1];
//        }
//        else
//        {
//            zhen[i + 1] =  zhen[i]-zhen[i + 1];
//        }
//    }
//    printf("%d", zhen[l2]);
//    return 0;
//}//整数数组存
//
//
////#include <string.h>
////#include <stdio.h>
////int main()
////{
////    int l1 = 0;
////    int zhen[1000] = { 0 };
////    int i = 0, j = 0;
////    while (scanf("%d", &zhen[i]) != EOF)
////    {
////        i++;
////    }
////    l1 = sizeof(zhen) / sizeof(zhen[0]);
////
////    for (i = 0; i < l1; i++)
////    {
////        for (j = 0; j < l1; j++)
////        {
////            int temp;
////            if (zhen[j] < zhen[j + 1])
////            {
////                temp = zhen[j];
////                zhen[j] = zhen[j + 1];
////                zhen[j + 1] = temp;
////            }
////        }
////    }
////    printf("Max=%d", zhen[0]);
////    return 0;
////}
////#define _CRT_SECURE_NO_WARNINGS 1
////#include <string.h>
////#include <stdio.h>
////
////int main()
////{
////    int l1 = 0;
////    int zhen[1000] = { 0 };
////    int i = 0, j = 0;
////    while (scanf("%d", &zhen[i]) != EOF)
////    {
////        i++;
////    }
////    l1 = sizeof(zhen) / sizeof(zhen[0]);//没实现，但是能用
////    for (i = 0; i < l1; i++)
////    {
////        for (j = 0; j < l1; j++)//两个大循环，不管时间复杂度
////        {
////            int temp;
////            if (zhen[j] < zhen[j + 1])
////            {
////                temp = zhen[j];
////                zhen[j] = zhen[j + 1];
////                zhen[j + 1] = temp;
////            }
////        }
////    }
////    printf("Max=%d", zhen[0]);
////    return 0;
////}
//
