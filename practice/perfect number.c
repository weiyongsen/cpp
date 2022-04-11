/*找出200以内的所有完数，并输出其因子。   1可以除外。。（但是在这里打印出了） 
例如，6=1+2+3，其中1,2,3是因子，6为因子之和。*/
#include <stdio.h>
int main()
{
	int num,factor,i,j;    //i表示因子相加，j表示确定完数之后再找出的因子 。 
	for (num=1;num<=200;num++)   //遍历200个数，找出完数。 
	{
		if (num==1)          //如果是一直接打印 
		{
			printf("1=1\n");
		}
		for (factor=1,i=0;factor<num;factor++)   //每次对i初始化，根据每轮循环最后i的值找出完数 。 
		{
			if (num%factor==0)
			{
				i=i+factor;
			}
		}
		if (i==num)            //对找出的完数再进行因子分解 。 
		{
			printf("%d=1",num);         //因为因子“1”和“+”位置的缘故，先打印出“num”=“1”后面再加上其他因子 
			for (j=2;j<num;j++)         //遍历该数，找出因子。 
			{
				if (num%j==0)
				{
					printf("+%d",j);    //打印出“+因子 ”形式 。 
				}
			}
		printf("\n");   //每个完数写完， 换一次行。 
		}
	}
	return 0;
}
