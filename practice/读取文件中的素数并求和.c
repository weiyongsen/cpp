#include <stdio.h>
#include <math.h>
int isPrime(int num);
int main()
{
	FILE *fa;
	if ((fa=fopen("E:\\xuexi\\C\\作业\\a.dat","rb+"))==NULL)
	{
		printf("cuowu");
		return -1;
	}
	int n;
	int sum=0;
	while((fscanf(fa,"%d",&n))!=EOF)		//读取数字 
	{
		
		if(isPrime(n))
		{
			sum+=n;
			printf("%d\n",n);			
		}	
	}	
	printf("%d",sum);
	fseek(fa,0,2);
	fprintf(fa," %d",sum);		//输出结果到文件 
	fclose(fa);
	return 0;	
}
int isPrime(int num)   			//判断素数函数 
{
	int k;
	k=(int)sqrt(num);
	int i;
	for (i=2;i<=k;i++)
	{
		if(num%i==0)
			return 0;
	}
	if (i>k)
	{
		return 1;
	}
}
