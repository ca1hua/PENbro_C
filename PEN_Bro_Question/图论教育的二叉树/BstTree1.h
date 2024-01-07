#pragma once //��ֹͷ�ļ����ظ�����
#ifndef BSTTREE_H
#define BSTTREE_H
//��    �ṹ�����   ��������
#define		TRUE	   1
#define		FASLE	   0
#define     OUTMEMERR  -1

typedef int Status; //״̬   1  0  -1
typedef int ElemType; //Ԫ������

typedef struct BinarySearchNode
{
	ElemType data;
	BstNode* leftchild;
	BstNode* rightchild;
	BstNode* parent;
}BstNode, * BstTree;

//��������
Status CreateTree(BstTree* ptree, ElemType* arr);

void FreeNode(BstNode* pnode);

void DestoryTree(BstTree* ptree);

void DeleteVal(BstTree* ptree, ElemType val);

BstNode* SearchVal(BstNode* pnode, ElemType val);

Status ChangeVal(BstNode* pnode, ElemType val, ElemType newval);

//������� �ݹ� + �ǵݹ�
// ����������ǵݹ�
void InOrder(BstNode* pnode);  //�ݹ�����


void NiceInOrder(BstNode* pnode); //�ǵݹ�����   ---����

//�ݼ�����
void ReverseNiceInOrder(BstNode* pnode); //�ǵݹ����������

#endif // !BSTTREE_H