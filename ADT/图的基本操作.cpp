/*
6 9		（节点数和路径数） 
1 2 10
1 4 20
1 6 2
2 3 3
2 4 5
3 5 15
4 5 11
4 6 10
5 6 3

输出
1 2 4 6 3 5（BFS） 
1 2 3 5 4 6（DFS） 
1 2 10	（起点到其他点的最短路） 
1 2 3 13
1 6 4 12
1 6 5 5
1 6 2
1 6 2	（根据权重输出MST的边） 
2 3 3
5 6 3
2 4 5
1 2 10
YES		（是否有环） 

*/
#include <bits/stdc++.h>
using namespace std;
const int UNVISITED=-1;
const int VISITED=1;
int c=0;
struct branch{
	int begin;
	int end;
	int weight;
	void ini(int a,int b,int c){
		begin=a;
		end=b;
		weight=c;
	}
};
class Graphm{
private:
	int numVertex, numEdge;
	int **matrix;
	int *mark;
public:
	Graphm(int numVert){
		Init(numVert);
	}
	~Graphm(){
		delete [] mark;
		for(int i=0;i<numVertex;i++)
			delete [] matrix[i];
		delete [] matrix;
	}
	void Init(int n){
		int i;
		numVertex =n;
		numEdge=0;
		mark=new int[n];
//		struct edge E[n]; 
		for(int i=0;i<numVertex;i++){
			mark[i]=UNVISITED;
		}
		matrix = (int **)new int*[numVertex];
		for(int i=0;i<numVertex;i++){
			matrix[i]=new int[numVertex];
		}
		for(int i=0;i<numVertex;i++)
			for(int j=0;j<numVertex;j++){
				matrix[i][j]=0;
			}
	}
	
	int n(){
		return numVertex;
	}
	int e(){
		return numEdge;
	}
	
	int first(int v){
		for(int i=0;i<numVertex;i++)
			if(matrix[v][i]!=0)
				return i;
		return numVertex;
	}
	int next(int v,int w){
		for(int i=w+1;i<numVertex;i++)
			if(matrix[v][i]!=0)
				return i;
		return numVertex;
	}
	void setEdge(int v1,int v2,int wt){
		if (matrix [v1][v2] ==0)
			numEdge++;
		matrix[v1][v2]=wt;
		matrix[v2][v1]=wt;
	}
	void delEdge(int v1,int v2){
		if(matrix[v1][v2]!=0)
			numEdge--;
		matrix[v1][v2]=0;
	}
	bool isEdge(int i,int j){
		return matrix[i][j]!=0;
	}
	
	int weight(int v1,int v2){
		return matrix[v1][v2];
	}
	int getMark(int v){
		return mark[v];
	}
	void setMark(int v,int val){
		mark[v]=val;
	}
	void iniMark(){
		for(int i=0;i<numVertex;i++)
			setMark(i,UNVISITED);
	}
	
