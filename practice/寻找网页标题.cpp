#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *findsubstr(char *s1,char *s2);     		//查找子串函数 
int main()
{
	FILE *fa,*fb;
	char s[256],title[100];
	int i=0,j=0,k=0;								//i是记录行数，j是s[]字符串的位置 
	int alpha=0,digit=0;						//a记录字母个数，d记录数字个数 
	char *pos1,*pos2;							//pos1记录第一个title位置，pos2记录第二个 
	char st1[]="<title>";
	char st2[]="</title>";
	if((fa=fopen("E:\\a.htm","r"))==NULL)		//判断a文件打开 
	{
		printf("cuo wu!");		
		return -1;
	}
	if((fb=fopen("E:\\b.txt","w"))==NULL)		//判断b文件打开 
	{
		printf("cuo wu!");		
		return -1;
	}
	while(1)
	{
		if(fgets(s,256,fa)==NULL)				//读取每行的字符串（包括空格和换行） 
			break;
		else
		{
			s[strlen(s)-1]='\0';				//处理掉换行 
			printf("%s\n",s);					//打印输出s[] 
			i++;								//行数+1 
		}
		if(i>100)
			break;								//title肯定在100行以内 
		pos1=findsubstr(s,st1);					//找到第一个title位置 
		if(pos1)								//找到titl再进行下一步 
		{
			pos2=findsubstr(s,st2);				//找到第二个title的位置 
			printf("<title>的首字符位置是%d，</title>的首字符位置是%d\n",pos1-s,pos2-s);		
			for(j=pos1-s+7;j<pos2-s;j++)
			{
				printf("%c",s[j]);				//打印标题的位置 
				title[k]=s[j];
				k++;
				title[k] ='\0';					//赋予title终止符 
				if(isalpha(s[j]))
					alpha++;					//字母 
				if(isdigit(s[j]))
					digit++;					//数字 
			}		
			printf("\n");
			printf("title是%s",title);
			printf("\ntitle在第%d行\n",i); 
			printf("字母有%d位，数字有%d位\n",alpha,digit);
		
			break;								//退出循环 
		}
	}
	fprintf(fb,"a.htm网页的标题是：%s \n",title);		//向文件中写入 
	fprintf(fb,"标题在文件 a.htm网页的第几行：%d\n",i);
	fprintf(fb,"标题中数字字符的个数：%d\n",digit);
	fprintf(fb,"标题中字母字符的个数：%d\n",alpha);
	fclose(fa);									//关闭文件 
	fclose(fb);
	return 0;
}
char *findsubstr(char *s1,char *s2)				//查找子串的函数 
{	
	int len=strlen(s2);
	while((s1=strchr(s1,*s2))!=NULL)
	{
		if(strncmp(s1,s2,len)==0)
			break;
		else
			s1++;
	}
	return s1;
}
