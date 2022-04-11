#include<iostream>
#include<cstring>
#include<string>
#define maxd 1000+5
#define maxm 100000+5
using namespace std;
string s;
int main(){
	int n;
	cin>>n;		//非常非常简单的模拟
	cin>>s;
	int maxnm=-1;
	s=s+s+s;  	//模拟环装的项链 
	for(int i=n;i<2*n;i++){
		int ans1=0,ans2=0;
		char c=s[i],d=s[i+1];
		for(int j=0;j<n;j++){
			if(s[i-j]=='w'){
				ans1++;
			}
			else if(s[i-j]==c){
				ans1++;
			}
			else break;
		}
		for(int j=0;j<n;j++){
			if(s[i+j+1]=='w'){
				ans2++;
			}
			else if(s[i+j+1]==d){
				ans2++;
			}
			else break;
		}
		maxnm=max(maxnm,ans2+ans1);
	}
	cout<<min(n,maxnm);	//最大只能为n 
    return 0;
}
