/*
输入： 
5
3 2
1 3
4 2
12 10
4 6

输出：第一行堆遍历，第二行堆排序 
1/3  2/3  2  6/5  3/2
1/3  2/3  6/5  3/2  2
*/ 
#include <bits/stdc++.h>
using namespace std;

void Assert(bool val,string s){
	if(!val){
		cout <<"Assertion Failed:" << s << endl;
		exit(-1);
	}
}

template<typename E>
inline void swap(E A[],int i,int j){
	E temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}

template <typename E> class heap{
private:
	E* Heap;
	int maxsize;
	int n;
	
	void siftdown(int pos){
		while(!isLeaf(pos)){
			int j=leftchild(pos);
			int rc=rightchild(pos);
			if((rc<n)&&(Heap[rc]<Heap[j]))
				j=rc;
			if(Heap[pos]<Heap[j])
				return ;
			swap(Heap,pos,j);
			pos = j;
		}
	}
	void siftup(int pos){
		while(pos!=0){
			int p=parent(pos);
			if(Heap[p]<Heap[pos])
				return ;
			swap(Heap,pos,p);
			pos=p;
		}
	}
public:
	heap(E*h, int num, int max){
		Heap=h; n=num; maxsize=max; 
		buildHeap();
	}
	int size() const{
		return n;	
	}
	bool isLeaf(int pos) const{
		return (pos>=n/2) && (pos<n);
	}
	int leftchild(int pos) const{
		return 2*pos+1;
	}
	int rightchild(int pos) const{
		return 2*pos+2;
	}
	int parent(int pos) const{
		return (pos-1)/2;
	}
	void buildHeap(){
		for(int i=n/2-1; i>=0; i--)
			siftdown(i);
	}
	
	void insert (const E& it){
		Assert(n<maxsize,"Heap is full");
		int curr = n++;
		Heap[curr]=it;
		while((curr!=0)&&(Heap[curr]<Heap[parent(curr)])){
			swap(Heap,curr,parent(curr));
			curr = parent(curr);
		}
	}
	E removefirst(){
		Assert(n>0,"Heap is empty");
		swap(Heap,0,--n);
		if(n!=0)
			siftdown(0);
		return Heap[n];
	}
	E remove(int pos){
		Assert((pos>=0)&&(pos<n),"Bad position");
		if(pos==(n-1))
			n--;
		else{
			swap(Heap,pos,--n);
			while((pos!=0)&&(Heap[pos]<Heap[parent(pos)])){
				swap(Heap,pos,parent(pos));
				pos=parent(pos);
			}
			if(n!=0)
				siftdown(pos);
		}
		return Heap[n];
	}	
	void show(){
		for(int i=0;i<n;i++)
			if(i==n-1)
				cout << Heap[i];
			else
				cout << Heap[i] << "  ";
	}
	void pre(){
		while(n!=0){
			if(n==1)
				cout << Heap[0];
			else
				cout << Heap[0] << "  ";
			removefirst();
			pre();
		}
//		cout << Heap[0];
	}
};

class Rational{
	friend Rational operator - (Rational &r1,Rational &r2); //根据减法来重载其它运算符 
	friend bool operator > (Rational &r1,Rational &r2); //重载">"运算符 
	friend bool operator < (Rational &r1,Rational &r2); //重载"<"运算符 
	friend bool operator >= (Rational &r1,Rational &r2); //重载">="运算符 
	friend bool operator <= (Rational &r1,Rational &r2); //重载"<="运算符 
	friend bool operator == (Rational &r1,Rational &r2); //重载"=="运算符
	friend bool operator != (Rational &r1,Rational &r2); //重载"!="运算符 
	friend istream& operator >>(istream&,Rational &);  //重载输入运算符 
	friend ostream& operator <<(ostream&,Rational &);  //重载输出运算符 
public:
	int N; //分子
	int D; //分母 
		 
	Rational() {}  //default constructor
   	Rational(int n){
		N=n;
		D=1;
		normalize();   
	} //constructor for integer value
   	Rational(int n,int d){ //normal constructor
		N = n;
		D = d;
		normalize();
	}
   	Rational(const Rational& r){
		N=r.N;
		D=r.D;
	} //copy constructor
   	Rational& operator=(const Rational& r) {
   		N=r.N;
   		D=r.D;
   		return *this;
	} // assignment override

	int gcd(int a,int b){
		return b?gcd(b,a%b):a;
	} 
	
	void normalize(); //将分数化为最简式函数 
	
};

void Rational::normalize(){ 
	if(D<0){ //保证分母大于0 
		N *= -1;
		D *= -1;
	}
	int a = abs(N);
	int b = abs(D);
	int gcd_ab = gcd(a,b); //求分子、分母的最大公约数 
	
	//分子、分母分别除以最大公约数，得到最简式 
	N /= gcd_ab;  
	D /=gcd_ab; 
} 


Rational operator - (Rational &x,Rational &y){
	int a = x.N;
	int b = x.D;
	int c = y.N;
	int d = y.D;

	int e = a*d-c*b;
	int f = b*d;
	return Rational(e,f);
}



bool operator > (Rational &x,Rational &y){
	Rational p = x-y;
	return p.N > 0;
}

bool operator < (Rational &x,Rational &y){
	Rational p = x-y;
	return p.N < 0;
}

bool operator >= (Rational &x,Rational &y){
	Rational p = x-y;
	return p.N >= 0;
}

bool operator <= (Rational &x,Rational &y){
	Rational p = x-y;
	return p.N <= 0;
}

bool operator != (Rational &x,Rational &y){
	Rational p = x-y;
	return p.N <= 0;
}
bool operator == (Rational &x,Rational &y){
	Rational p = x-y;
	return p.N == 0;
}

istream& operator >> (istream& in,Rational &obj){
	cout << "输入分子：";
	in >> obj.N;
	cout << "输入分母："; 
	in >> obj.D;
	return in;
}
ostream& operator << (ostream& out,Rational &obj){
	if(obj.N==0)
		out << obj.N;
	if(obj.D==1)
		out << obj.N;
	else
		out << obj.N << '/' << obj.D;
	return out; 
}
int main(){
//	Rational r1(3,2);
//	Rational r2(1,3);
//	Rational r3(4,2);
//	Rational r4(12,10);
//	Rational r5(4,6);
//	Rational a[5]={r1,r2,r3,r4,r5};
//	heap <Rational> h(a,5,10);
	int m;
	cin >> m;
	Rational r[m];
	int n,d;
	int cnt=0;
	while(m--){
		cin >> n >> d;
		r[cnt].N=n;
		r[cnt].D=d;
		r[cnt++].normalize();
	}
	heap <Rational> h(r,cnt,100);
	h.show();
	cout << endl;
	h.pre();
	return 0;
}
