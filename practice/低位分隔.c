/*
��дһ��������һ���������ĸ�λ���ִӵ�λ����λ�ֽ⿪
���� 123���ֽ�Ϊ 3 2 1�� ����д���������в���
*/
#include <stdio.h>
void divide(int n);		//���������� 
int main()
{
	int num;
	printf("Please in put a number:");
	scanf("%d",&num);
	divide(num);
	return 0;
} 
void divide(int n)
{
	while(n/10>0)
	{
		printf("%d ",n%10);	//������һλ���֡� 
		n/=10;				//ȥ�����һλ�� 
	}
	printf("%d",n);
}
