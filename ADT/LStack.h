#include "Link.h"
using namespace std;
const int defaultsize=100;

template <typename E> 
class LStack{
private:
	Link<E>* top;
	int size;
	
public:
	LStack(int sz=defaultsize){
		top=NULL;
		size=0;
	}
	~LStack() { clear(); }
	void clear(){
		while(top!=NULL){
			Link<E>* temp=top;
			top=top->next;
			delete temp;
		}
		size=0;
	}
	void push(const E& it){
		top = new Link<E>(it,top);
		size++;		
	}
	E pop(){
		if(top==NULL)
			cout << "Stack is empty" << endl;
		else{
			E it=top->element;
			Link<E>* ltemp=top->next;
			delete top;
			top = ltemp;
			size--;
			return it;
		}
	}
	const E& topValue() const{
		if(top==0)
			cout << "Stack is empty" <<endl;
		else
			return top->element;
	}
	int length() const{
		return size;
	}
};

