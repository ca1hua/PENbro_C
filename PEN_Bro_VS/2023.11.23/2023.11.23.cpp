#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;//c=6
//	b = ++c, c++, ++a, a++;
//	b = b + a++ + c;
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}

//pow(n,2);
//important   /  %
//int main()
//{
//	float m = 6 / 4;
//	printf("%f\n",  m);//默认六位
//	printf("%f",6/4);  /*整数之后的商；*/
//}//bug？

//非要放，就会截断

 //%是不能对int以外的值求
//负数求模的规则是，结果的正负号由第⼀个运算数的正负号决定。
//int main()
//{
//	printf("%d\n", 11 % -5); // 1
//	printf("%d\n", -11 % -5); // -1
//	printf("%d\n", -11 % 5); // -1
//	return 0;
//}

//int main()
//{
//	
//	//连续赋值
//	c = b = a + 3;//连续赋值，从右向左依次赋值的。
//	return 0;
//}

//int main()
//{
//	int a = -10;
//	printf("%d\n", -a);
//	return 0;
//}

//int main()
//{
//	int a = (int)3.14;
//	printf("%d\n", a);
//	//5.5
//	//6.7
//	return 0;
//}


//int main()
//{
//	printf("%s says it is %d o'clock\n", "lisi");
//	return 0;
//}
//printf() 参数与占位符是⼀⼀对应关系，如果有 n 个占位符， printf() 的参数就应该有 n + 
//1 个。如果参数个数少于对应的占位符， printf() 可能会输出内存中的任意值。
//%a ：⼗六进制浮点数，字⺟输出为⼩写。
//•% A ：⼗六进制浮点数，字⺟输出为⼤写。
//•% c ：字符。
//•% d ：⼗进制整数。
//•% e ：使⽤科学计数法的浮点数，指数部分的 e 为⼩写。
//•% E ：使⽤科学计数法的浮点数，指数部分的 E 为⼤写。
//•% i ：整数，基本等同于% d 。
//•% f ：⼩数（包含 float 类型和 double 类型）。
//•% g ：6个有效数字的浮点数。整数部分⼀旦超过6位，就会⾃动转为科学计数法，指数部分的 e
//为⼩写。
//•% G ：等同于% g ，唯⼀的区别是指数部分的 E 为⼤写。
//•% hd ：⼗进制 short int 类型。
//•% ho ：⼋进制 short int 类型。
//•% hx ：⼗六进制 short int 类型。
//•% hu ：unsigned short int 类型。
//•% ld ：⼗进制 long int 类型。
//•% lo ：⼋进制 long int 类型。
//•% lx ：⼗六进制 long int 类型。
//•% lu ：unsigned long int 类型。
//•% lld ：⼗进制 long long int 类型。
//•% llo ：⼋进制 long long int 类型。
//•% llx ：⼗六进制 long long int 类型。
//•% llu ：unsigned long long int 类型。
//•% Le ：科学计数法表⽰的 long double 类型浮点数。
//•% Lf ：long double 类型浮点数。
//•% n ：已输出的字符串数量。该占位符本⾝不输出，只将值存储在指定变量之中。
//• % o ：⼋进制整数。
//•% p ：指针。
//•% s ：字符串。
//•% u ：⽆符号整数（unsigned int）。
//•% x ：⼗六进制整数。
//•% zd ： size_t 类型。
//•%% ：输出⼀个百分号。


//限制最小宽度
//int main()
//{
//	printf("%d\n", 123);
//	    printf("%5d\n", 123);//右对齐//默认
//	    printf("%5d\n", 1234567);//右对齐
//	    printf("%-5dhehe\n", 123);//左对齐
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    printf("%12f\n", 123.45);//小数点也算
//    return 0;
//}


//int main()
//{
//	printf("%+d\n", 10);
//	printf("%+d\n", -10);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    printf("Number is %.2f\n", 5.2678);//会四舍五入
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    printf("%6.2f\n", 123456.5);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    printf("%*.*f\n", 8, 2, 0.5);//可传参
//    return 0;
//}



//                SCANF
//int main()
//{
//	int score = 0;
//	printf("请输入成绩:");
//	//输入
//	scanf("%d", &score);//提供的是地址，必需要
//	printf("%d", score);
//
//	return 0;
//}

//scanf有危险，不检查数组越界
//#include <stdio.h>
//int main()
//{
//	int score = 0;
//	printf("请输成绩:");
//	scanf("%d", &score);
//	printf("成绩是：%d\n", score);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	float f = 0.0f;
//	int r = scanf("%d %d %f", &a, &b, &f);
//	printf("a=%d b=%d f=%f\n", a, b, f);
//	printf("r = %d\n", r);
//	return 0;
//}
////提前结束scanf  ctrl Z
////EOF -1 读取失败
//


//int main()
//{
//	int a = 10;
//	char ch = '0';
//	//scanf("%d", &a);
//	//printf("%d\n", a);
//
//	scanf(" %c", &ch);//%号前加空格
//	printf("%cxxxxx", ch);
//
//	return 0;
//}

//%s遇到空格就结束了，且会放\0

#include <stdio.h>

int main()
{
    int year = 0;
    int month = 0;
    int day = 0;

    //scanf("%d-%d-%d", &year, &month, &day);
    //2023-11-22
    scanf("%d%*c%d%*c%d", &year, &month, &day);
    printf("%d %d %d\n", year, month, day);
    return 0;
}
