/*
输入两个正整数a和n，求a+aa+…a(n个a)之和.
例如，输入2和3，输出246（2+22+222）。
*/
# include <stdio.h>
# include <math.h>
int main()
{
	printf("请依次输入a和n(用空格分隔):");
	int i,j,a,n;//i，j均为循环控制变量。 
	scanf("%d %d",&a,&n);
	int t = a;//记录a的初始值方便之后操作 。 
	for (i=0;i<n;i++)
	{
		
		a=a+t*pow(10,i)*(n-i); //可以将题目转换成个位，十位，百位等的分别计算后相加。 
	}
	for (i=0;i<n;i++)//i控制输出几个加号。 
	{
		for(j=0;j<=i;j++)//j控制 两个加号之间有几个a 。 
		{
			printf("%d",t);
		}
		printf("+");//注意    最后会多一个加号。 
	} 
	printf("\b");//退格 把最后一个加号去掉。 
	printf("=%d",a-t);//在循环的开始多一个a，最后值应该减去a的初始值。 
	return 0;
}
