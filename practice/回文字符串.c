/*����һ���ַ������жϸ��ַ����Ƿ��ǻ����ַ�����
��ν�����ַ���������һ���ַ����������Ҷ��ʹ��ҵ��������ȫһ���ġ�
����"level" �� "aaabbaaa"��
*/ 
#include <stdio.h>
#include <string.h> 
int ispalindrome(char a[], int n);	//�������� 
int main()
{
	char a[100];
	int j,l;
	printf("In put string:");
	gets(a);				//�����ַ��� 
	l=strlen(a);			//��������a�ĳ��� 
	j=ispalindrome(a,l);	//���ú��� 
	if(j==1)
		printf("���������һ�������ַ�����");
	else
		printf("������Ĳ���һ�������ַ�����");
}
int ispalindrome(char a[], int n)	//�������麯�� 
{
	int i,flag;
	for (i=0;i<n/2;i++)
	{
		if(a[i]==a[n-i-1])		//������Ƚ��Ƿ���� 
		{
			flag=1;
		}
		else
		{
			flag=0;
			break;				//ֻҪһ�����������˳� 
		}	
	}
	return flag;
}

