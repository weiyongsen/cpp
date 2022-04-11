const int  DefaultListSize=20;
template <class Elem> class AStack2{
private:
	int size;
	int top1,top2;
	Elem *listArray;
public:
	AStack2(int sz=DefaultListSize){
		size=sz;
		top=0;
		listArray=new Elem[sz];
	}
	~AStack2(){
		delete[] listArray;
	}
	void clear(int st){
		if(st==1)
			top1=0;
		else
			top2=size-1;
	}
	bool push(int st,const Elem& item){
		if(top+1>=top2)
			return false;
		if(st==1)
			listArray[top1++]=item;
		else
			listArray[top2--]=item;
		return ture;
	}
	bool pop(int st,Elem& it){
		if((st==1)&&(top1==0))
			return false;
		if((st==2)&&(top2==(size-1))
			return false;
		if(st==1)
			it=listArray[top1-1];
		else
			it=listArray[top2+1];
		return true;
	}
	int length(int st) const{
		if(st==1)
			return top1;
		else
			return size-top2-1;
	}
}
