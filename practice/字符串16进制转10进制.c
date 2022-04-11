/* 
输入一个以"#"结束的字符串，过滤掉所有的非16进制字符后，
组成一个新的字符串（包含大小写的十六进制字符），
然后将其转换为十进制整数输出，
如果字符串的首字符    为"+"或者"-"，则代表该数的正负。
例如 输入"-wr10#"，则输出-16
     输入"+Pf41#"，则输出3905
ASCII  97='a'   102='f'    48='0'   57='9'
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
void cut(char a[], int *num1);
void move(char a[], int count, int num2);
int change(char a[], int num3);
int main()
{
	char a[100],b;
	int i=0,j,output; 
	printf("请输入带有正负符号（默认第一个字符是符号）的字符串：") ; 
	scanf("%c",&b);
	if(b=='-')					//判断符号 
		printf("output=-");
	else
		printf("output=");
	while((a[i++]=getchar())!='#')		//读入字符数组 
	;
	j=strlen(a); 
	j-=1;						//去掉#后的字符数组长度 
	cut(a,&j);					//去掉多余字母 
	output=change(a,j);				//求和 
	printf("%d",output);
	 
	return 0;
}

void cut(char a[], int *num1)
{
	int q;
	for(q=0;q<*num1;q++)						//遍历#之前的字符 
	{
		if(a[q]=='#')							//判断是否#已经前移到了第p位，就可跳出循环 
			break;
		else if (isdigit(a[q])||(a[q]>96&&a[q]<103))  		//符合题意的字符 
			;
		else
		{
			move(a,q,*num1);					//前移覆盖掉这个不合题意的字符 
			q-=1;								//q-1是为了检查前移到这一位（第q位）的字符是否符合题意 
			*num1-=1;							//前移之后，j-1，代表符合题意的字符少了一个（去掉了最后一位的#） 
		}
	}
}
void move(char a[], int count, int num2)		//a[]数组的前num位数字从第count位开始均向前移动一位 
{
	int p;
	for(p=count;p<num2;p++) 
	{
		a[p]=a[p+1];							//前移 
	}
} 
int change(char a[], int num3)					//转换进制 
{
	int x,out=0;
	for(x=0;x<num3;x++)
	{
		if(isdigit(a[x]))						//判断是否数字 
			out+=(a[x]-48)*pow(16,num3-1-x);
		else									//a~f的字符 
			out+=(a[x]-87)*pow(16,num3-1-x);
	}
	return out;
}

