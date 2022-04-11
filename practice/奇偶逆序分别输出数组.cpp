#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<time.h>
#define N 20
int b[10];
int c[10];
void findmax(int a[],int n)
{
	int i,max=a[0],maxn=0;
	for(i=0;i<N;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			maxn=i;
		}
	}
	printf("最大值下标为:%d\n", maxn);
}
void qi(int a[]){
	int kkk=0;
	for(int i=0;i<20;i+=2){
		b[kkk++]=a[i];
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<9-i;j++){
			if(b[j]<b[j+1]){
				int t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
}
void ou(int a[]){
	int kkk=0;
	for(int i=1;i<20;i+=2){
		c[kkk++]=a[i];
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<9-i;j++){
			if(c[j]>c[j+1]){
				int t=c[j];
				c[j]=c[j+1];
				c[j+1]=t;
			}
		}
	}
}
int main()
{
	int i,j,k,arr[N]; 
	srand((unsigned) time(NULL));
	for(i=0;i<N;i++) {
		arr[i]=rand()%1000;
	}
	printf("数组如下:\n") ;
	for(i=0;i<N;i++) {
		printf("%3d",arr[i]);
		if( (i+1)%5 ) printf(" ");
		else printf("\n");
	}
	findmax(arr,N);
	printf("奇数项为：\n"); 
	qi(arr);
	for(i=0;i<10;i++) {
		printf("%3d",b[i]);
		if( (i+1)%5 ) printf(" ");
		else printf("\n");
	}
	ou(arr);
	printf("偶数项为:\n");
	for(i=0;i<10;i++) {
		printf("%3d",c[i]);
		if( (i+1)%5 ) printf(" ");
		else printf("\n");
	}
	return 0;
}

