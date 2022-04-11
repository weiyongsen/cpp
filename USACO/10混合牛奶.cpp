#include<cstdio>
#include<stack>
#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
struct node{
	int a;//价格 
	int b;//数量 
}kkk[5005];
bool cmp(node q,node p){
	return q.a<p.a;
}
int main(){
	int n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>kkk[i].a>>kkk[i].b;
	}
	sort(kkk,kkk+m,cmp);
	for(int i=0;i<m;i++){
		if(!n) break;
		if(n>=kkk[i].b){
			n-=kkk[i].b;
			ans+=kkk[i].a*kkk[i].b;
		}
		else{
			ans+=kkk[i].a*n;
			n=0;
		}
	}
	cout<<ans;
	return 0;
}
/*3 10 30
5 20 100
6 30 180
8 80 320*/
