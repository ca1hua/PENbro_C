#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu
{
    int ID;
    int math;
    int English;
    int C;
    int avargrade;
    char name[20];
}Stu;


int main()
{
    FILE* fp;
    Stu stu[5];
    int i, avargrade = 0;
    printf("������5��ͬѧ����Ϣ��ѧ���ţ�������3�ųɼ�:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d %s %d %d %d", &(stu[i].ID), stu[i].name, &(stu[i].math), &(stu[i].English), &(stu[i].C));
        stu[i].avargrade = (stu[i].math + stu[i].English + stu[i].C) / 3;
    }
    if ((fp = fopen("stud", "w")) == NULL)
    {
        printf("error :cannot open file!\n");
        exit(0);
    }
    for (i = 0; i < 5; i++)
        fprintf(fp, "%d %s %d %d %d %d\n", stu[i].ID, stu[i].name, stu[i].math, stu[i].English,
            stu[i].C, stu[i].avargrade);
    fclose(fp);
	return 0;
}