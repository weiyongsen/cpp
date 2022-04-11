#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define N 100
void selectsort(char s[]);    /*声明选择法排序函数*/
int main()
{
	char str[N];
	FILE *fb,*fbt;
	if((fb=fopen("E:\\xuexi\\C\\作业\\b.txt","r+"))==NULL)
	{
		printf("cuo wu.\n");
		return -1;
	}
		if((fbt=fopen("E:\\xuexi\\C\\作业\\bt.txt","w+"))==NULL)
	{
		printf("cuo wu.\n");
		return -1;
	}
	while(1)
	{
		if(fgets(str,100,fb)==NULL)
			break;
		else {
			str[strlen(str)-1]='\0';
			printf("数据排序前：");
			puts(str);
			selectsort(str);    //排序 
			printf("数据排序后：");
			fprintf(fbt,"%s\n",str);
			puts(str);				
		} 
	}
	fclose(fb);
	fclose(fbt);
 	return 0;
}
void selectsort(char s[])   /*定义选择法排序函数*/
{
	int i,j,k,t,len;
	len=strlen(s);
	for(i=0;i<len-1;i++)
	{	k=i;
		for(j=i+1;j<len;j++)
			if(s[j]<s[k])
				k=j;
		if(k!=i)
			t=s[i],s[i]=s[k],s[k]=t;
	}
}
