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
int b;
const int inf=1e9;
char jinzhi[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};//ÓÃ´óÐ´ 
using namespace std;
int main()
{
	cin>>b;
	for(int i=1;i<=300;i++){
		int j=i*i;
		int k=i;
		int cnt1=0;
		int cnt2=0;
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
		//printf("%s %s\n",s,sf);
		
		while(j){
			fang[cnt2++]=jinzhi[j%b];
			j/=b;
		}
		fang[cnt2]='\0';
		for(int wei=0;wei<cnt2;wei++){
			fangf[wei]=fang[cnt2-1-wei];
		}
		fangf[cnt2]='\0';
		//printf("%s %s\n",fang,fangf);
		if(!strcmp(fang,fangf)){
			printf("%s %s\n",sf,fangf);
		}
	}
	/*char s[100];
	int cnt1=0,cnt2;
	while(x){
		s[cnt1++]=jinzhi[x%b];
		x/=b;
	}
	s[cnt1]='\0';
	cout<<s;*/
    return 0;
}
