#include<bits/stdc++.h> 
const int inf=2e9;
using namespace std;
int n;
bool isprime(int x){
	if(x==1) return false;
	if(x==2) return true;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int prime[5]={1,3,5,7,9};


void dfs(int sum,int k,int n){//当前数字 和 位数
	//printf("%d %d\n",k,n);
	if(k==n) {
		cout<<sum<<endl;
		return ;
	}
	else{
		int sum2=0;
		for(int i=0;i<5;i++){
			sum2=sum*10+prime[i];
		//cout<<sum2<<" "; 
			if(isprime(sum2))
				dfs(sum2,k+1,n);
		}
	}
}
int main(){
	int n;
	cin>>n;
	dfs(2,1,n);
	dfs(3,1,n);
	dfs(5,1,n);
	dfs(7,1,n);
    return 0;
}
