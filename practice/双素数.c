/*
�ڶ��ο��ò���
��д������1000���ڵ�˫������˫������ָһ�Բ�ֵΪ2��������
���磬3��5��һ��˫������11��13Ҳ��һ��˫������
����˫���������������ú���ʵ�֣�
main������������˫����������˫������������������������
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
int isPrime(int num)		//�ж�һ�����Ƿ�����
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
int doublePrime(int m)		//�ж�һ������+2�ǲ���һ������ 
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
					return 1; 		//�������������1 
				}
			return 0;//���m֮������ŵ�һ����������m+2���Ϳ����˳����� 
			}
		}
	}
	else
		return 0;
} 



