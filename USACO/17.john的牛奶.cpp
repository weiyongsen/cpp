#include<cstdio>
#include<stack>
#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>
#include<set>
#include<string>
#include<cstring> 
#include<map>
#include<vector>
const int inf=2e9;
using namespace std;
int n;
int b[3];//容量上限 
bool vis[3][3];//vis[i][j]==1表示从i倒给j
int milk[1000];
int mind(int p,int q){
	if(p<q) return p;
	else return q;
}
bool kkk[25][25][25];
void dfs(int a[],int k){
	//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	if(kkk[a[0]][a[1]][a[2]]) return ;//已经搜过这种情况，则返回
	kkk[a[0]][a[1]][a[2]]=1;//标记这种情况
	if(k>=50) return ;//深度超过50，则返回
	if(a[0]==0){
		if(milk[a[2]]) return;
		else {
			milk[a[2]]=1;
			//cout<<a[2]<<" ";
		}
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if( i!=j && (!vis[i][j]) && (!vis[j][i]) ){//i到给j
				int minx=mind(a[i],b[j]-a[j]);
				a[i]-=minx;
				a[j]+=minx;
				vis[i][j]=1;
				//cout<<minx<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
				dfs(a,k+1);
				a[i]+=minx;//回溯
				a[j]-=minx;
				vis[i][j]=0;
			}
			else{
				if( i!=j && (vis[i][j]) || (vis[j][i]) ){
					vis[i][j]=vis[j][i]=0;
				}
			}
		}
	}
	
}
int main(){
	int a[3]={0,0,0};
	cin>>b[0]>>b[1]>>b[2];
	a[2]=b[2];
	//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	dfs(a,0);
	int flag=1;
	for(int i=0;i<=b[2];++i) {
		if(milk[i]){
			if(flag) flag=0;
			else{
				cout<<" ";
			}
			cout<<i;
		}
	}
    return 0;
}
