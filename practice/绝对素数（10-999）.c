/*
将自然数区间10-1000中所有绝对素数挑选出来，每行打印输出5个。
绝对素数是：一个数和其反序数都是素数，
例如13和31都是素数，所以13是绝对素数。
*/
#include <stdio.h>
#include <math.h>
int isPrime(int num);//判断素数的函数  声明 
int main()
{
	int num;//遍历10-999间的数 
	int t;//倒序用转换变量 
	int i=0;//每行五个 
	for (num=10;num<1000;num++)
	{
		if (isPrime(num))
		{
			if(num<100)//分位数进行倒序 
			{
				t=num%10*10+num/10;
				if (isPrime(t))
				{
					if(i!=0&&i%5==0)
					{
						printf("\n");
					}
					printf("%d	",num);
					i++; 
				}
			}
			else if(num<1000)
			{
				t=num%10*100+num/10%10*10+num/100;//容易出错，多次调试出来的。 
				if (isPrime(t))
				{
					if(i%5==0)
					{
						printf("\n");
					}
					printf("%d	",num);
					i++;
				}
			}
		}
	}
	return 0;
}
int isPrime(int num)//是素数的话返回结果1；不是的话返回结果0. 
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
