/*
�������һ��16��16�еĶ�ά�����Ԫ�أ�Ԫ��ֵ100���ڣ�
��д����ʵ��Ѱ�Ҳ�����ö�ά���鼫ֵ��Ĺ��ܡ�
����m��n�еľ���A�����A�ķǱ߽�Ԫ��A[i][j]
����ͬ�е�����������ͬ�е���������Ԫ�أ����ڵ���������4��Ԫ�أ���
��ô�ͳ�A[i][j]�Ǿ���ľֲ����ֵ��
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void numin(int a[16][16]);			//�������ĺ������� 
void numout(int a[16][16]);			//������������� 
void max(int a[16][16]);			//�ֲ����ֵ�������� 
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
	srand((unsigned) time(NULL));			//��ʼ�������������	 
	for(p=0;p<16;p++)
	{
		for(q=0;q<16;q++)
		{
			a[p][q]=rand()%100;
		}
	}
}
void numout(int a[16][16])					//������� 
{
	int x,y;
	for(x=0;x<16;x++)
	{
		for(y=0;y<16;y++)
		{
			printf("%4d",a[x][y]);			//������� 
		}
		printf("\n");
	}
}
void max(int a[16][16])						//�ҳ��ֲ����ֵ 
{
	int i,j;
	for(i=1;i<15;i++)
	{
		for(j=1;j<15;j++)
		{
			if(a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1])
			{
				printf("��%d�У�%d���Ǿֲ����ֵ\n",i+1,j+1); 
			}
		}
	}
}
