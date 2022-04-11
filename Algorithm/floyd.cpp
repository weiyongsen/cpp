#include <bits/stdc++.h>
using namespace std;
const int INF=1e6;
const int NUM=105;
int graph[NUM][NUM];
int n,m;
void floyd(){
	int s=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(graph[i][k]!=INF)
				for(int j=0;j<n;j++)
					if(graph[i][j]>graph[i][k]+graph[k][j])
						graph[i][j]=graph[i][k]+graph[k][j];
	printf("%d\n",graph[s][n]);
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0)
			return 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				graph[i][j]=INF;
		while(m--){
			int a,dis,c;
			scanf("%d%d%d",&a,&dis,&c);
			graph[a][dis]=graph[dis][a]=c;
		}
		floyd();		
	}
	return 0;
}
	
				
	
