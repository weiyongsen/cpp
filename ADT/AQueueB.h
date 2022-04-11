const int DefaultSize=20;
template <class E>
class AQueueB{
private:
	int size;
	int front;
	int rear;
	E *listArray;
	bool isEmpty;
public:
	AqueueB(int sz=DefaultSize){
		size=sz+1;
		rear=0;
		front=1;
		listArray=new E{size}; ////
		isEmpty=true;
	}
	~AqueueB(){
		delete[]listArray;
	}
	void clear(){
		front=rear;		////
		isEmpty=true;
	}
	bool enqueue(const E&it){
		if((isEmpty!=true)&&(((rear+1)%size)==front))
			return false;
		listArray[rear]=it;
		isEmpty=false;
		return true;
	}
	bool dequeue(E& it){
		if(isEmpty==true)
			return false;
		it=listArray[front];
		front=(front+1)%size;
		if(((rear+1)%size)==front)
			isEmpty==true;
		return true;
	}
	bool frontValue(E& it)const{
		if(isEmpty==true)
			return false;
		it=listArray[front];
		return true;
	}
	virtual int length() const{
		if(isEmpty==true)
			return 0;
		return ((rear+size)-front+1)%size;
	}	
};
