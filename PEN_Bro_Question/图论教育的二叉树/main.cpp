#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "BstTree1.h"
#include <cassert>

//函数声明
Status CreateTree(BstTree* ptree, ElemType* arr);

void FreeNode(BstNode* pnode);

void DestoryTree(BstTree* ptree);

void DeleteVal(BstTree* ptree, ElemType val);

BstNode* SearchVal(BstNode* pnode, ElemType val)
{
	if (pnode == NULL)  //若树为空
	{
		return NULL;
	}
	BstNode* p = pnode;
	while (p != NULL && p->data != val)
	{
		p = val < p->data ? p->leftchild : p->rightchild;
	}
	return p;
}

Status ChangeVal(BstNode* pnode, ElemType val, ElemType newval);

//中序遍历 递归 + 非递归
// 逆中序遍历非递归
void InOrder(BstNode* pnode);  //递归中序
void NiceInOrder(BstNode* pnode); //非递归中序   ---递增

//递减序列
void ReverseNiceInOrder(BstNode* pnode); //非递归逆中序遍历