#include <bits/stdc++.h>
#define maxm 805
//const int inf=2147483647;
const int inf=1e9;
using namespace std;
int n;//�򵥵�̰�� ��1  2 ����3 ��Ҫ����  
//1���� 2    2���� 1  ȡ�������ֵ 
int a[1005];
int b[105];
int c[105];
int ans=0;
int main()
{	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=0;i<b[1]+b[2];i++){
		if(a[i]==3) c[3]++;
		else if(a[i]==2&&i<b[1]) c[1]++;
		else if(a[i]==1&&i>=b[1]) c[2]++;
	}
	//cout<<c[3];
	cout<<c[3]+max(c[1],c[2]);
    return 0;
}
