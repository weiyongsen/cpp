#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int n,tot=0;
int col[15]={0};//每一行的棋子的列数
bool check(int c,int r){
	for(int i=0;i<r;i++){
		if(col[i]==c||(abs(col[i]-c)==abs(i-r)))//保证棋子位置合法
		return false;
	}
	return true;
}
void dfs(int r){//深度优先搜索
	if(r==n){//所有的都放好
		tot++;//解的个数加一
		if(tot<=3){//打印前三个解
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
	for(int i=1;i<=n;i++){//没有放好，则检查是否合法
		if(check(i,r)){//如果合法
			col[r]=i;//放置棋子
			dfs(r+1);//继续放下一行
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
