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
	printf("������һ����������\n");
	scanf ("%d",&num);
	if (isPrime (num))
		printf("%d��һ������",num);
	else
		printf("%d����һ������",num); 
	
	return 0;
}	
	
