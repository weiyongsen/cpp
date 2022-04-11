#include <bits/stdc++.h>
template <typename E> 
class DLink{		//双链表节点定义 
private:
	static DLink<E> *freelist;    //所有DLink对象都可以引用同一个freelist变量 
public:
	E e;
	DLink* next;
	DLink* prev;
	DLink(const E& it, DLink* prevp, DLink* nextp){
		e = it;
		prev=prevp;
		next=nextp;
	}
	DLink(DLink* prevp=NULL, DLink* nextp=NULL){
		prev=prevp;
		next=nextp;
	}
	void* operator new(size_t){
		if(freelist==NULL)
			return ::new DLink;   //表示标准C++new运算符被调用，而不是重载的new运算符。如果没有冒号，会陷入死循环 
		DLink<E>* temp=freelist;
		freelist=freelist->next;
		return temp;
	}
	void operator delete(void* ptr){
		((DLink<E>*)ptr)->next=freelist;
		freelist=(DLink<E>*)ptr;
	}
};
template <typename E>
DLink<E>* DLink<E>::freelist=NULL;
