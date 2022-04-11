/*
读入一个正整数number和一个数字digit（0-9），
统计并输出number中digit数字的个数。
要求定义函数countDigit（number,digit）实现，
例如输入10090 0，则调用函数countDigit(10090,0)计算10090中0的个数。
*/
#include <stdio.h>
int countDigit(int number, int digit);//函数声明 
int main()
{
	int number,digit;
	printf("Please in put number&digit(逗号分隔):");
	scanf("%d,%d",&number,&digit);
	printf("%d出现了%d次",digit,countDigit(number,digit)); 
	return 0;
}
int countDigit(int number, int digit)
{
	int count;
	while (number/10>0)
	{
		if(number%10==digit)//判断每一位上的数是否和digit相等。 
		{
			count++;
		}
		number/=10;			//缩减num的位数。 
	}
	return count;
}
