#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int n,tot=0;
int col[15]={0};//ÿһ�е����ӵ�����
bool check(int c,int r){
	for(int i=0;i<r;i++){
		if(col[i]==c||(abs(col[i]-c)==abs(i-r)))//��֤����λ�úϷ�
		return false;
	}
	return true;
}
void dfs(int r){//�����������
	if(r==n){//���еĶ��ź�
		tot++;//��ĸ�����һ
		if(tot<=3){//��ӡǰ������
			for(int i=0;i<n;i++){
				printf("%d",col[i]);
				if(i!=n-1)
					printf(" ");
				else
					printf("\n"); 
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){//û�зźã������Ƿ�Ϸ�
		if(check(i,r)){//����Ϸ�
			col[r]=i;//��������
			dfs(r+1);//��������һ��
		}
	}
}
int main()
{
 	memset(col,0,sizeof(col));
	scanf("%d",&n);
 	dfs(0);
 	printf("%d",tot);
   	return 0;
}
