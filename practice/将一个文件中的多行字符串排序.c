#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define N 100
void selectsort(char s[]);    /*����ѡ��������*/
int main()
{
	char str[N];
	FILE *fb,*fbt;
	if((fb=fopen("E:\\xuexi\\C\\��ҵ\\b.txt","r+"))==NULL)
	{
		printf("cuo wu.\n");
		return -1;
	}
		if((fbt=fopen("E:\\xuexi\\C\\��ҵ\\bt.txt","w+"))==NULL)
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
			printf("��������ǰ��");
			puts(str);
			selectsort(str);    //���� 
			printf("���������");
			fprintf(fbt,"%s\n",str);
			puts(str);				
		} 
	}
	fclose(fb);
	fclose(fbt);
 	return 0;
}
void selectsort(char s[])   /*����ѡ��������*/
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
