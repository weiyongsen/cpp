#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	map<string,int>mp;
	string s[25],str,t;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		mp[s[i]]=0;
	}
	while(cin>>str){
		int a,b;
		cin>>a>>b;
		mp[str]-=a;
		for(int i=0;i<b;i++){
			cin>>t;
			mp[t]+=a/b;
		}
		if(b!=0){
			mp[str]+=a%b;
		}
	}
	for(int i=0;i<n;i++){
		cout<<s[i]<<" "<<mp[s[i]]<<endl;
	}
    return 0;
}

