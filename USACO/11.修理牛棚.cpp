#include<cstdio>
#include<stack>
#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>
#include<set>
#include<string>
#include<cstring> 
#include<map>
#include<cmath> 
#include<vector>
#define maxm 805
//const int inf=2147483647;
const int inf=1e9;
using namespace std;
int m,s,c;//木板，牛棚，牛 
int cow[205];
bool cmp(int a,int b){
	return a>b;
} 
int main()
{
	cin>>m>>s>>c; 
	for(int i=0;i<c;i++) cin>>cow[i];
	sort(cow,cow+c);
	//for(int i=0;i<c;i++) cout<<cow[i]<<" ";
	if(m>=c){
		printf("%d",c);
	}//每个牛都能有一块木板 
	else{//反向思考，  逐个减去两牛棚相距最远的 
		int sum=cow[c-1]-cow[0]+1;
		//cout<<sum<<endl;
		int sen[205];
		for(int i=0;i<c-1;i++){
			sen[i]=cow[i+1]-cow[i];
		}
		//一块木板分成n块需要n-1次 
		sort(sen,sen+c-1,cmp);
		/*for(int i=0;i<c-1;i++){
			cout<<sen[i]<<" ";
		}*/
		for(int i=0;i<m-1;i++) {
			sum-=sen[i]-1;
		}
		cout<<sum;
	}
    return 0;
}
