#include <bits/stdc++.h>
using namespace std;

class Rational{
	friend Rational operator + (Rational &,Rational &); //重载加法运算 
	friend Rational operator - (Rational &,Rational &); //重载减法运算 
	friend Rational operator * (Rational &,Rational &); //重载乘法运算 
	friend Rational operator / (Rational &,Rational &); //重载除法运算
	
	friend bool operator > (Rational &,Rational &); //重载">"运算符 
	friend bool operator < (Rational &,Rational &); //重载"<"运算符 
	friend bool operator >= (Rational &,Rational &); //重载">="运算符 
	friend bool operator <= (Rational &,Rational &); //重载"<="运算符 
	friend bool operator == (Rational &,Rational &); //重载"=="运算符
	friend bool operator != (Rational &,Rational &);
	friend istream& operator >>(istream&,Rational&);
	friend ostream& operator <<(ostream&,Rational &); //重载输出运算符 
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

Rational operator + (Rational &x,Rational &y){
	int a = x.N;
	int b = x.D;
	int c = y.N;
	int d = y.D;

	int e = a*d+c*b;
	int f = b*d;
	return Rational(e,f);
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

Rational operator * (Rational &x,Rational &y){
	int a = x.N;
	int b = x.D;
	int c = y.N;
	int d = y.D;
	int e = a*c;
	int f = b*d;
	return Rational(e,f);
}

Rational operator / (Rational &x,Rational &y){
	int a = x.N;
	int b = x.D;
	int c = y.N;
	int d = y.D;
	int e = a*d;
	int f = b*c;
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


