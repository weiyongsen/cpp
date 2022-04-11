#include <stdio.h>

int main()
{
	int a[10];
	int i,j,t;
	printf("请输入需要排序的10个数:\n");
	for (i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("\n");
	for(j=0;j<9;j++)          //进行9次循环比较 
		for(i=0;i<9-j;i++)    // 在每趟中进行9-j次比较 
			if(a[i]>a[i+1])   //相邻两个数比较 
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
	printf("从小到大排列：\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;	
}
