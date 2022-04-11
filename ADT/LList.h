#include "Link.h"
using namespace std;
const int defaultsize=100;

template <typename E>
class LList{			//链表的定义 
private:
	Link<E>* head;
	Link<E>* tail;
	Link<E>* curr;
	int cnt;
	
	void init(){
		curr=tail=head=new Link<E>;
		cnt=0;
	}
	
	void removeall(){
		while(head!=NULL){
			curr=head;
			head=head->next;
			delete curr;
		}
	}
public:
	LList(int size=defaultsize){
		init();
	}
	~LList(){ removeall(); }
	void print() const{
		if(head==NULL){
			cout << "LList empty" << endl;
		}
		else{
			Link<E>* p;
			p=head->next;
			while(p){
				cout<< p->e << "\t";
				p=p->next;
			}
		}
	}
	void clear(){
		removeall();
		init();
	}
	void insert(const E& it){
		curr->next=new Link<E>(it,curr->next);
		if (tail==curr)
			tail=curr->next;
		cnt++;
	}
	void append(const E& it){
		tail=tail->next=new Link<E>(it,NULL);
		cnt++;
	}
	E remove(){
//		Assert(curr->next!=NULL,"No e");
		if(curr->next==NULL)
			cout << "No e" <<endl;
		else{
			E it=curr->next->e;		//记录下要remove的指针中含有的值 
			Link<E>* Itmp=next->next;
			if(tail==curr->next)
				tail=curr;
			curr->next=curr->next->next;
			delete Itmp;
			cnt--;
			return it;			
		}	
	}
	void moveToStart(){
		curr=head;
	}
	void moveToEnd(){
		curr=tail;
	}
	void prev(){
		if(curr==head)
			return;
		Link<E>* temp=head;
		while(temp->next!=curr)
			temp=temp->next;
		curr=temp;
	}
	void next(){
		if(curr!=tail)
			curr=curr->next;
	}
	int length() const{
		return cnt;
	}
	int currPos() const{
		Link<E>* temp=head;
		int i;
		for(i=0;curr!=temp;i++)
			temp=temp->next;
		return i;
	}
	void moveToPos(int pos){
//		Assert ((pos>=0)&&(pos<=cnt),"Position out of range");
	    if(pos<0||pos>cnt)
	    	cout << "Position out of range" << endl;
	    else
			for(int i=0;i<pos;i++)
			curr=curr->next;		
	}
	const E& getvalue() const{
//		Assert(curr->next!=NULL,"No value");
		if(curr->next==NULL)
			cout << "No value" << endl;
		else
			return curr->next->e;
	}
};
