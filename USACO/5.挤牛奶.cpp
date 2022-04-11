#include<cstdio>
#include<stack>
#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>
#include<set>
#include<string>
#include<cstring> 
#include<map>
#include<cmath> 
#include<vector>
#define maxm 805
//const int inf=2147483647;
const int inf=1e9;
using namespace std;
int n;
struct node{
	int begin;
	int end;
}kkk[5005];
bool cmp(node p,node q){
	return p.begin<q.begin;
}
int main()
{	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>kkk[i].begin>>kkk[i].end;
	}
	sort(kkk,kkk+n,cmp);
	
	int one=0,none=0,begin=kkk[0].begin,end=kkk[0].end;
	for(int i=1;i<n;i++){
		if(kkk[i].begin<=end) end=max(end,kkk[i].end);
		else{
			one=max(one,end-begin);
			none=max(none,kkk[i].begin-end);
			begin=kkk[i].begin;
			end=kkk[i].end;
		}
		//cout<<i<<" "<<one<<" "<<none<<endl;
	}
	one=max(one,end-begin);
	cout<<one<<" "<<none;
    return 0;
}
