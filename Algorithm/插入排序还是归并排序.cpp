#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;  
int n;
int a1[105],a2[105],b[105];
void insertion_sort(int a[],int b[]){
	int flag=0;
	for(int i=2;i<=n;i++){
		sort(a,a+i);
		if(flag){
			printf("Insertion Sort\n");
			printf("%d",a[0]);
			for(int i=1;i<n;i++)
				printf(" %d",a[i]);
			return;
		}
		if(equal(a,a+n,b)) 
			flag=1;
	}
}
void merge_sort(int a[],int b[]){
	int flag=0;
	for(int i=2; ;i*=2){
		for(int j=0;j<n;j+=i)
			sort(a+j,a+(j+i<n?j+i:n));
		if(flag){
			printf("Merge Sort\n");
			printf("%d",a[0]);
			for(int j=1;j<n;j++)
				printf(" %d",a[j]);
			return ;
		}
		if(equal(a,a+n,b)) flag=1;
		if(i>n) break;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a1[i]);
		a2[i]=a1[i];
	}
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	insertion_sort(a1,b);
	merge_sort(a2,b);
	return 0;
} 
