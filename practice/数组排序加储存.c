/*
编程序实现功能：定义一个长度为100的整型数组，按升序的方式初始化部分数据，
例如int a[100]={23,45,60,67,88}。
程序运行时，反复输入一个正整数，在数组中查找是否有这个数，
如有则将该数从数组中删除并保持数组有序；如没有则将该数插入到数组并保持数组有序；
当数组中的数据达到100个时提出警告，不再添加新数；输入负数结束程序运行。
*/
#include <stdio.h>
int len(int a[]); 								//计算长度函数声明 
void Find(int a[], int *num, int digit);		//删去或添加函数声明 
void daoxu(int a[], int num);					//倒序函数 
void shunxu(int a[], int num);					//顺序函数 
void printa(int a[]) ;							//输出数组 
int main()
{
	int i,j,n;
	int a[100]={23,45,60,67,88};
	j=len(a);					//先测量出此时数组中除0之外的元素个数 
	while(1)
	{
		printf("Input n(1 ——1000000):");
		scanf("%d",&n);				//输入想要检查是否含有的数字 
		if(n==0)					//不能为0 
		{
			printf("请输入正整数！\n");
			continue; 
		 } 
		if(n<0)						//程序结束 
		{
			printf("现在有%d个数\n",j);		//程序终止报数 
			printa(a);						//输出数组 
			printf("\n程序终止.");
			break;
		}
		else
		{
			
			if(j>100)
			{
				printf("已经有一百个数了。");
				continue;				//超过一百个数，警告。依然执行循环，但是数字加不进去。 
			}
			else
			{
				Find(a,&j,n);			//查找这个数，删除或者添加 
				printf("现在有%d个数\n",j);			//汇报目前数字 
				daoxu(a,100);			//倒序排列，使得最前面j个数不为0 
				shunxu(a,j);			//对这j个数，进行正序排列 
				printa(a);				//输出这个数组中不为0的正序排列的数 
				printf("\n\n");			//与下一个语句相隔一行。 
			}
		}
	}
	return 0;
}

int len(int a[])				//测量数组长度（返回最后一位不为零的数所在位数） 
{
 	int i=0;
 	while(a[i]!=0)
	{
		i++;
	} 
	return i;
} 
void Find(int a[], int *num, int digit)		//在数组a[100]寻找数字digit，并删除数字,或者添加 使a[num]=digit. 
{
	int p,q;
	q=*num;				//定义成指针，可以修改主函数j=len（a）的值。 
	daoxu(a,100);
	for (p=0;p<q;p++)
	{
		if(digit==a[p])
		{
			a[p]=0;
			printf("存在这个数，已删去。\t"); 
			*num-=1;	//数字个数减一 
			break;		//使得最后q不等于p，相差为1，便于之后的if判断 
		}
	} 
	if(p>=q)
	{
		printf("数组中没有这个数。\t"); 
		a[*num]=digit;
		*num+=1;		//数字个数加一 
	} 
}
void daoxu(int a[], int num)  	//冒泡倒序排列 
{
	int i,j,temp;
	for(i=0;i<num-1;i++)
	{
		for(j=1;j<num-i;j++)
		{
			if(a[j-1]<a[j])
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
 } 
void shunxu(int a[], int num)	//顺序冒泡排列数组
{
		int i,j,temp;
	for(i=0;i<num-1;i++)
	{
		for(j=1;j<num-i;j++)
		{
			if(a[j-1]>a[j])
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
 } 
void printa(int a[]) 			//输出不为0的数组元素 
{
	int i=0;
	while(a[i]!=0)
	{
		printf("%8d",a[i]);		//数字最大为8位 
		i++;
	}
}
