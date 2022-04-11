/*输入一个字符串，判断该字符串是否是回文字符串，
所谓回文字符串，就是一个字符串，从左到右读和从右到左读是完全一样的。
比如"level" 、 "aaabbaaa"。
*/ 
#include <stdio.h>
#include <string.h> 
int ispalindrome(char a[], int n);	//函数声明 
int main()
{
	char a[100];
	int j,l;
	printf("In put string:");
	gets(a);				//输入字符串 
	l=strlen(a);			//测量现在a的长度 
	j=ispalindrome(a,l);	//调用函数 
	if(j==1)
		printf("宁输入的是一个回文字符串。");
	else
		printf("宁输入的不是一个回文字符串。");
}
int ispalindrome(char a[], int n)	//回文数组函数 
{
	int i,flag;
	for (i=0;i<n/2;i++)
	{
		if(a[i]==a[n-i-1])		//倒序相比较是否相等 
		{
			flag=1;
		}
		else
		{
			flag=0;
			break;				//只要一个不成立就退出 
		}	
	}
	return flag;
}

