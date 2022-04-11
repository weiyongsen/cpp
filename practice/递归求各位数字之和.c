#include <stdio.h>
int sum(int n);    //函数声明 
int main()
{
 	int num;
 	printf("请输入一个数：");
 	scanf("%d",&num); 
	printf("各位数字之和是%d",sum(num));
 	return 0;
}
int sum(int n)
{
	int sums=0;
	if(n/10==0)    //递归结束条件 
		sums=n;
	else
		sums=n%10+sum(n/10);
	return sums;
}


