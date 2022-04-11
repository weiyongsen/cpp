//第二小的数 
//一群猴子要选新猴王。新猴王的选择方法是：让N只候选猴子围成一圈，
//从某位置起顺序编号为1~N号。
//从第1号开始报数，每轮从1报到3，
//凡报到3的猴子即退出圈子，
//接着又从紧邻的下一只猴子开始同样的报数。如此不断循环，
//最后剩下的一只猴子就选为猴王。请问是原来第几号猴子当选猴王？
#include <bits/stdc++.h>
using namespace std;

int main(){
	int num;
	cin >> num;
	int a[num];
	for(int i=0;i<num;i++){
		a[i]=i+1;
	}
	int len = num;
	int cnt=0;
	int cur=-1;
	while(len!=1){
		cnt++;
		if(cur==len-1)
			cur=0;
		else{
			cur++;
		}
		
		if(cnt==3){
			cnt=0;
			len--;
			
			for(int i=cur;i<len;i++){
				a[i]=a[i+1];
			}
			cur--;
		}
		
	}
	cout << a[0];
	return 0;
} 
