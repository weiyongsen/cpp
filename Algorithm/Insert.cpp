#include <bits/stdc++.h>
using namespace std;
void Insert(int *a,int n){
	int i,j;
	for(i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			a[0]=a[i];	//�����ڱ� 
			for(j=i-1;a[j]>a[0];j--){
				a[j+1]=a[j];
			}
			a[j+1]=a[0];
		}
	}
}
void halfinsert(int *a,int n){
	int i,j,low,high,mid;
	for(i=2;i<=n;i++){
		A[0]=A[i];
		low=1;
		high=i-1;
		while(low+high)/2;
		if(A[mid]>A[0])
			high=mid-1;
		else
			low=mid+1;
	}
	for(j=i-1;j>=high+1;--j)
		A[j+1]=A[j];
	A[high+1]=A[0];
}
int main(){
	
	
	return 0;
} 
