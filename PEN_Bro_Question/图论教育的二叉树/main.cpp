#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "BstTree1.h"
#include <cassert>

//��������
Status CreateTree(BstTree* ptree, ElemType* arr);

void FreeNode(BstNode* pnode);

void DestoryTree(BstTree* ptree);

void DeleteVal(BstTree* ptree, ElemType val);

BstNode* SearchVal(BstNode* pnode, ElemType val)
{
	if (pnode == NULL)  //����Ϊ��
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

//������� �ݹ� + �ǵݹ�
// ����������ǵݹ�
void InOrder(BstNode* pnode);  //�ݹ�����
void NiceInOrder(BstNode* pnode); //�ǵݹ�����   ---����

//�ݼ�����
void ReverseNiceInOrder(BstNode* pnode); //�ǵݹ����������