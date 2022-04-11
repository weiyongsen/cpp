#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> g[n];//存储第n个点所连接的点
	int visit[n];
	//vis=-1代表正在访问中
	bool dfs(int u){
		vis[u]=1;
		{...;
			return true;	//出现目标状态，返回正确 
		}
		{...;
			return false;	//做相应处理，返回错误 
		}
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];	//u的第i个邻居 
			if(!visit[u][i])
				return dfs(v);	//递归访问 
		}
		{...;
			return ...;	//事后处理，返回正确或错误 
		}
	} 
	
	 
}
