#include <bits/stdc++.h>
using namespace std;
const int defaultsize=100;

template <typename E> 
class DLink{		//双链表节点定义 
private:
	static DLink<E> *freelist;    //所有DLink对象都可以引用同一个freelist变量 
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
			return ::new DLink;   //表示标准C++new运算符被调用，而不是重载的new运算符。如果没有冒号，会陷入死循环 
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
	void print() const{					//从头到尾打印链表中所含元素 
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
	E remove(){				//移除当前元素 
//		Assert(curr->next!=NULL,"No e");
		if(curr->next==tail)
			return NULL;//此时不删除节点 
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
	int length() const{			//双链表当前所含元素多少 
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
	int m=M,n=N;		//保护 M，N 的值不被改变 
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
	int i=0,j=0;		//分别用来记录d1，d2链表中curr的位置 
	while(i!=M&&j!=N){
		if(d1.getv2()>d2.getv2()){					//判断指数大小，以此进行add链表操作 
			add.append(d1.getv1(),d1.getv2());		//add（加法） 链表添加项 
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
	if(i<M){		//d1，d2链表中没有遍历完的那一个，后面元素直接复制到add链表 
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
	while(add.length()){				//完成加法输出 
		cout << add.getv1() << " " << add.getv2() << endl;
		add.remove();
	}				
	
	d1.moveToStart();
	d2.moveToStart();		//将两链表curr移至head处，以便进行乘法操作 
	m=M;n=N;i=0;j=0;		//重定义 
	if(d1.length()==0||d2.length()==0)	//若其中一个多项式为0，则乘法结果为0项 
		cout << mul.length() << endl;			
	else{
		for(j=0;j<n;j++){
			mul.append(d1.getv1()*d2.getv1(),d1.getv2()+d2.getv2());
			d2.next();
		}
		d1.next();
		d2.moveToStart();		
		int c=0,e=0;			//e来记录mul 链表中已有的值。c实现对其的遍历。 
		i=1;j=0;
		e=i*n;
		for(i=1;i<m;i++){				//遍历d1 
			for(j=0;j<n;j++){			//遍历d2 
				c=0;
				while((c<e)&&d1.getv2()+d2.getv2()<=mul.getv2()){
					mul.next();			//使curr移动到恰当的位置 
					c++;
				}
				if(d1.getv2()+d2.getv2()==mul.getv2()){
					if(d1.getv1()*d2.getv1()+mul.getv1()){
						mul.remove();
						mul.insert(d1.getv1()*d2.getv2()+mul.getv1(),mul.getv2()); //mul在此插入项 
					}
					else{
						mul.remove();		//直接在 mul 中删去这一项 
						--e;
					}
				}
				else{
					mul.insert(d1.getv1()*d2.getv1(),d1.getv2()+d2.getv2());
					++e;
				}
				d2.next();
				mul.moveToStart();		//便于判断，每次都让mul回到起点。 
			}
			d1.next();
			d2.moveToStart();			//d2完成了一次遍历 
		}
		cout << mul.length() << endl;
		while(mul.length()){
			cout << mul.getv1() << " " << mul.getv2() << endl;
			mul.remove();
		}	
	}		
	return 0;
}

