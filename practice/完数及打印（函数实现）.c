#include <stdio.h>
int perfect(int n);   //������������ 
void print(int m);    //����������� 
int main()
{
	int num;
	for (num=1;num<1000;num++)   //һǧ���ڵ������� 
	{
		if (perfect(num))
		{
			printf("%d is a perfect number.\n\t",num);
			print(num);
			printf("\n");   //������ʽ 
		}
	}
	return 0;
 } 
int perfect(int n)
{
	int i,j;  //i���ҳ���ÿ�����ӣ�j���������ӵĺ� �� 
	if (n==1)
		return 1;
	for (i=1,j=0;i<n;i++)
	{
		if(n%i==0)
			j=j+i;
	}
	if (n==j)
		return 1;
	else 
		return 0;
}
void print(int m)
{
	printf("%d=1",m);   //���ȴ�ӡ����num=1...���ĸ�ʽ�� 
	int k;              //���� 
	for(k=2;k<m;k++)
	{
		if(m%k==0)
			printf("+%d",k);   //��ӡ����+factor���ĸ�ʽ�� 
	}
}
