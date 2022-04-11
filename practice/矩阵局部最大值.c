/*
随机产生一个16行16列的二维数组的元素（元素值100以内）
编写程序实现寻找并输出该二维数组极值点的功能。
对于m行n列的矩阵A，如果A的非边界元素A[i][j]
大于同行的左右两个和同列的上下两个元素（相邻的上下左右4个元素），
那么就称A[i][j]是矩阵的局部最大值。
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void numin(int a[16][16]);			//填充数组的函数声明 
void numout(int a[16][16]);			//输出数组额函数声明 
void max(int a[16][16]);			//局部最大值函数声明 
int main()
{
	int a[16][16]; 
	numin(a);
	numout(a);
	max(a);
	return 0;
}
void numin(int a[16][16])
{
	int p,q;
	srand((unsigned) time(NULL));			//初始化随机数发生器	 
	for(p=0;p<16;p++)
	{
		for(q=0;q<16;q++)
		{
			a[p][q]=rand()%100;
		}
	}
}
void numout(int a[16][16])					//输出函数 
{
	int x,y;
	for(x=0;x<16;x++)
	{
		for(y=0;y<16;y++)
		{
			printf("%4d",a[x][y]);			//输出数组 
		}
		printf("\n");
	}
}
void max(int a[16][16])						//找出局部最大值 
{
	int i,j;
	for(i=1;i<15;i++)
	{
		for(j=1;j<15;j++)
		{
			if(a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1])
			{
				printf("第%d行，%d列是局部最大值\n",i+1,j+1); 
			}
		}
	}
}
