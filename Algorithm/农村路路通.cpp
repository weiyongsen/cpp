#include <bits/stdc++.h>
using namespace std;
const int num=1003;
int S[num];

struct Edge{int u,v,w;
}
edge[num*num];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	while(1) {
  	if (x==S[x]) 
        return x;
  	x=S[x];
  }
}
int n,m;
int kruskal(){
	int ans=0;
	for(int i=1;i<=n;i++)
		S[i]=i;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++){
		int b=find(edge[i].u);
		int c=find(edge[i].v);
		if(b==c)
			continue;
		S[c]=b;
		ans+=edge[i].w;
	}
	return ans;
}
void lianjie(int a,int b) {
	int x,y;
	x=find(a);
	y=find(b);
	if (x!=y) {
		S[y]=x;
	}
}
int main(){
	int s=0,t=0;
	cin >> n >> m; 
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		for (int i=0;i<m&&t<=n-1;i++) {
		if (find(edge[i].u)!=find(edge[i].v)) {
			lianjie(edge[i].u,edge[i].v);
			s=s+edge[i].w;
			t++;
		}	
	}
	if (t<n-1) 
		printf ("-1\n");
	else
		printf("%d\n",s);
	return 0;
}