	void DFS(Graphm *G,int v,int *dfs){
		//前 
		dfs[c++]=v+1; 
		G->setMark(v,VISITED);
		for(int w=G->first(v);w<G->n();w=G->next(v,w))
			if(G->getMark(w)==UNVISITED)
				DFS(G,w,dfs);
		//后 
		
	}
	void BFS(Graphm *G,int start, queue<int>* Q, int *bfs){
		int v,w;
		Q->push(start);
		G->setMark(start,VISITED);
		while(Q->size()!=0){
			v=Q->front();
			Q->pop();
			//前
			//cout << v+1 << " ";
			bfs[c++]=v+1;
			for(w=G->first(v);w<G->n();w=G->next(v,w))
				if(G->getMark(w)==UNVISITED){
					G->setMark(w,VISITED);
					Q->push(w);
				} 
		}
	}
	int minVertex(Graphm* G,int* D){
		int i=0,v=-1;
		for(int i=0;i<G->n();i++)
			if(G->getMark(i)==UNVISITED){
				v=i;
				break;
			}
		for(i++;i<G->n();i++)
			if((G->getMark(i)==UNVISITED) && (D[i]<D[v]))
				v=i;
		return v;
	}
	void dijkstra(Graphm* G,int* D,int s,int* pre){
		int i=0,v=0,w=0;
		D[s]=0; 
		for(i=0;i<G->n();i++){
			v=minVertex(G,D);
			if(D[v]==INFINITY)
				return ;
			G->setMark(v,VISITED);
			for(w=G->first(v);w<G->n();w=G->next(v,w))
				if(D[w] > (D[v] + G->weight(v,w))){
					D[w] = D[v] + G->weight(v,w);
					pre[w]=v;
				}					
		}
	}
	void print_path(int s,int t,int *pre){
		if(s==t){
			cout << s+1 << " ";
			return ;
		}
		print_path(s,pre[t],pre);
		cout << t+1 << " ";
	}
	void prim(Graphm* G,int* D,int s,struct branch* b){
		int V[G->n()];
		for(int i=0;i<G->n();i++)
			D[i]=INFINITY;
		D[s]=0;
		int i=0,w=0,j=0;
		for(i=0;i<G->n();i++){
			int v=minVertex(G,D);
			G->setMark(v,VISITED);
			if(v!=s){
				b[j++].ini(min(V[v],v),max(V[v],v),G->weight(V[v],v));
			}
		if(D[v]==INFINITY)
			return ;
		for(w=G->first(v);w<G->n();w=G->next(v,w))
			if(D[w]> G->weight(v,w)){
				D[w]= G->weight(v,w);
				V[w]=v;														
			}			
		}
	}

	void top(Graphm*G)
	{
		int flag=0;
		int tp[G->n()];	
		memset(tp,0,sizeof(tp));	
		int v=0,w=0;
		for(v=0; v<G->n(); v++)
			for(w=G->first(v);w<G->n();w=G->next(v,w))
				tp[w]++;
		for(int i=0;i<G->n();i++){
			if(tp[i]<1)	{
				tp[i]--;
				for(int j=G->first(i); j<G->n(); j=G->next(i,j))
					tp[j]--;
			}
		}
		for(int i=0;i<G->n();i++)	
			if(tp[i]>0){
				flag=1;	
				break;
			}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
};
	
bool cmp(branch a,branch b){
	if(a.weight<b.weight)
		return 1;
	else if(a.weight==b.weight)
		return a.begin<b.begin;
	else
		return 0;
}	
int main(){
	int n,m;
	cin >> n >> m;
	Graphm G(n);
	queue<int> Q;
	int v1,v2,wt;
	int dfs[n],bfs[n];
	while(m--){
		cin >> v1 >> v2 >> wt;
		G.setEdge(v1-1,v2-1,wt);
	}
	int D[n],pre[n];
	for(int i=0;i<n;i++)
		D[i]=INFINITY;
	struct branch b[n];
	for(int i=0;i<n;i++){
		b[i].ini(0,0,INFINITY);
	}
//	cout << "BFS:" << endl;
	G.BFS(&G,0,&Q,bfs); 
	for(int i=0;i<n;i++)
		if(i==0)
			cout << bfs[i];
		else
			cout << " " << bfs[i]; 
	G.iniMark();
	cout << endl;
	c=0;
//	cout << "DFS:" << endl;
	G.DFS(&G,0,dfs);
	for(int i=0;i<n;i++)
		if(i==0)
			cout << dfs[i];
		else
			cout << " " << dfs[i];
	cout << endl;
	G.iniMark();

//	cout << "dijkstra:" << endl;
	G.dijkstra(&G,D,0,pre);
	for(int i=1;i<n;i++){
		G.print_path(0,i,pre);
		cout << D[i] << endl;
	}
//	cout << endl;
	G.iniMark();
	
//	cout << "prim:" << endl;
	G.prim(&G,D,0,b);
	sort(b,b+n,cmp);
	for(int i=0;i<n-1;i++)
		cout << b[i].begin+1 <<" "<< b[i].end+1 <<" "<< b[i].weight <<endl;
	G.iniMark();
	
	G.top(&G);
	return 0;
}
