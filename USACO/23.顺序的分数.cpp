#include <bits/stdc++.h> 
const int inf=2>>31-1;
using namespace std;
struct node{
	char s[20];
	double k;
}kkk[20000];
bool vis[200][200];
bool cmp(node p,node q){
	return p.k<q.k;
}
int main(){
	int n;
	int cnt=1;
	cin>>n;
	kkk[0].s[0]='0';
	kkk[0].s[1]='/';
	kkk[0].s[2]='1';
	kkk[0].k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int x=i,y=j;
			int r=__gcd(x,y);
			x/=r,y/=r;
			if(vis[y][x]) continue;
			vis[y][x]=true;
			kkk[cnt].k=y*1.0/x;
			sprintf(kkk[cnt].s,"%d/%d",y,x);
			cnt++;
		}
	}
	sort(kkk,kkk+cnt,cmp);
	for(int i=0;i<cnt;i++){
		printf("%s\n",kkk[i].s);
	}
    return 0;
}
