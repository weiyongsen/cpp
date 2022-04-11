#include <bits/stdc++.h>
#include "swap.h"
template <class Elem,class Comp> class MinHeap{
private:
	Elem* Heap;
	int size;
	int n;
	void siftdown(int);
public:
	MinHeap(Elem* h,int num,int max){
		Heap=h;
		n=num;
		size=max;
		buildHeap();
	}
	int heapsize() const{
		return n;
	}
	bool isLeaf(int pos) const{
		return (pos>=n/2)&&(pos<n); 
	}
	int leftchild(int pos) const{	//pos´Ó0¿ªÊ¼ 
		return 2*pos+1;
	}
	int rightchild(int pos) const{
		return 2*pos+2;
	}
	int parent(int pos) const{
		return (pos-1)/2;
	}
	bool insert(const Elem&);
	bool removemin(Elem&);
	bool remove(int, Elem&);
	void buildHeap(){
		for(int i=n/2-1;i>=0;i--)
			siftdown(i);
	}
};

template <class Elem, class Comp>
void MinHeap<Elem,Comp>::siftdown(int pos){
	while(!isLeaf(pos)){
		int j=leftchild(pos);
		int rc=rightchild(pos);
		if((rc<n)&&Comp::gt(Heap[j],Heap[rc]))
		 	j=rc;
		if(!Comp::gt(Heap[pos],Heap[j]))
			return ;
		swap(Heap,pos,j);
		pos=j;
	}
}

template <class Elem,class Comp>
bool MinHeap<Elem,Comp>::insert(const Elem& val){
	if(n>=size)
		return false;
	int curr=n++;
	Heap[curr]=val;
	while((curr!=0)&&(Comp::lt(Heap[curr],Heap[parent(curr)]))){
		swap(Heap,curr,parent(curr));
		curr=parent(curr);
	}
	return true;
}

template <class Elem,class Comp>
bool MinHeap<Elem,Comp>::removemin(Elem& it){
	if(n==0)
		return false;
	swap(Heap,0,--n);
	if(n!=0)
		siftdown(0);
	it=Heap[n];
	return true;
}

template <class Elem,class Comp>
bool MinHeap<Elem,Comp>::remove(int pos,Elem& it){
	if((pos<0)||(pos>=n))
		return false;
	swap(Heap,pos,parent(pos));
	siftdown(pos);
	it=Heap[n];
	return true;
}

