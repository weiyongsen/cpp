#include <stdio.h>
int perfect(int n);   //完数函数声明 
void print(int m);    //输出函数声明 
int main()
{
	int num;
	for (num=1;num<1000;num++)   //一千以内的完数。 
	{
		if (perfect(num))
		{
			printf("%d is a perfect number.\n\t",num);
			print(num);
			printf("\n");   //美化格式 
		}
	}
	return 0;
 } 
int perfect(int n)
{
	int i,j;  //i是找出的每个因子，j是所有因子的和 。 
	if (n==1)
		return 1;
	for (i=1,j=0;i<n;i++)
	{
		if(n%i==0)
			j=j+i;
	}
	if (n==j)
		return 1;
	else 
		return 0;
}
void print(int m)
{
	printf("%d=1",m);   //首先打印出“num=1...”的格式。 
	int k;              //因子 
	for(k=2;k<m;k++)
	{
		if(m%k==0)
			printf("+%d",k);   //打印出“+factor”的格式。 
	}
}
