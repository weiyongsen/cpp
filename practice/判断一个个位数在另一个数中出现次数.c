/*
����һ��������number��һ������digit��0-9����
ͳ�Ʋ����number��digit���ֵĸ�����
Ҫ���庯��countDigit��number,digit��ʵ�֣�
��������10090 0������ú���countDigit(10090,0)����10090��0�ĸ�����
*/
#include <stdio.h>
int countDigit(int number, int digit);//�������� 
int main()
{
	int number,digit;
	printf("Please in put number&digit(���ŷָ�):");
	scanf("%d,%d",&number,&digit);
	printf("%d������%d��",digit,countDigit(number,digit)); 
	return 0;
}
int countDigit(int number, int digit)
{
	int count;
	while (number/10>0)
	{
		if(number%10==digit)//�ж�ÿһλ�ϵ����Ƿ��digit��ȡ� 
		{
			count++;
		}
		number/=10;			//����num��λ���� 
	}
	return count;
}
