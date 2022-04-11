#include <bits/stdc++.h>
using namespace std;
void swap(int a[],int op)
{
	if(op==1)
	{
		for(int i=0;i<6;i++)
		{
			a[i]=(a[i]+1)%2;
		}
	}
	if(op==2)
	{
		for(int i=0;i<6;i+=2)
		{
			a[i]=(a[i]+1)%2;
		}
	}
	if(op==3)
	{
		for(int i=1;i<6;i+=2)
		{
			a[i]=(a[i]+1)%2;
		}
	}
	if(op==4)
	{
		for(int i=1;i<=6;i=3*i+1)
		{
			a[i-1]=(a[i-1]+1)%2;
		}
	}	
}
void check(int x[],int y[],int a[],int p,int q,int n, int *cnt)
{
		for(int i=0;i<p;i++)
		{
			if(a[(x[i]-1)%6]!=1)
			{
				break;
			}
			for(int i=0;i<n;i++)
				cout << a[i%6];
			cout << endl;
			*cnt=*cnt+1;
		}
		for(int i=0;i<q;i++)
		{
			if(a[(y[i]-1)%6]!=0)
			{
				break;
			}
			for(int i=0;i<n;i++)
				cout << a[i%6];	
			cout << endl;
			*cnt++;
		}
}
int main()
{
	int n,c,cnt=0;
	cin >> n >> c;
	int a[n],x[n],y[n];
	for(int i=0;i<n;i++)
	{
		a[i]=1;
	}
	memset(a,0,sizeof(a));
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	int l=0,m=0;
	int p=0,q=0;
	while(1)
	{
		cin >> l;
		if(l<0)
			break;
		x[p++]=1;		//最后亮的灯 
	}
	while(1)
	{
		cin >> m;
		if(m<0)
			break;
		y[q++]=m;		//最后灭的灯 
	}
//	for(int i=0;i<n;i++)
//		cout << a[i%6] << " ";	
	for(;c>4;c-=2);
	if(c==1)
	{
		swap(a,1);check(x,y,a,p,q,n,&cnt);swap(a,1);
		swap(a,2);check(x,y,a,p,q,n,&cnt);swap(a,2);
		swap(a,3);check(x,y,a,p,q,n,&cnt);swap(a,3);
		swap(a,4);check(x,y,a,p,q,n,&cnt);swap(a,4);
		if (cnt==0) cout << "IMPOSSIBLE";
	}	
	if(c==2)
	{
		swap(a,1);check(x,y,a,p,q,n,&cnt);swap(a,1);
		swap(a,2);check(x,y,a,p,q,n,&cnt);swap(a,2);
		swap(a,3);check(x,y,a,p,q,n,&cnt);swap(a,3);
		swap(a,4);check(x,y,a,p,q,n,&cnt);swap(a,4);
		swap(a,1);swap(a,2);check(x,y,a,p,q,n,&cnt);swap(a,2);swap(a,1);
		swap(a,1);swap(a,3);check(x,y,a,p,q,n,&cnt);swap(a,3);swap(a,1);
		swap(a,1);swap(a,4);check(x,y,a,p,q,n,&cnt);swap(a,4);swap(a,1);
		swap(a,2);swap(a,3);check(x,y,a,p,q,n,&cnt);swap(a,3);swap(a,2);
		swap(a,2);swap(a,4);check(x,y,a,p,q,n,&cnt);swap(a,4);swap(a,2);
		swap(a,3);swap(a,4);check(x,y,a,p,q,n,&cnt);swap(a,4);swap(a,3);
		if (cnt==0) cout << "IMPOSSIBLE";
	}
	
	return 0;
 } 
