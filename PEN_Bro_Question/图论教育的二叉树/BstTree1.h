#pragma once //防止头文件被重复引用
#ifndef BSTTREE_H
#define BSTTREE_H
//宏    结构体设计   函数声明
#define		TRUE	   1
#define		FASLE	   0
#define     OUTMEMERR  -1

typedef int Status; //状态   1  0  -1
typedef int ElemType; //元素类型

typedef struct BinarySearchNode
{
	ElemType data;
	BstNode* leftchild;
	BstNode* rightchild;
	BstNode* parent;
}BstNode, * BstTree;

//函数声明
Status CreateTree(BstTree* ptree, ElemType* arr);

void FreeNode(BstNode* pnode);

void DestoryTree(BstTree* ptree);

void DeleteVal(BstTree* ptree, ElemType val);

BstNode* SearchVal(BstNode* pnode, ElemType val);

Status ChangeVal(BstNode* pnode, ElemType val, ElemType newval);

//中序遍历 递归 + 非递归
// 逆中序遍历非递归
void InOrder(BstNode* pnode);  //递归中序


void NiceInOrder(BstNode* pnode); //非递归中序   ---递增

//递减序列
void ReverseNiceInOrder(BstNode* pnode); //非递归逆中序遍历

#endif // !BSTTREE_H