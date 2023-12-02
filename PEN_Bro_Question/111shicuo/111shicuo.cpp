#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
#include <string.h>
#define  N  50
#define  M  2*N-1
typedef  struct
{
    char data[5];
    int  weight;
    int  parent;
    int  lchild;
    int  rchild;
} HTNode;
typedef  struct {
    char  cd[N];
    int   start;
}HCode;
void  CreatHT(HTNode  ht[], int n)
{
    int  i, k, lnode, rnode;
    int  min1, min2;
    for (i = 0; i < 2 * n - 1; i++)
        Ht[i].parent = ht[i].lchild = ht[i].rchild = 0
        for (i = n; i < 2 * n - 1; i++)
        {
            min1 = min2 = 32767;
            lnode = rnode = 0
                for (k = 0; k <= i - 1; k++)
                    if (ht[k].parent == 0)
                        £ûif(ht[k].weight < min1)
                    {
                        min2 = min1; rnode = lnode;
                        min1 = ht[k].weight; lnode = k;
                    }
                    else if (ht[k].weight < min2)
                    {
                        min2 = ht[k].weight; rnode = k;
                    }
            £ý
                ht[lnode].parent = i; ht[rnode].parent = i;
            ht[i].weight = ht[lnode].weight + ht[rnode].weight;
            ht[i].lchild = lnode; ht[i].rchild = rnode;
        }
}
void CreatHCode(HTNode ht[], HCode[]; int n)
{
    int  i, f, c;
    HCode  hc;
    for (i = 0; i < n; i++)
        £û hc.start = n; c = i;
    f = ht[i].parent;
    while (f != 0)
    {
        if (ht[f].lchild == c)
            Hc.cd[hc.start--] = ¡¯0¡¯;
        else
            Hc.cd[hc.start--] = ¡¯1¡¯;
        c = f; f = ht[f].parent;
    }
    hc.start++;
    hcd[i] = hc;
}
}
void  DispHCode(HTNode ht[], HCode hcd[], int n)
{
    Int i, k;
    Int  sum = 0, m = 0, j;
    printf(¡°Êä³ö¹þ·òÂü±àÂë£º\n¡±);
    for (i = 0; i < n; i++)
    {
        j = 0;
        printf(¡° % s:\t¡±, ht[i].data);
        for (k = hcd[i].start; k <= n; k++)
        {
            printf(¡° % c¡±, hcd[i].cd[k]);
            j++;
        }
    }
    void  main()
        £û int  n = 8, i;
    char* str[] = { ¡°a¡±, ¡°b¡±, ¡°c¡±, ¡°d¡±, ¡°e¡±, ¡°f¡±, ¡°g¡±, ¡°h¡± };
    int  fnum[] = { 7,19,2,6,32,3,21,10 };
    HTNode  ht[M];
    HCode  hcd[N];
    for (i = 0; i < n; i++)
    {
        strcpy(ht[i].data, str[i]);
        Ht[i].weight = fnum[i];
    }
    printf(¡°\n¡±);
    CreateHT(ht, n);
    CreateHCode(ht, hcd, n);
    DispHCode(ht, hcd, n);
    printf(¡°\n¡±);
}

