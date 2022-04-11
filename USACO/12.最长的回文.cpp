#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#define maxd 1000+5
using namespace std;
char s[40000+5],t[40000+5];
int a[40000+5];
int cnt=0;
int cntt=0;
int huiwen(int x){//从下标x向两侧延伸 
	int ans1=1,ans2=0;
	for(int j=1;j<=x&&j+x<cnt&&t[x-j]==t[x+j];j++) ans1+=2;//奇数延拓 
	for(int i=x,j=x+1;i>=0&&j<cnt&&t[i]==t[j];i--,j++) ans2+=2;//偶数延拓 
	return max(ans1,ans2);
}
int main(){
	int maxm=0,maxx=0;
	while( scanf("%c",&s[cntt++])!=EOF );
	for(int i=0;i<cntt;i++){
		if(s[i]>='A'&&s[i]<='Z'){
			a[cnt]=i;
			t[cnt++]=s[i]-'A'+'a';
		}
		else if(s[i]>='a'&&s[i]<='z'){
			a[cnt]=i;
			t[cnt++]=s[i];
		}
	}
	t[cnt]='\0';
	for(int i=0;i<cnt;i++){
		int lenoi=huiwen(i);
		if(lenoi>maxm){
			maxm=lenoi;
			maxx=i;
		}
	}
	cout<<maxm<<endl;
	if(maxm%2){
		int begin=maxx-maxm/2;
		int end=maxx+maxm/2;
		for(int i=a[begin];i<=a[end];i++){
			cout<<s[i];
		}
	}
	else{
		int begin=maxx-maxm/2+1;
		int end=maxx+maxm/2;
		for(int i=a[begin];i<=a[end];i++){
			cout<<s[i];
		}
	}
    cout<<endl;
    return 0;
}
