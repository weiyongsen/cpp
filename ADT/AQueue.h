#include <iostream>
using namespace std;
const int defaultsize=100;
template <typename E> 
class AQueue{
private:
	int maxSize;
	int front;
	int rear;
	E *listarray;
	
public:
	AQueue(int size=defaultsize){
		maxSize=size+1;
		rear=0;
		front=1;
		listarray=new E[maxSize];
	}
	~AQueue(){
		delete [] listarray;
	}
	void clear(){
		front=1;
		rear=0;
//		delete [] listarray;
//		listarray=new E[maxSize];
	}
	void enqueue(const E& it){
		if((rear+2)%maxSize==front){
			cout << "Queue is full" << endl;
		}
		else{
			rear=(rear+1)%maxSize;
			listarray[rear]=it;			
		}

	}
	E dequeue(){
		if(length()==0){
			cout << "Queue is empty" << endl;
		}
		else{
			E it=listarray[front];
			front=(front+1)%maxSize;
			return it;
		}
	}
	const E& frontValue() const{
		if(length()==0){
			cout << "Queue is empty" << endl;
		}
		else{
			return listarray[front];
		}
	}
	virtual int length(){
		return ((rear+maxSize)-front+1)%maxSize;
	}
	int maxsize() const{
		return maxSize-1;
	}
};
