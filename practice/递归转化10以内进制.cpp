#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void fun(int n, int r)
{
	if (n==0) return;
	else fun(n/2,r);
	v.push_back(n%2);
}
int reverse(int n){
	int e=0,t=0;
	while(n){
	t=n%10;
	n/=10;
	e=e*10+t;
	}
	return e;
}
	 
int main(){
	int x;
	int sum=0;
	int b=0;
	cin >> x >> b;
	fun(x,b);
	for(int i=0;i<v.size();i++)
		sum=sum*10+v[i];
	cout << sum;
//	cin >> x;
//	cout << reverse(x);
	return 0;
}
