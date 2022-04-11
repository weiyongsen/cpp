#include <bits/stdc++.h>
using namespace std;
const int UNVISITED=0;
const int VISITED=1;
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
		//Assert (wt>0,"Illegal weight value");
		if (matrix [v1][v2] ==0)
			numEdge++;
		matrix[v1][v2]=wt;
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
	
	
	void DFS(Graphm *G,int v){
		//Ç° 
		cout << v+1 << " "; 
		G->setMark(v,VISITED);
		for(int w=G->first(v);w<G->n();w=G->next(v,w))
			if(G->getMark(w)==UNVISITED)
				DFS(G,w);
		//ºó 
		
	}
	void BFS(Graphm *G,int start, queue<int>* Q){
		int v,w;
		Q->push(start);
		G->setMark(start,VISITED);
		while(Q->size()!=0){
			v=Q->front();
			Q->pop();
			//Ç°
			cout << v+1 << " ";
			for(w=G->first(v);w<G->n();w=G->next(v,w))
				if(G->getMark(w)==UNVISITED){
					G->setMark(w,VISITED);
					Q->push(w);
				} 
		}
	}
	int minVertex(Graphm* G,int* D){
		int i,v=-1;
		for(int i=0;i<G->n();i++)
			if(G->getMark(i)==UNVISITED){
				v=i;break;
			}
		for(i++;i<G->n();i++)
			if((G->getMark(i)==UNVISITED)&&(D[i]<D[v]))
				v=i;
		return v;
	}
	void dijkstra(Graphm* G,int* D,int s,int* pre){
		int i,v,w;
		D[s]=0; 
		for(i=0;i<G->n();i++){
			v=minVertex(G,D);
			if(D[v]==INFINITY)
				return ;
			G->setMark(v,VISITED);
			for(w=G->first(v);w<G->n();w=G->next(v,w))
				if(D[w] > (D[v] + G->weight(v,w))){
					D[w] = D[v]+G->weight(v,w);
					pre[w]=v;
				}					
		}
	}
	void print_path(int s,int t,int *pre){
		if(s==t){
			cout << s+1;
			return ;
		}
		print_path(s,pre[t],pre);
		cout << t+1;
	}
	void prim(Graphm* G,int* D,int s,int pre){
		int V[G->n()];
		int i,w;
		for(i=0;i<G->n();i++){
			int v=minVertex(G,D);
			G->setMark(v,VISITED);
	//		if(v!=s)
	//			AddEdgetoMST(V[v],v);
		if(D[v]==INFINITY)
			return ;
		for(w=G->first(v);w<G->n();w=G->next(v,w))
			if(D[w]> G->weight(v,w)){
				D[w]= G->weight(v,w);
				V[v]=v;
			}			
		}
	}
};
	
