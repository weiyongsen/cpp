#include <stdio.h>
#define PI 3.1415926535			//定义π的值 
double fac(double n);			//求阶乘函数声明 
double pows(double a,int b); 	//求次方函数声明 
int main()
{
    double e,x,sign=1,cosx=0;   	//e是精度，x是弧度，sign每一项前面的1或-1，cosx余弦值 
    int i=0;
    printf("input x(弧度):");
    scanf("%lf",&x);
    printf("input e(精度):"); 
    scanf("%lf",&e);
    while(x>2*PI)					//弧度值只能小于2π 
	{
        x-=2*PI;
    }
    while (1)						//除非break否则一直执行 
    {
        cosx=cosx+sign*pows(x,i)/fac(i);	//cosx根据泰勒公式计算 
        i=i+2;
        sign*=-1.0;					//sign变号 
        if(pows(x,i)/fac(i)<e)    //判断第i项是否小于精度 
		{
            printf("cos %lf的值是%lf",x,cosx);       
            break;
        }
    }
    return 0;
}
double fac(double n)   	//阶乘函数 
{
    if (n==1||n==0)     //还有fac(0)的值 
        return 1;
    else
        return n*fac(n-1);   	//递归 
}
double pows(double a,int b)   	//计算a(浮点数)的b次方 
{
    double ans = 1;				//初始化很重要 
    int i;
    for(i = 0;i < b;i++)
	{
        ans *= a;
    }
    return ans;
}


