#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
bool runnian(int n){
	if( n%400==0 || ( n%100 &&(n%4==0) ) ) return 1;//是闰年 
	else return 0;
}
const int maxn=400+10;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//int b[500][12];//调试用 
int shu[8];
int main()
{
	int n;
	cin>>n;
	int begin=6;
    for(int i=0;i<n;i++){
    	if(!runnian(1900+i)){
    		for(int j=0;j<12;j++){
    			//b[i][j]=begin;
    			shu[begin]++;
    			begin+=a[j]%7;
    			if(begin>7) begin%=7;
			}
		}
		else{
			for(int j=0;j<12;j++){
				if(j!=1){
    				//b[i][j]=begin;
    				shu[begin]++;
    				begin+=a[j]%7;
    				if(begin>7) begin%=7;
    			}
				else{
					//b[i][j]=begin;
					shu[begin]++;
    				begin+=1;
    				if(begin>7) begin%=7;
				}
			}
		}
	}
	printf("%d %d",shu[6],shu[7]);
	for(int i=1;i<=5;i++) printf(" %d",shu[i]);
	/*printf("\n\n");
	for(int j=0;j<n;j++) {
		for(int i=0;i<12;i++) 
			cout<<" "<<b[j][i];
		cout<<endl;
	}*/
    return 0;
}
