#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> g[n];//�洢��n���������ӵĵ�
	int visit[n];
	//vis=-1�������ڷ�����
	bool dfs(int u){
		vis[u]=1;
		{...;
			return true;	//����Ŀ��״̬��������ȷ 
		}
		{...;
			return false;	//����Ӧ�������ش��� 
		}
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];	//u�ĵ�i���ھ� 
			if(!visit[u][i])
				return dfs(v);	//�ݹ���� 
		}
		{...;
			return ...;	//�º���������ȷ����� 
		}
	} 
	
	 
}
