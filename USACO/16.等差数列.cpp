#include <bits/stdc++.h>
#define maxd 1000+5
using namespace std;
bool jud[250*500+10];
struct node{
	int a,b;
}wei[5000+5];
int tot=0;
bool cmp(node p,node q){
	if(p.b==q.b) return p.a<q.a;
	else return p.b<q.b;//先按b排再按a排 
	
}
int main(){
	int n,m;
	cin>>n>>m;
	int lim=m*m*2; 
	for(int i=0;i<=m;++i){
		for(int j=0;j<=m;++j){
			jud[i*i+j*j]=1;
		}
	}//寻找双平方数 
	/*for(int i=0;i<=lim;++i){
		if(jud[i])
		cout<<i<<" ";
	}*/
	for(int i=0;i<=lim;++i){
		
		if(jud[i]){
			
			for(int j=i+1;j<=lim;++j){
				if(jud[j]){
					//cout<<j;
					int cnt=1;
					int d=j-i;
					int maxm=j+d*(n-2);//数列最大项若不在范围内，则直接跳过 
					if(maxm>lim) break;
					for(int k=j+d;k<=maxm;k+=d){
						//cout<<k<<" ";
						if(!jud[k]){
							cnt=0;
							break;
						}
					}
					//cout<<cnt;
					if(cnt){
						//cout<<i<<" "<<d<<endl;
						wei[tot].a=i;
						wei[tot].b=d;
						tot++;
					}
					
				}
				//cout<<j<<" ";
			}
		}
		
		//cout<<i<<" ";
	}
	if(tot){
		sort(wei,wei+tot,cmp);
		for(int i=0;i<tot;++i){
			printf("%d %d\n",wei[i].a,wei[i].b);
		}
	}
	else cout<<"NONE";
    return 0;
}
