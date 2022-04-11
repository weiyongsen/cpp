#include <bits/stdc++.h>
using namespace std;
void shellsort(int *A,int n){
	int dk,i,j;
	for(dk=n/2;dk>=1;dk=dk/2)
		if(A[i]<A[i-dk]){
			A[0]=A[i];
			for(j=i-dk;j>0&&A[0]<A[i];j-=dk)
				A[j+dk]=A[j];
		}
}
int main(){
	
	
	return 0;
} 
