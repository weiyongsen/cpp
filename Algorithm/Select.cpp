#include <bits/stdc++.h>
using namespace std;
void Select(int *a,int n){
	int i,j,min;
	int temp;
	for(i=1;i<n;i++){
		min=i;
		for(int j=i+1;j<=n;j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		if(i!=min){
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}

int main(){
	
	
	return 0;
} 
