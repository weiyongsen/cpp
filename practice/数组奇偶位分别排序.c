#include <stdio.h>
#include <stdio.h> 
#include <time.h>
#define N 20
void bubble(int a[],int n);
int findmax(int a[],int n);	//�����ֵ���±� 
int main()
{
	int i,arr[N];  
	int m,n,t;  
	int j[10],o[10];	//��żλ������ 
	srand((unsigned) time(NULL));
	for(i=0;i<N;i++) 
	{
		arr[i]=rand()%1000;  //���� 
	}
	for(i=0;i<N;i++)  
	{
		if(i%10==0)
			printf("\n"); 
		printf("%4d", arr[i]); //������� 
	}
	printf("\n���Ԫ���½Ǳ������%d\n",findmax(arr,N));
	for(i=0,m=0,n=0;i<N;i++)
	{
		if(i%2==0)
		{
			j[m]=arr[i];
			m++;
		}
		else
		{
			o[n]=arr[i];
			n++;
		}
	}
	bubble (j,10);
	bubble (o,10);
	printf("����λ����ż��λ�������У�\n");
	for(i=0;i<10;i++)
	{
		if(i%5==0)
		printf("\n");
		printf("%4d%4d",j[9-i],o[i]);
	}
	printf("\n");

	return 0;
}
int findmax(int a[],int n)
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
	return maxn;
}
void bubble(int a[],int n) 
{ 	int i,j,t;
	for(i=0;i<n -1;i++)
		for(j=1;j<n-i;j++)
			if(a[j]<a[j-1])
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
}
