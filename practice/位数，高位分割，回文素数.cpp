/*
1,ͳ��������m��λ����
2.�Ӹ�λ��ʼ��λ�ָ������ĸ�λ���֣�
3.��ӡ���0��m֮�����еĻ�������
����������ָ���������Ҷ�����ȫһ��������������11��101��131�ȣ�����ӡʱÿ�����5����
*/
#include <stdio.h>
#include <math.h>
int counts(int num);  //�ж�λ���������� 
int isPrime(int num); //�ж������������� 
int reverse(int rev); //���������������� 
int main()
{
	int num,temp,count;
	int i,j,k; //i��ѭ�����Ʊ�����j�Ǹ�λ�ָ������ÿһ������k���������Ǳ���0-num���á� 
	int row=0;   //����ÿ�����5������������ 
	printf("������һ��������:");
	scanf("%d",&num);
	temp = num;
	count = counts(temp);
	printf ("��.%d��������� %d λ.\n",temp,count);
	printf("��.�Ӹߵ�����λ���:"); 
	for(i=1;i<=count;i++)
	{
		j=temp/(int)pow(10,count-i);   //�õ�temp�����λ ,pow����ֵ��double����Ҫת����int�� 
		printf(" %d ",j);
		temp-=j*(int)pow(10,count-i);  //ȥ��temp�����λ�� 
	}
	printf("\n��.0-%d�Ļ��������У�\n",temp);
	temp = num; //ʹ��temp�ٴε���num��
	for (k=2;k<=temp;k++)
	{
		if(isPrime(k))       //�Ƿ������� 
		{
			if(k==reverse(k))  //�Ƿ������ �� 
				{
					if(row!=0&&row%5==0)  //����һ��5���� 
					{
						printf("\n");
					}
					printf("%d\t",k);
					row++;
				}
				
		 } 
	}
	
	return 0;
}
int counts(int num) //����λ������ �� 
{
	int count=0;
	while(num>0)
	{
		num/=10;
		count++;
	}
	return count;
}
int isPrime(int num) //�ж��Ƿ������� �� 
{
	int a=(int)sqrt(num);
	int i,flag;
	for (i=2;i<=a;i++)
	{
		if(num%i==0)
			return flag=0;
	}
	if (i>a)
		return flag=1;
}
int reverse(int num)//�����������������һ����Ϊ0����������������� �� 
{
	int rev=0;      //��ʼ��rev����Ҫ �� 
	while(num>0)    //��ѭ����numβ����0��ʱ��ʧЧ�����������Ľ�βһ����Ϊ0�� 
	{
		rev=rev*10+num%10;
		num/=10;
	}
	return rev;
}
