/*
����������Ľ��������������������������
����������
9
1 2 4 7 3 5 8 9 6
4 7 2 1 8 5 9 3 6
���������
7 4 2 8 9 5 6 3 1
*/

#include <bits/stdc++.h>
using namespace std;
const int N =1010;
int pre[N],in[N],post[N];
int k;
struct node {
	int value;
	node *l, *r;
	node (int value=0,node *l=NULL,node *r=NULL):value(value),l(l),r(r){}
};
void buildtree(int l, int r, int &t, node* &root){	//���� 
	int flag=-1;
	for(int i=l;i<=r;i++)
		if(in[i]==pre[t]){
			flag=i;
			break;
		}
	if(flag==-1)
		return ;
	root = new node (in[flag]);			//�½���� 
	t++;
	if(flag>1)
		buildtree(l,flag-1,t,root->l);
		buildtree(flag+1,r,t,root->r);
}
void preorder(node *root){			//������� 
	if(root != NULL){
		post[k++]=root->value;
		preorder(root->l);
		preorder(root->r);
	}
}
void inorder(node *root){			//������� 
	if(root !=NULL){
		inorder(root->l);
		post[k++]=root->value;
		inorder(root->r);
	}
}
void postorder(node *root){			//������� 
	if(root != NULL){
		postorder(root->l);
		postorder(root->r);
		post[k++]=root->value;
	}
}
void remove_tree(node *root){		//�ͷſռ� 
	if(root==NULL)
		return ;
	remove_tree(root->l);
	remove_tree(root->r);
	delete root;
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&pre[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&in[j]);
		node *root;
		int t=1;
		buildtree(1,n,t,root);
		k=0;
		postorder(root);			//����������˴��ɸĺ���Ϊpreorder��inorder 
		for(int i=0;i<k;i++)
			printf("%d%c",post[i],i==k-1?'\n':' ');
		remove_tree(root);
	}
	return 0;
}
