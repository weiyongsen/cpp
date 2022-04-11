#include <iostream>
using namespace std;
const int defaultsize=100;

template <typename E> 
class AStack{
private:
	int maxSize;
	int top;		//同时记录了stack中元素数量 
	E *listarray;
public:
	AStack(int size=defaultsize){
		maxSize=size;
		top=0;
		listarray = new E[maxSize];
	}
	~AStack(){
		delete [] listarray;
	}
	void clear(){
		top=0;
	}
	void push(const E& it){
		if(top==maxSize)
			cout << "Stack is full" << endl;
		else
			listarray[top++]=it;
	}
	E pop(){
		if(top==0)
			cout << "Stack is empty" << endl;
		else
			return listarray[--top];		//stack中最高的元素是listarray[top-1] 
	}
	const E& topValue() const{
		if(top==0)
			cout<<"Stack is empty"<<endl;
		else
			return listarray[top-1];
	}
	int length() const{
		return top;
	}	
	int maxsize() const{
		return maxsize;
	}
};

