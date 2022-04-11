#include <bits/stdc++.h>
using namespace std;
const int MIN=-10000000;
int main(){
	int N;
    cin >> N;
	bool visit[N+1];
	int dis[N+1];
	for(int i=1; i <=N; i++)
	{
		dis[i] = MIN;
	}
	memset(visit,0,sizeof(visit));
	int find[N+1];
	int vde;
	int **arc = new int*[N+1];
	int count = 0;
	for(int i = 0; i < N+1; i++)
	{
		arc[i] = new int[N+1];
		for(int k = 0; k < N+1; k++)
		{
			arc[i][k] = MIN;
		}
	}
	for(int i = 1; i <= N; i++)
	{
		int edgenum;
		cin >> edgenum;
		for(int j = 0; j < edgenum; j++)
		{
			int v, w;
			cin >> v >> w;
			arc[i][v] = w;
			find[v] = 1;
		}
	}
	int E;
	 cin >> E;
	for(int i = 1; i < N+1; i++)
	{
		if(find[i]!=1)
		{
			vde = i;
			visit[vde] = 1;
			break;
		}
	}
	int now_visit = vde;
	dis[vde] = 0;
	while(count < N)
	{
		int min = MIN;
		int vmin;
		for(int i = 1; i <= N; i++)
		{
			if(dis[i] < dis[now_visit]+arc[now_visit][i])
			{
				dis[i] = dis[now_visit]+arc[now_visit][i];
				if(visit[1]==1)
				{
					visit[i] = 0;
					count--;
				}
			}
		}
		for(int i = 1; i <= N; i++)
		{
			if(visit[i]==0&&dis[i] > min)
			{
				min= dis[i];
				vmin = i;
			}
		}
		now_visit = vmin;
		visit[now_visit] = 1;
		count++;
	}
	for(int i = 1; i <=N; i++)
	{
		if(E+dis[i]>=0)
		{
			cout << i << endl;
		}
	}
}

