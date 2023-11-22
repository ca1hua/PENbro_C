#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//
//int main() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d %d", a / b, a % b);
//    return 0;
//}

#include <stdio.h>
//int num = 10;
//int main()
//{
//    int num = 1;//先是这个
//    printf("num = %d\n", num);
//    return 0;
//}

//int main()
//{
//	printf("%c",'\130');
//	printf("%c", '\x30');
//	//          \ddd   \130就是八进制表示ASCll码
//}
#include <string.h>
//int main()
//{
//	int len = strlen("abc");
//	printf("%d\n", len);
//	//转义字符就是会
//	//        strlen 求的是\0之前的字符说
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++) //for循环的循环体的⼤括号中的就是复合语句
//	{
//		arr[i] = 10 - i;
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}


//C语言是一种结构话=化的程序设计语言

//int main()
//{
//	/*
//	是大陆空军，我jdalFLAG{多行}
//	dfa
//	fdsjh
//	da
//	*/          //不支持嵌套的
//	return 0;
//}

// 注释会被替换为空格

         /*数据类型*/
// char  int,shrot,long    float,double  _Bool
//  unsigned 无符号

#include <stdbool.h>
//    int main()
//{
//    printf("%zd\n", sizeof(char));//1              //%zd  
//    printf("%zd\n", sizeof(bool));//2              //0表示假，其他都是真
//    printf("%zd\n", sizeof(short));//2
//    printf("%zd\n", sizeof(int));//4
//    printf("%zd\n", sizeof(long));//4             //有的是8
//    printf("%zd\n", sizeof(long long));//8
//    printf("%zd\n", sizeof(float));//4
//    printf("%zd\n", sizeof(double));//8
//    printf("%zd\n", sizeof(long double));//8
//    return 0;
//}
//    /*sizeof(可以放变量，也可以放类型)*/
//
//   // 字节   bit Byte//字节=八个bit    1KB=1024个Byte     MB...

//int main()
//{
//	int a = 10;
//	short s = 4;
//	printf("%zd\n", sizeof(s = a + 5));//不会算的
// //zd  专门来给    size_t   这个类型的
//	printf("s = %d\n", s);
//
//	return 0;
//}

//int mian()
//{
//    int a;
//    printf("s = %u\n", a);
//    return 0;
//}
//%d是有符号的打印
//%u是无符号的整数       advantage:  max double of signed bit


//    for char:  signed char   !=    unsigned char    This decided by compiler
//    short age





//int a    整型   数据类型 创建变量

//int a = 1000;//全局变量,可以不初始化，是0
//
//int main()
//{
//    int a = 0;//局部 
//    //先局部，在全局
//    //全局不能用局部
//    printf("%d",a);
//    return 0;
//}


//局部，全局       在栈区，堆区，静态区
// 
// 局部变量是放在内存的栈区
// 全局变量是放在内存的静态区  
// 堆区是用来动态内存管理的

int main()
{
    printf("%d\n", strlen("c:\test\121"));
    return 0;
}