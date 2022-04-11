/*
第二次课堂测验
编写程序求1000以内的双素数，双素数是指一对差值为2的素数，
例如，3，5是一对双素数，11和13也是一对双素数。
其中双素数和求素数都用函数实现，
main主函数调用求双素数函数，双素数函数调用求素数函数。
*/
#include <stdio.h>
#include <math.h>
int isPrime(int num);
int doublePrime(int m);
int main()
{
	int num;
	for(num=2;num<1000;num++)
	{
		if(doublePrime(num))
		{
			printf("%d,%d\n",num,num+2);
		}
	}
	return 0;
}
int isPrime(int num)		//判断一个数是否素数
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
int doublePrime(int m)		//判断一个素数+2是不是一个素数 
{
	int n;
	if(isPrime(m))
	{
		for(n=m+1;n<1000;n++)
		{
			if(isPrime(n))
			{
				if(n-m==2)
				{
					return 1; 		//如果成立，返回1 
				}
			return 0;//如果m之后紧接着的一个素数不是m+2，就可以退出函数 
			}
		}
	}
	else
		return 0;
} 



