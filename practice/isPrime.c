#include <stdio.h>
#include <math.h>
int isPrime(int num)
{
	int i,j,flag;
	j=(int)sqrt(num);
	for (i=2;i<=j;i++)
	{
		if (num%i==0)
		{
			flag=0;
			break;
		}
	}
	if (i>j)
	{	
		flag=1;		
	}	
	return flag;
}
int main()
{
	int num;
	printf("请输入一个正整数：\n");
	scanf ("%d",&num);
	if (isPrime (num))
		printf("%d是一个素数",num);
	else
		printf("%d不是一个素数",num); 
	
	return 0;
}	
	
