#include <stdio.h>
#define PI 3.1415926535			//����е�ֵ 
double fac(double n);			//��׳˺������� 
double pows(double a,int b); 	//��η��������� 
int main()
{
    double e,x,sign=1,cosx=0;   	//e�Ǿ��ȣ�x�ǻ��ȣ�signÿһ��ǰ���1��-1��cosx����ֵ 
    int i=0;
    printf("input x(����):");
    scanf("%lf",&x);
    printf("input e(����):"); 
    scanf("%lf",&e);
    while(x>2*PI)					//����ֵֻ��С��2�� 
	{
        x-=2*PI;
    }
    while (1)						//����break����һֱִ�� 
    {
        cosx=cosx+sign*pows(x,i)/fac(i);	//cosx����̩�չ�ʽ���� 
        i=i+2;
        sign*=-1.0;					//sign��� 
        if(pows(x,i)/fac(i)<e)    //�жϵ�i���Ƿ�С�ھ��� 
		{
            printf("cos %lf��ֵ��%lf",x,cosx);       
            break;
        }
    }
    return 0;
}
double fac(double n)   	//�׳˺��� 
{
    if (n==1||n==0)     //����fac(0)��ֵ 
        return 1;
    else
        return n*fac(n-1);   	//�ݹ� 
}
double pows(double a,int b)   	//����a(������)��b�η� 
{
    double ans = 1;				//��ʼ������Ҫ 
    int i;
    for(i = 0;i < b;i++)
	{
        ans *= a;
    }
    return ans;
}


