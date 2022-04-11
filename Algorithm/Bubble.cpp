#include <bits/stdc++.h>
using namespace std;

void bubble(int *a,int n){
	int i,j;
	int temp;
	for(i=1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void bubble2(int *a,int n){
	int j,j;
	int temp;
	bool flag=1;
	for(int i=1;i<n&&flag;i++){
		flag=0;
		for(int j=n-1;j>=i;j--){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
	}
}
int main(){
	
	
	return 0;
} 
