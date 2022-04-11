#include <bits/stdc++.h>
using namespace std;

class Rational{
	friend Rational operator + (Rational &,Rational &); //���ؼӷ����� 
	friend Rational operator - (Rational &,Rational &); //���ؼ������� 
	friend Rational operator * (Rational &,Rational &); //���س˷����� 
	friend Rational operator / (Rational &,Rational &); //���س�������
	
	friend bool operator > (Rational &,Rational &); //����">"����� 
	friend bool operator < (Rational &,Rational &); //����"<"����� 
	friend bool operator >= (Rational &,Rational &); //����">="����� 
	friend bool operator <= (Rational &,Rational &); //����"<="����� 
	friend bool operator == (Rational &,Rational &); //����"=="�����
	friend bool operator != (Rational &,Rational &);
	friend istream& operator >>(istream&,Rational&);
	friend ostream& operator <<(ostream&,Rational &); //������������ 
public:
	int N; //����
	int D; //��ĸ 
		 
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
	
	void normalize(); //��������Ϊ���ʽ���� 
	
};

void Rational::normalize(){ 
	if(D<0){ //��֤��ĸ����0 
		N *= -1;
		D *= -1;
	}
	int a = abs(N);
	int b = abs(D);
	int gcd_ab = gcd(a,b); //����ӡ���ĸ�����Լ�� 
	
	//���ӡ���ĸ�ֱ�������Լ�����õ����ʽ 
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
	cout << "������ӣ�";
	in >> obj.N;
	cout << "�����ĸ��"; 
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


