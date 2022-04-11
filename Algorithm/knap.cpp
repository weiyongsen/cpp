#include <bits/stdc++.h>
using namespace std;
/*
物品数量n=5,背包容量c=10,第一个物品重量2,价值6.... 
5 10
2 6
2 3
6 5
5 4
4 6

out:
15
*/

int main(){
	int n,c;
	cin >> n >> c;
	int w[n];
	int v[n];
	for(int i=0;i<n;i++){
		cin >> w[i] >> v[i];
	}
	int dp[n+1][c+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=c;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=w[i-1]&&dp[i-1][j-w[i-1]]+v[i-1]>dp[i-1][j])
				dp[i][j]=dp[i-1][j-w[i-1]]+v[i-1];
		}
	}
	cout << dp[n][c];
	return 0;
}
