//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//    FILE* fa, * fb, * fc;
//    int i, j, k;
//    char str[100], str1[100];
//    char tem;
//    if ((fa = fopen("test", "r")) == NULL) // A.txt �ļ���Ҫ����
//    {
//        printf("error: cannot open A file!\n");
//        exit(0);
//    }
//    fgets(str, 99, fa);
//    fclose(fa);
//    if ((fb = fopen("i am coming", "r")) == NULL)  // B.txt �ļ���Ҫ����
//    {
//        printf("error: cannot open B file!\n");
//        exit(0);
//    }
//    fgets(str1, 100, fb);
//    fclose(fb);
//    strcat(str, str1);
//    for (i = strlen(str) - 1; i > 1; i--)
//        for (j = 0; j < i; j++)
//            if (str[j] > str[j + 1])
//            {
//                tem = str[j];
//                str[j] = str[j + 1];
//                str[j + 1] = tem;
//            }
//
//    if ((fc = fopen("C.txt", "w")) == NULL)  // �ϲ�Ϊ C.txt
//    {
//        printf("error: cannot open C file!\n");
//        exit(0);
//    }
//    fputs(str, fc);
//    fclose(fc);
//    system("pause");
//    return 0;
//}