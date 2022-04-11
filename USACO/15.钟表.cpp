#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>//暴力出奇迹 
#define maxd 500+5
using namespace std;
int a[10];
int b[10];
int main(){
	for(int i=1;i<=9;i++){
		int k;
		cin>>k;
		a[i]=k/3;
	}
	for(b[1]=0;b[1]<4;b[1]++)
	for(b[2]=0;b[2]<4;b[2]++)
	for(b[3]=0;b[3]<4;b[3]++)
	
	for(b[4]=0;b[4]<4;b[4]++)
	for(b[5]=0;b[5]<4;b[5]++)
	for(b[6]=0;b[6]<4;b[6]++)
	
	for(b[7]=0;b[7]<4;b[7]++)
	for(b[8]=0;b[8]<4;b[8]++)
	for(b[9]=0;b[9]<4;b[9]++){
		if(
			((b[1]+b[2]+b[4])%4==4-a[1])       &&
			((b[1]+b[2]+b[3]+b[5])%4==4-a[2])    &&
			((b[2]+b[3]+b[6])%4==4-a[3])	     &&
			((b[1]+b[4]+b[5]+b[7])%4==4-a[4])    &&
			((b[1]+b[3]+b[5]+b[7]+b[9])%4==4-a[5]) &&
			((b[3]+b[5]+b[6]+b[9])%4==4-a[6])    &&
			((b[4]+b[7]+b[8])%4==4-a[7])	     &&
			((b[5]+b[7]+b[8]+b[9])%4==4-a[8])    &&
			((b[6]+b[8]+b[9])%4==4-a[9])	
		){
			int flag=1; 		//控制输出格式，第一个无空格 
			for(int i=1;i<=9;i++){
				if(b[i]){
					for(int j=0;j<b[i];j++){
						if(flag){
							flag=0;
							printf("%d",i);
						}
						else{
							printf(" %d",i);
						}
					}
				}
			}
			return 0;
		}
	}
    return 0;
}
