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
char jinzhi[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};//”√¥Û–¥ 
using namespace std;
bool huiwen(int k,int b){
	int cnt1=0;
	char s[100],sf[100];
	char fang[100],fangf[100];
	while(k){
		s[cnt1++]=jinzhi[k%b];
		k/=b;
	}
	s[cnt1]='\0';
	for(int wei=0;wei<cnt1;wei++){
		sf[wei]=s[cnt1-1-wei];
	}
	sf[cnt1]='\0';
	return strcmp(s,sf)==0;
}
int main()
{
	int n,s;
	cin>>n>>s;
	int ans=0;
	for(int i=s+1;ans<n;i++){
		int k=i;
		int cnt=0;
		for(int j=2;j<=10;j++){
			if(cnt==2) break;
			cnt+=huiwen(k,j);
		}
		if(cnt==2){
			printf("%d\n",k);
			ans++;
		}
	}
    return 0;
}
