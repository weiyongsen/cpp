#include <bits/stdc++.h>
using namespace std;
const int defaultsize=100;

template <typename E> 
class DLink{		//˫����ڵ㶨�� 
private:
	static DLink<E> *freelist;    //����DLink���󶼿�������ͬһ��freelist���� 
public:
	E e,el;
	DLink* next;
	DLink* prev;
	DLink(const E& it1, const E& it2, DLink* prevp, DLink* nextp){
		e=it1;
		el=it2;
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


template <typename E>
class DLList{			//����Ķ��� 
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
	void print() const{					//��ͷ��β��ӡ����������Ԫ�� 
		if(head==NULL){
			cout << "List empty" << endl;
		}
		else{
			DLink<E>* p;
			p=head->next;
			while(p!=tail){
				cout<< p->e << " " << p->el << "\n";
				p=p->next;
			}
		}
	}
	void clear(){
		removeall();
		init();
	}
	void insert(const E& it1,const E& it2){
		curr->next=curr->next->prev=new DLink<E>(it1,it2,curr,curr->next);
		cnt++;
	}
	void append(const E& it1,const E& it2){
		tail->prev=tail->prev->next=new DLink<E>(it1,it2,tail->prev,tail);
		cnt++;
	}
	E remove(){				//�Ƴ���ǰԪ�� 
//		Assert(curr->next!=NULL,"No e");
		if(curr->next==tail)
			return NULL;//��ʱ��ɾ���ڵ� 
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
	int length() const{			//˫����ǰ����Ԫ�ض��� 
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
	const E& getv1() const{
//		Assert(curr->next!=NULL,"No value");
		if(curr->next==tail){
			;
		}
		else
			return curr->next->e;
	}
		const E& getv2() const{
//		Assert(curr->next!=NULL,"No value");
		if(curr->next==tail){
			; 
		}
		else
			return curr->next->el;
	}
};
//int cmp(int e1,int e2){
//	if(e1>e2)
//		return 1;
//	else if(e1<e2)
//		return -1;
//	else
//		return 0;
//}
int main(){
	DLList<int> d1;
	DLList<int> d2;
	DLList<int> add;
	DLList<int> mul;
	int M,N;
	cin >> M >> N;
	int m=M,n=N;		//���� M��N ��ֵ�����ı� 
	int x,y;
	while(m--){
		cin >> x >> y;
		d1.append(x,y);
	}
	while(n--){
		cin >> x >> y;
		d2.append(x,y);
	}	
//	m=M;n=N;
//	while(m--){
//		cout << d1.getv1() << " " << d1.getv2() << endl;
//		d1.next();
//	}
//	while(n--){
//		cout << d2.getv1() << " " << d2.getv2() << endl;
//		d2.next();
//	}
	int i=0,j=0;		//�ֱ�������¼d1��d2������curr��λ�� 
	while(i!=M&&j!=N){
		if(d1.getv2()>d2.getv2()){					//�ж�ָ����С���Դ˽���add������� 
			add.append(d1.getv1(),d1.getv2());		//add���ӷ��� ��������� 
			d1.next();
			i++;
		}
		else if(d1.getv2()<d2.getv2()){
			add.append(d2.getv1(),d2.getv2());
			d2.next();
			j++;
		}
		else if(d1.getv2()==d2.getv2()){
			if(d1.getv1()+d2.getv1()!=0){
				add.append(d1.getv1()+d2.getv1(),d1.getv2());
				d1.next();d2.next();
				i++;j++;
			}
		}
	}
	if(i<M){		//d1��d2������û�б��������һ��������Ԫ��ֱ�Ӹ��Ƶ�add���� 
		int p=M-i;
		while(p--){
			add.append(d1.getv1(),d1.getv2());
			d1.next();
		}
	}
	if(j<N){
		int q=N-j;
		while(q--){
			add.append(d2.getv1(),d2.getv2());
			d2.next();
		}
	}
	cout << add.length() << endl;
	while(add.length()){				//��ɼӷ���� 
		cout << add.getv1() << " " << add.getv2() << endl;
		add.remove();
	}				
	
	d1.moveToStart();
	d2.moveToStart();		//��������curr����head�����Ա���г˷����� 
	m=M;n=N;i=0;j=0;		//�ض��� 
	if(d1.length()==0||d2.length()==0)	//������һ������ʽΪ0����˷����Ϊ0�� 
		cout << mul.length() << endl;			
	else{
		for(j=0;j<n;j++){
			mul.append(d1.getv1()*d2.getv1(),d1.getv2()+d2.getv2());
			d2.next();
		}
		d1.next();
		d2.moveToStart();		
		int c=0,e=0;			//e����¼mul ���������е�ֵ��cʵ�ֶ���ı����� 
		i=1;j=0;
		e=i*n;
		for(i=1;i<m;i++){				//����d1 
			for(j=0;j<n;j++){			//����d2 
				c=0;
				while((c<e)&&d1.getv2()+d2.getv2()<=mul.getv2()){
					mul.next();			//ʹcurr�ƶ���ǡ����λ�� 
					c++;
				}
				if(d1.getv2()+d2.getv2()==mul.getv2()){
					if(d1.getv1()*d2.getv1()+mul.getv1()){
						mul.remove();
						mul.insert(d1.getv1()*d2.getv2()+mul.getv1(),mul.getv2()); //mul�ڴ˲����� 
					}
					else{
						mul.remove();		//ֱ���� mul ��ɾȥ��һ�� 
						--e;
					}
				}
				else{
					mul.insert(d1.getv1()*d2.getv1(),d1.getv2()+d2.getv2());
					++e;
				}
				d2.next();
				mul.moveToStart();		//�����жϣ�ÿ�ζ���mul�ص���㡣 
			}
			d1.next();
			d2.moveToStart();			//d2�����һ�α��� 
		}
		cout << mul.length() << endl;
		while(mul.length()){
			cout << mul.getv1() << " " << mul.getv2() << endl;
			mul.remove();
		}	
	}		
	return 0;
}

