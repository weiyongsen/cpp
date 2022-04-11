#include <stdio.h>
#include <string.h>
int sort(char a[]);		//排序函数声明	
int main()
{
	FILE *f1,*f2,*f3;
	char s1[50],s2[50];
	if((f1=fopen("E:\\xuexi\\C\\作业\\file1.txt","r+"))==NULL)
	{
		printf("cuo wu.\n");
		return -1;
	}
	if((f2=fopen("E:\\xuexi\\C\\作业\\file2.txt","r+"))==NULL)
	{
		printf("cuo wu.\n");
		return -1;
	}
	if((f3=fopen("E:\\xuexi\\C\\作业\\file3.txt","w+"))==NULL)
	{
		printf("cuo wu.\n");
		return -1;
	}
	fscanf(f1,"%s",s1);		//从文件读取 
	fscanf(f2,"%s",s2);
	printf("1排序前：");
	puts(s1);
	printf("2排序前：");
	puts(s2);
	strcat(s1,s2);			//连接 
	printf("3排序前:");		
	puts(s1);
	sort(s1);
	printf("3排序后:");	 
	puts(s1); 
	fprintf(f3,"%s",s1);	//输出到file3 
	return 0; 
} 
int sort(char a[])			//选择排序法 
{
	int l;
	int i,j,k;
	int temp;
	l=strlen(a);
	for(i=0;i<l-1;i++)
	{
		k=i;
		for(j=i+1;j<l;j++)
		{
			if(a[j]<a[k])
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}
	}
}
