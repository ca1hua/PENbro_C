//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
////神头鬼脸的这个代码就通过了...
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int x = 1, y = 0;        // x 用来控制当前位于哪一位
//    while (x < n)
//    {
//        y += (n / x % 2) * x;        // x 从1开始,等于从个位开始往上依次摩2,得到奇偶性之后再乘 x 即当前这个位数的0或者1      比如 1+10+100 一直加到加不了
//        x *= 10;
//    }printf("%d", y);
//    return 0;
//}