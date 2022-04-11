/*
1,统计正整数m的位数；
2.从高位开始逐位分割并输出它的各位数字；
3.打印输出0到m之间所有的回文素数
回文素数是指从左读与从右读是完全一样的素数（例如11，101，131等），打印时每行输出5个。
*/
#include <stdio.h>
#include <math.h>
int counts(int num);  //判断位数函数声明 
int isPrime(int num); //判断素数函数声明 
int reverse(int rev); //倒序素数函数声明 
int main()
{
	int num,temp,count;
	int i,j,k; //i是循环控制变量，j是高位分割输出的每一个数，k是找素数是遍历0-num所用。 
	int row=0;   //控制每行输出5个回文素数。 
	printf("请输入一个正整数:");
	scanf("%d",&num);
	temp = num;
	count = counts(temp);
	printf ("Ⅰ.%d这个数字有 %d 位.\n",temp,count);
	printf("Ⅱ.从高到低逐位输出:"); 
	for(i=1;i<=count;i++)
	{
		j=temp/(int)pow(10,count-i);   //得到temp的最高位 ,pow返回值是double，还要转化成int。 
		printf(" %d ",j);
		temp-=j*(int)pow(10,count-i);  //去掉temp的最高位。 
	}
	printf("\nⅢ.0-%d的回文素数有：\n",temp);
	temp = num; //使得temp再次等于num。
	for (k=2;k<=temp;k++)
	{
		if(isPrime(k))       //是否素数。 
		{
			if(k==reverse(k))  //是否倒序相等 。 
				{
					if(row!=0&&row%5==0)  //控制一行5个。 
					{
						printf("\n");
					}
					printf("%d\t",k);
					row++;
				}
				
		 } 
	}
	
	return 0;
}
int counts(int num) //数字位数计算 。 
{
	int count=0;
	while(num>0)
	{
		num/=10;
		count++;
	}
	return count;
}
int isPrime(int num) //判断是否是素数 。 
{
	int a=(int)sqrt(num);
	int i,flag;
	for (i=2;i<=a;i++)
	{
		if(num%i==0)
			return flag=0;
	}
	if (i>a)
		return flag=1;
}
int reverse(int num)//倒序素数（素数最后一定不为0，可以用这个函数） 。 
{
	int rev=0;      //初始化rev很重要 。 
	while(num>0)    //该循环在num尾数是0的时候失效，但是素数的结尾一定不为0。 
	{
		rev=rev*10+num%10;
		num/=10;
	}
	return rev;
}
