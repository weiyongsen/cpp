# include <stdio.h>
# include <math.h>
#define ESP 1e-6
#define e 2.7182818
int fac(int n);//阶乘函数 声明 
int main()
{
	int k;//控制累加次数 
	double e1=0;//表示计算所得e的值 
	while (fabs(e-e1)>=ESP)//如果计算的e1和e这件的差值大于1e-6。即精度 
	{
		e1=k*1.0/fac(k)+e1;
		k++;
	}
	printf("e的近似值为%lf",e1);
	return 0;
}
int fac(int n)
{
	int j,m;
	for (j=1,m=1;j<=n;j++)//初始化m来求最终m的值，j控制循环次数 
	{
		m=m*j;//阶乘的过程 
	}
	return m;
}

