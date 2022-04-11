#include <bits/stdc++.h>
template <typename E> 
class DLink{		//˫����ڵ㶨�� 
private:
	static DLink<E> *freelist;    //����DLink���󶼿�������ͬһ��freelist���� 
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
			return ::new DLink;   //��ʾ��׼C++new����������ã����������ص�new����������û��ð�ţ���������ѭ�� 
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
