#include <stdio.h>
#include <math.h>
int isPrime(int num);
int main()
{
	FILE *fa;
	if ((fa=fopen("E:\\xuexi\\C\\��ҵ\\a.dat","rb+"))==NULL)
	{
		printf("cuowu");
		return -1;
	}
	int n;
	int sum=0;
	while((fscanf(fa,"%d",&n))!=EOF)		//��ȡ���� 
	{
		
		if(isPrime(n))
		{
			sum+=n;
			printf("%d\n",n);			
		}	
	}	
	printf("%d",sum);
	fseek(fa,0,2);
	fprintf(fa," %d",sum);		//���������ļ� 
	fclose(fa);
	return 0;	
}
int isPrime(int num)   			//�ж��������� 
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
