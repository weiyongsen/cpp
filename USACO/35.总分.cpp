#include<cstdio>
#include<string>//完全背包问题 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
const int inf=2>>31-1;
using namespace std;
int m,n;
int value[10005],weight[10005];
int dp[10005];
int main()
{	
	memset(dp,inf,sizeof(dp));
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>value[i]>>weight[i];
	}
	for(int i=0;i<n;i++){
		for(int j=weight[i];j<=m;j++){
			dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
