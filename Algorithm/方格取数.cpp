#include <bits/stdc++.h>
const int maxn = 200005;
const int maxm = 400005;

using namespace std;
struct Edge
{
	int to, next, cap, flow;
} edge[maxm];


int Q[maxn];
int dep[maxn], cur[maxn], sta[maxn];
int n, m, S, T;
int a[35][35];
int tx[] = {0,0,1,-1};
int ty[] = {1,-1,0,0}; 
int tol;
int head[maxn];

bool bfs(int s, int t, int n)
{
	int front = 0, tail = 0;
	memset(dep, -1, sizeof(dep[0]) * (n + 1));
	dep[s] = 0;
	Q[tail++] = s;
	while (front < tail)
	{
		int u = Q[front++];
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (edge[i].cap > edge[i].flow && dep[v] == -1)
			{
				dep[v] = dep[u] + 1;
				if (v == t)
					return true;
				Q[tail++] = v;
			}
		}
	}
	return false;
}
int dinic(int s, int t, int n)
{
	int maxflow = 0;
	while (bfs(s, t, n))
	{
		for (int i = 0; i < n; i++)
			cur[i] = head[i];
		int u = s, tail = 0;
		while (cur[s] != -1)
		{
			if (u == t)
			{
				int tp = INFINITY;
				for (int i = tail - 1; i >= 0; i--)
					tp = min(tp, edge[sta[i]].cap - edge[sta[i]].flow);
				maxflow += tp;
				for (int i = tail - 1; i >= 0; i--)
				{
					edge[sta[i]].flow += tp;
					edge[sta[i] ^ 1].flow -= tp;
					if (edge[sta[i]].cap - edge[sta[i]].flow == 0)
						tail = i;
				}
				u = edge[sta[tail] ^ 1].to;
			}
			else if (cur[u] != -1 && edge[cur[u]].cap > edge[cur[u]].flow && dep[u] + 1 == dep[edge[cur[u]].to])
			{
				sta[tail++] = cur[u];
				u = edge[cur[u]].to;
			}
			else
			{
				while (u != s && cur[u] == -1)
					u = edge[sta[--tail] ^ 1].to;
				cur[u] = edge[cur[u]].next;
			}
		}
	}
	return maxflow;
}

void addedge(int u, int v, int w, int rw = 0)
{
	edge[tol].to = v;
	edge[tol].cap = w;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = rw;
	edge[tol].flow = 0;
	edge[tol].next = head[v];
	head[v] = tol++;
}

void init()
{
	tol = 2;
	memset(head, -1, sizeof(head));
}
int main(){    
	init();
	scanf("%d%d", &m, &n);
	int sum=0,sz=0;
	S=0;T=n*m+1;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			sum += a[i][j];
			sz ++;
			if((i + j) % 2){
				addedge(S, sz, a[i][j]);
				if(j < n) addedge(sz, sz + 1, 1e9);
				if(j > 1) addedge(sz, sz - 1, 1e9);
				if(i < m) addedge(sz, sz + n, 1e9);
				if(i > 1) addedge(sz, sz - n, 1e9);
			} else {
				addedge(sz,T,a[i][j]);
			}
		}
	} 
	printf("%d",sum - dinic(S,T,T));
	return 0;
}
