/*
����Ȼ������10-1000�����о���������ѡ������ÿ�д�ӡ���5����
���������ǣ�һ�������䷴��������������
����13��31��������������13�Ǿ���������
*/
#include <stdio.h>
#include <math.h>
int isPrime(int num);//�ж������ĺ���  ���� 
int main()
{
	int num;//����10-999����� 
	int t;//������ת������ 
	int i=0;//ÿ����� 
	for (num=10;num<1000;num++)
	{
		if (isPrime(num))
		{
			if(num<100)//��λ�����е��� 
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
				t=num%10*100+num/10%10*10+num/100;//���׳�����ε��Գ����ġ� 
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
int isPrime(int num)//�������Ļ����ؽ��1�����ǵĻ����ؽ��0. 
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
