#include <bits/stdc++.h>
using namespace std;
typedef struct node *AVLNode;
struct node{
	AVLNode lchild,rchild;
	int Data;
}; 
int GetHeight(AVLNode A) 
{
	if(!A)
		return 0;
	int L=GetHeight(A->lchild);
	int R=GetHeight(A->rchild);
	return (L>R? L:R)+1;
}
AVLNode SingleRightRotation(AVLNode A);
AVLNode SingleRightRotation(AVLNode A)
{
	AVLNode B=A->rchild;
	A->rchild=B->lchild;
	B->lchild=A;
	return B;
}
AVLNode SingleLeftRotation(AVLNode A);
AVLNode SingleLeftRotation(AVLNode A)
{
	AVLNode B=A->lchild;
	A->lchild=B->rchild;
	B->rchild=A;
	return B;
}
AVLNode DoubleRightLeftRotation(AVLNode A);
AVLNode DoubleRightLeftRotation(AVLNode A)
{
	A->lchild=SingleLeftRotation(A->lchild);
	return SingleRightRotation(A);
}
AVLNode DoubleLeftRightRotation(AVLNode A);
AVLNode DoubleLeftRightRotation(AVLNode A)
{
	A->rchild=SingleRightRotation(A->rchild);
	return SingleLeftRotation(A);
}
AVLNode InsertAVL(AVLNode A,int x);
AVLNode InsertAVL(AVLNode A,int x)
{
	if(!A)
	{
		A=new node;
		A->Data=x;
		A->lchild=A->rchild=NULL;
	}
	else if(A->Data<x)
	{
		A->rchild=InsertAVL(A->rchild,x);
		if(GetHeight(A->rchild)-GetHeight(A->lchild)==2)
		{
			if(A->rchild->Data<x)	A=SingleRightRotation(A);
			else A=DoubleRightLeftRotation(A);
		}
	}
	else if(A->Data>x)
	{
		A->lchild=InsertAVL(A->lchild,x);
		if(GetHeight(A->lchild)-GetHeight(A->rchild)==2)
		{
			if(x<A->lchild->Data)	A=SingleLeftRotation(A);
			else A=DoubleLeftRightRotation(A);
		}
	}
	return A;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,x;
	AVLNode A=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		A=InsertAVL(A,x);
	}
	printf("%d",A->Data);
	return 0;
}

