#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *findsubstr(char *s1,char *s2);     		//�����Ӵ����� 
int main()
{
	FILE *fa,*fb;
	char s[256],title[100];
	int i=0,j=0,k=0;								//i�Ǽ�¼������j��s[]�ַ�����λ�� 
	int alpha=0,digit=0;						//a��¼��ĸ������d��¼���ָ��� 
	char *pos1,*pos2;							//pos1��¼��һ��titleλ�ã�pos2��¼�ڶ��� 
	char st1[]="<title>";
	char st2[]="</title>";
	if((fa=fopen("E:\\a.htm","r"))==NULL)		//�ж�a�ļ��� 
	{
		printf("cuo wu!");		
		return -1;
	}
	if((fb=fopen("E:\\b.txt","w"))==NULL)		//�ж�b�ļ��� 
	{
		printf("cuo wu!");		
		return -1;
	}
	while(1)
	{
		if(fgets(s,256,fa)==NULL)				//��ȡÿ�е��ַ����������ո�ͻ��У� 
			break;
		else
		{
			s[strlen(s)-1]='\0';				//��������� 
			printf("%s\n",s);					//��ӡ���s[] 
			i++;								//����+1 
		}
		if(i>100)
			break;								//title�϶���100������ 
		pos1=findsubstr(s,st1);					//�ҵ���һ��titleλ�� 
		if(pos1)								//�ҵ�titl�ٽ�����һ�� 
		{
			pos2=findsubstr(s,st2);				//�ҵ��ڶ���title��λ�� 
			printf("<title>�����ַ�λ����%d��</title>�����ַ�λ����%d\n",pos1-s,pos2-s);		
			for(j=pos1-s+7;j<pos2-s;j++)
			{
				printf("%c",s[j]);				//��ӡ�����λ�� 
				title[k]=s[j];
				k++;
				title[k] ='\0';					//����title��ֹ�� 
				if(isalpha(s[j]))
					alpha++;					//��ĸ 
				if(isdigit(s[j]))
					digit++;					//���� 
			}		
			printf("\n");
			printf("title��%s",title);
			printf("\ntitle�ڵ�%d��\n",i); 
			printf("��ĸ��%dλ��������%dλ\n",alpha,digit);
		
			break;								//�˳�ѭ�� 
		}
	}
	fprintf(fb,"a.htm��ҳ�ı����ǣ�%s \n",title);		//���ļ���д�� 
	fprintf(fb,"�������ļ� a.htm��ҳ�ĵڼ��У�%d\n",i);
	fprintf(fb,"�����������ַ��ĸ�����%d\n",digit);
	fprintf(fb,"��������ĸ�ַ��ĸ�����%d\n",alpha);
	fclose(fa);									//�ر��ļ� 
	fclose(fb);
	return 0;
}
char *findsubstr(char *s1,char *s2)				//�����Ӵ��ĺ��� 
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
