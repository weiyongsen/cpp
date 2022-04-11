/*
编写一个函数将一个正整数的各位数字从低位到高位分解开
比如 123，分解为 3 2 1， 并编写主函数进行测试
*/
#include <stdio.h>
void divide(int n);		//函数声明。 
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
		printf("%d ",n%10);	//输出最后一位数字。 
		n/=10;				//去掉最后一位。 
	}
	printf("%d",n);
}
