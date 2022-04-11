#include"stdio.h"
#include"stdlib.h"
#define EOFI -1
int main()
{
	FILE *fp;
	char ch;
	fp=fopen("E:\\c_work\\bubble.c","r");       //NULL
	if(fp==NULL)
	{
		printf("file error!");
		return 1;//exit(1)
	}
	printf("file ok!\n");
	while(1)
	{
		ch=fgetc(fp);
		putchar(ch);
		if(feof(fp))
		   break;		
	}
	fclose(fp);//
	
	return 0;
	
}

