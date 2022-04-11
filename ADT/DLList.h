#include "DLink.h"
using namespace std;
const int defaultsize=100;

template <typename E>
class DLList{			//链表的定义 
private:
	DLink<E>* head;
	DLink<E>* tail;
	DLink<E>* curr;
	int cnt;
	
	void init(){
		curr = head =new DLink<E>;
		tail =new DLink<E>;  
		curr->next = tail;
		tail->prev = curr;
		cnt = 0;
	}
	void removeall(){
		while(head!=NULL){
			curr=head;
			head=head->next;
			delete curr;
		}
	}
public:
	DLList(int size=defaultsize){
		init();
	}
	~DLList(){ removeall(); }
	void print() const{
		if(head==NULL){
			cout << "List empty" << endl;
		}
		else{
			DLink<E>* p;
			p=head->next;
			while(p!=tail){
				cout<< p->e << "\n";
				p=p->next;
			}
		}
	}
	void clear(){
		removeall();
		init();
	}
	void insert(const E& it){
		curr->next=curr->next->prev=new DLink<E>(it,curr,curr->next);
		cnt++;
	}
	void append(const E& it){
		tail->prev=tail->prev->next=new DLink<E>(it,tail->prev,tail);
		cnt++;
	}
	E remove(){
//		Assert(curr->next!=NULL,"No e");
		if(curr->next==tail)
			return NULL;
		E it=curr->next->e;
		DLink<E>* ltemp=curr->next;
		curr->next->next->prev=curr;
		curr->next=curr->next->next;
		delete ltemp;
		cnt--;		
		return it;
	}
	void moveToStart(){
		curr=head;
	}
	void moveToEnd(){
		curr=tail;
	}
	void prev(){
		if(curr->prev!=head)
			curr=curr->prev;
	}
	void next(){
		if(curr->next!=tail)
			curr=curr->next;
	}
	int length() const{
		return cnt;
	}
	int currPos() const{
		DLink<E>* temp=head;
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
		if(curr->next==tail){
				return NULL; //一般为0,char类型返回空格 
		}
		else
			return curr->next->e;
	}
};
