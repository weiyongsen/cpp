#include"stdio.h"
#include"string.h"
#include <conio.h>
int main()
{
	FILE *fp,*fpt;
	char str[100],*p;
	int count=0;
	fp=fopen("E:\\c_work\\a.txt","r");
	fpt=fopen("E:\\c_work\\b.txt","w");
	if(fp==NULL||fpt==NULL)
	{
		printf("file open error!");
		return 1;
	}

	while(1)
	{
		fgets(str,100,fp);
		fputs(str,fpt);
		puts(str);
		if(feof(fp))
		   break;	
		//printf("%d\n",count);
	}
	fclose(fp);
	fclose(fpt);
	
	return 0;
}

