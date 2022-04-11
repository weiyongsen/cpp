#include <iostream>
using namespace std;
const int defaultsize=100;

template <typename E>
class AList{
private:
	int maxsize;
	int listsize;
	int curr;
	E* listarray;	
	
public:
    AList(int size=defaultsize){       
        maxsize = size;
        listsize = curr = 0;
        listarray = new E[maxsize];
    }
    ~AList(){ delete[] listarray; }
	void clear(){
		delete [] listarray;
		listsize=curr=0;
		listarray=new E[maxsize];
	}
	void insert(const E& it){
		if(listsize<maxsize)
		{
			for(int i=listsize;i>curr;i--){
				listarray[i]=listarray[i-1];
			}
			listarray[curr]=it;
			listsize++;			
		}
		else
			cout<< "Insert failed" << endl;
	}
	void append(const E& it){
		if(listsize<maxsize)
			listarray[listsize++]=it;
		else
			cout << "Append failed" << endl;
	}
	E remove(){
		if((curr>=0)&&(curr<listsize)){
			E it=listarray[curr];
			for(int i=curr;i<listsize-1;i++)
			{
				listarray[i]=listarray[i+1];
			}
			listsize--;
			return it;
		}
		else{
			cout << "Remove failed" << endl;
			return listarray[curr];
		}
		
	}
	void moveToStart(){
		curr=0;
	}
	void moveToEnd(){
		curr=listsize;
	}
	void prev(){
		if(curr!=0)
			curr--;
	}
	void next(){
		if(curr<listsize)
			curr++;
	}
	int length() const{
		return listsize;
	}
	int maxlength() const{
		return maxsize;
	}
	int currPos() const{
		return curr;
	}
	void moveToPos(int pos){
		if((pos>=0)&&(pos<listsize))
			curr=pos;
		else
			cout << "MoveToPos failed" << endl;
	}
	const E& gevalue() const{
		if((curr>=0)&&(curr<listsize))
			return listarray[curr];
		else
			return listarray[0];
	}
};

