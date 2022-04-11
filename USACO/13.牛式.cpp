#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#define maxd 1000+5
#define maxm 100000+5//dijkstra堆优化+反向建边 
using namespace std;
int sum[10];
int cnt[10];
bool cmp(int n){
	while(n){
		if(!cnt[n%10]) return false;
		n/=10;
	}
	return true;
}
int main(){
	memset(cnt,0,sizeof(cnt));
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sum[i];
		cnt[sum[i]]=1;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){//暴力解决一切
			for(int k=0;k<n;k++){
				for(int l=0;l<n;l++){
					for(int m=0;m<n;m++){
						int first=sum[i]*100+sum[j]*10+sum[k];
						int second=sum[l]*10+sum[m];
						/*if(first==222&&second==22) {
							printf("%d %d %d %d %d",first,second,first*sum[l],first*sum[m],second*first);
							break;
						}*/
						//cout<<first<<endl;
						if(first*sum[l]<=999 && cmp(first*sum[l]) && second*first<=9999 &&first*sum[m]<=999&& cmp(first*sum[m]) && cmp( second*first ) )
							ans++;
					}
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
