#include <iostream>
#include "Link.h"
using namespace std;
const int defaultsize=100;
template <typename E> 
class LQueue{
private:
	Link<E>* front;
	Link<E>* rear;
	int size;
	
public:
	LQueue(int sz=defaultsize){
		front=rear=new Link<E>();
		size=0;
	}
	~LQueue(){
		clear();
		delete front;
	}
	void clear(){
		while(front->next!=NULL){
			rear=front;
			delete rear;
		}
		rear=front;
		size=0;
	}
	void enqueue(const E& it){
		rear->next=new Link<E>(it,NULL);
		rear=rear->next;
		size++;
	}
	E dequeue(){
		if(size==0){
			cout << "Queue is empty" << endl;
		}
		else{
			E it=front->next->element;
			Link<E>* ltemp=front->next;
			front->next=ltemp->next;
			if(rear=ltemp)
				rear=front;
			delete ltemp;
			size--;
			return it;
		}
	}
	const E& frontValue() const{
		if(size==0){
			cout << "Queue is empty" << endl;
		}
		else{
			return front->next->element;
		}
	}
	virtual int length(){
		return size;
	}
};

