﻿//#define _CRT_SECURE_NO_WARNINGS 1
////  Created by www.runoob.com on 15/11/9.
////  Copyright © 2015年 菜鸟教程. All rights reserved.
////
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//    FILE* fp = NULL;
//    char str[50];
//    int i, len;
//    printf("输入一个字符串：\n");
//    gets_s(str);
//    len = strlen(str);
//    for (i = 0; i < len; i++)
//    {
//        if (str[i] <= 'z' && str[i] >= 'a')
//            str[i] -= 32;
//    }
//    if ((fp = fopen("test", "w")) == NULL)
//    {
//        printf("error: cannot open file!\n");
//        exit(0);
//    }
//    fprintf(fp, "%s", str);//打印到文件里
//    fclose(fp);
//
//    system("pause");
//    return 0;
//}