#include <stdio.h>
int sum(int n);    //�������� 
int main()
{
 	int num;
 	printf("������һ������");
 	scanf("%d",&num); 
	printf("��λ����֮����%d",sum(num));
 	return 0;
}
int sum(int n)
{
	int sums=0;
	if(n/10==0)    //�ݹ�������� 
		sums=n;
	else
		sums=n%10+sum(n/10);
	return sums;
}


