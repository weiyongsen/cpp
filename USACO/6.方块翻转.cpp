#include<cstdio>
#include<stack>
#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>
#include<set>
#include<string>
#include<cstring> 
#include<map>//CV大法好，用过都说爽
#include<vector>
const int inf=2e9;
using namespace std;
char s[15][15],t[15][15],temp[15][15],s1[15][15],s2[15][15],s3[15][15];
int n;
bool cnt=true;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i]+1;
	for(int i=1;i<=n;i++) cin>>t[i]+1;
	memcpy(s1,s,sizeof(s));
	memcpy(s2,s,sizeof(s));
	memcpy(s3,s,sizeof(s));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp[j][n-i+1]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i][j]!=t[i][j]){
				cnt=0;
				break;
			}
		}
	}
	if(cnt){
		printf("1\n");
		return 0;
	}//90
	
	cnt=1;
	memcpy(s,temp,sizeof(s));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp[j][n-i+1]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i][j]!=t[i][j]){
				cnt=0;
				break;
			}
		}
	}
	if(cnt){
		printf("2\n");
		return 0;
	}//180
	
	cnt=1;
	memcpy(s,temp,sizeof(s));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp[j][n-i+1]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i][j]!=t[i][j]){
				cnt=0;
				break;
			}
		}
	}
	if(cnt){
		printf("3\n");
		return 0;
	}//270
	
	cnt=1;
	memcpy(s,s1,sizeof(s1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp[i][n-j+1]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i][j]!=t[i][j]){
				cnt=0;
				break;
			}
		}
	}
	if(cnt){
		printf("4\n");
		return 0;
	}//fan
	
	cnt=1;
	memcpy(s,temp,sizeof(s));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp[j][n-i+1]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i][j]!=t[i][j]){
				cnt=0;
				break;
			}
		}
	}
	if(cnt){
		printf("5\n");
		return 0;
	}//90
	
	cnt=1;
	memcpy(s,temp,sizeof(s));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp[j][n-i+1]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i][j]!=t[i][j]){
				cnt=0;
				break;
			}
		}
	}
	if(cnt){
		printf("5\n");
		return 0;
	}//180
	
	cnt=1;
	memcpy(s,temp,sizeof(s));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp[j][n-i+1]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i][j]!=t[i][j]){
				cnt=0;
				break;
			}
		}
	}
	if(cnt){
		printf("5\n");
		return 0;
	}//90
	
	cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s1[i][j]!=t[i][j]){
				cnt=0;
				break;
			}
		}
	}
	if(cnt){
		printf("6\n");
		return 0;
	}//90
	printf("7\n");
	/*for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)
			cout<<temp[i][j];
		*///cout<<endl;
	//}*/
    return 0;
}
