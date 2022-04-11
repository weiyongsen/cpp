//函数求数组的最大值 
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int max(int *v,int m,int b);
void printfarr(int *v,int m, int n);
const int M=3,N=4;
int main()
{
	int a[M][N],i,j;
	srand(time(NULL));
	for (i=0;i<M;i++)
		for(j=0;j<N;j++)
			a[i][j]=rand()%1000;
	cout << "the maximum is: " << max(a[0],M,N) << endl;
	cout << "the arry is:" << endl;
	printfarr(*a,M,N);
}
int max(int *v,int m,int n)
{
	int i,j,maxv;
	maxv=v[0];
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			if(v[i*n+j]>maxv)
				maxv=v[i*n+j];
	return maxv;
}
void printfarr(int *v,int m,int n)
{
	int i,j;
	for (i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout << setw(5) << v[i*n+j] ;
		cout << endl;
	} 	
}
