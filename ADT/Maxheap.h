#include "Assert.h"
#include "swap.h"

template <typename E, typename Comp> class MaxHeap{
private:
	E* Heap;
	int maxsize;
	int n;
	
	void siftdown(int pos){
		while(!isLeaf(pos)){
			int j=leftchild(pos);
			int rc=rightchild(pos);
			if((rc<n)&&Comp::prior(Heap[rc],Heap[j]))
				j=rc;
			if(Comp::prior(Heap[pos],Heap[j]))
				return ;
			swap(Heap,pos,j);
			pos = j;
		}
	}

public:
	MaxHeap(E*h, int num, int max){
		Heap=h; n=num; maxsize=max; 
		buildHeap();
	}
	int size() const{
		return n;	
	}
	bool isLeaf(int pos) const{
		return (pos>=n/2) && (pos<n);
	}
	int leftchild(int pos) const{
		return 2*pos+1;
	}
	int rightchild(int pos) const{
		return 2*pos+2;
	}
	int parent(int pos) const{
		return (pos-1)/2;
	}
	void buildHeap(){
		for(int i=n/2-1; i>=0; i--)
			siftdown(i);
	}
	
	void insert (const E& it){
		Assert(n<maxsize,"Heap is full");
		int curr = n++;
		Heap[curr]=it;
		while((curr!=0)&&(Comp::prior(Heap[curr],Heap[parent(curr)]))){
			swap(Heap,curr,parent(curr));
			curr = parent(curr);
		}
	}
	E removefirst(){
		Assert(n>0,"Heap is empty");
		swap(Heap,0,--n);
		if(n!=0)
			siftdown(0);
		return Heap[n];
	}
	E remove(int pos){
		Assert((pos>=0)&&(pos<n),"Bad position");
		if(pos==(n-1))
			n--;
		else{
			swap(Heap,pos,--n);
			while((pos!=0)&&(Comp::prior(Heap[pos],Heap[parent(pos)]))){
				swap(Heap,pos,parent(pos));
				pos=parent(pos);
			}
			if(n!=0)
				siftdown(pos);
		}
		return Heap[n];
	}	
};

