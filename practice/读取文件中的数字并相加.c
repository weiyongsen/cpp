#include <stdio.h>
#include <ctype.h>			//isdigit‘§¥¶¿Ì 
int main()
{
	FILE *fa,*fb,*fc;
	char ch;
	int suma=0;
	int sumb=0;
	int sum;
	if((fa=fopen( "C:\\Users\\Administrator\\Desktop\\a.txt","r"))==NULL)
	{
		printf("Can°Øt open the file a \n");
		return 1 ; 
	}
	if((fb=fopen( "C:\\Users\\Administrator\\Desktop\\b.txt","r"))==NULL)
	{
		printf("Can°Øt open the file b \n");
		return 1 ; 
	}
	if((fc=fopen( "C:\\Users\\Administrator\\Desktop\\c.txt","w"))==NULL)
	{
		printf("Can°Øt open the file c \n");
		return 1 ; 
	}
	while((ch=fgetc(fa))!=EOF)
	{
		if(isdigit(ch)) 
			suma=suma*10+ch-'0';
	}
	while((ch=fgetc(fb))!=EOF)
	{
		if(isdigit(ch)) 
			sumb=sumb*10+ch-'0';
	}
	sum=suma+sumb;
	fprintf(fc,"%d",sum);
	fclose(fa);
	fclose(fb);
	fclose(fc);
	return 0;
 }

