//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//int Count;
//
//struct student {
//    char sno[20], name[20];
//    int math, english, chinese, sum;
//};
//
//struct student cha[10];
//
//void print(struct student stu) {
//    printf("%s %s %d %d %d %d\n", stu.sno, stu.name, stu.math, stu.english, stu.chinese, stu.sum);
//}
//
//int chaCount = 0; // 追踪 cha 数组中已填充的元素数量
//
//void query_stu(struct student s[], char* name) {
//    chaCount = 0; // 每次查询时重置 chaCount
//    for (int i = 0; i < Count; i++) {
//        if (strcmp(s[i].name, name) == 0) {
//            cha[chaCount++] = s[i]; // 使用 chaCount 作为索引
//        }
//    }
//}
//
//void delete_stu(struct student s[], char* sno) {
//    for (int i = 0; i < Count; i++) {
//        if (strcmp(s[i].sno, sno) == 0) {
//            for (int j = i; j < Count - 1; j++) {
//                s[j] = s[j + 1];
//            }
//            Count--;
//            return;
//        }
//    }
//}
//
//void update_stu(struct student s[], char* sno, int math, int english, int chinese) {
//    for (int i = 0; i < Count; i++) {
//        if (strcmp(s[i].sno, sno) == 0) {
//            s[i].math = math;
//            s[i].english = english;
//            s[i].chinese = chinese;
//            s[i].sum = math + english + chinese;
//            return;
//        }
//    }
//}
//
//int main(void) {
//    int n, q;
//    struct student students[50];
//    struct student two[50];
//    scanf("%d%d", &n, &q);
//    Count = n;
//    for (int i = 0; i < n; i++) {
//        scanf("%s%s%d%d%d", students[i].sno, students[i].name, &students[i].math, &students[i].english, &students[i].chinese);
//        students[i].sum = students[i].math + students[i].english + students[i].chinese;
//    }
//
//    struct student updated_students[50];
//    memcpy(updated_students, students, sizeof(students)); // 复制学生信息到另一个数组中
//
//    while (q--) {
//        int op;
//        scanf("%d", &op);
//        char sno[20], name[20];
//        if (op == 1) {
//            scanf("%s", name);
//            query_stu(updated_students, name);
//             
//        }
//        else if (op == 2) {
//            int a, b, c;
//            scanf("%s%d%d%d", sno, &a, &b, &c);
//            update_stu(updated_students, sno, a, b, c);
//            for (int i = 0; i < 10; i++) {
//                two[i]= updated_students[i];
//            }
//        }
//        else {
//            scanf("%s", sno);
//            delete_stu(updated_students, sno);
//        }
//    }
//    
//    for (int i = 0; i < chaCount; i++) {
//        print(cha[i]);
//    }
//    for (int i = 0; i < 10; i++) {
//        print(two[i]);
//    }
//
//
//    for (int i = 0; i < Count; i++) {
//        print(updated_students[i]);
//    }
//
//    return 0;
//}
//
//
//
//
//
//
////10 3
////1 Siyu 90 90 90
////2 Amy 60 70 94
////3 Jack 60 60 98
////4 Jack 77 90 60
////5 Banana 60 60 40
////6 White 60 60 60
////7 Pinkman 60 60 60
////8 Fring 60 60 70
////9 Ehrmantraut 80 63 61
////10 Schrader 99 66 100
////1 Jack
////2 1 100 100 100
////3 10