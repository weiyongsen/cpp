#include<stdio.h>
void cal(int n, int m,int *Q1,int *Q2,int *Q3,int *Q4,int *Q5);
int main()
{	
	int n,m;
	int Q1,Q2,Q3,Q4,Q5;
	printf("请输入两个数（逗号分隔）：");
	scanf("%d,%d",&n,&m);
	cal(n,m,&Q1,&Q2,&Q3,&Q4,&Q5);
	printf("和%d\n差%d\n积%d\n商%d\n余%d",Q1,Q2,Q3,Q4,Q5);
	return 0;       
}
void cal(int n, int m,int *Q1,int *Q2,int *Q3,int *Q4,int *Q5)
{
	*Q1=n+ m;
	*Q2=n- m;
	*Q3=n* m;
	*Q4=n/ m;
	*Q5=n% m;
}
