/* 
����һ����"#"�������ַ��������˵����еķ�16�����ַ���
���һ���µ��ַ�����������Сд��ʮ�������ַ�����
Ȼ����ת��Ϊʮ�������������
����ַ��������ַ�    Ϊ"+"����"-"������������������
���� ����"-wr10#"�������-16
     ����"+Pf41#"�������3905
ASCII  97='a'   102='f'    48='0'   57='9'
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
void cut(char a[], int *num1);
void move(char a[], int count, int num2);
int change(char a[], int num3);
int main()
{
	char a[100],b;
	int i=0,j,output; 
	printf("����������������ţ�Ĭ�ϵ�һ���ַ��Ƿ��ţ����ַ�����") ; 
	scanf("%c",&b);
	if(b=='-')					//�жϷ��� 
		printf("output=-");
	else
		printf("output=");
	while((a[i++]=getchar())!='#')		//�����ַ����� 
	;
	j=strlen(a); 
	j-=1;						//ȥ��#����ַ����鳤�� 
	cut(a,&j);					//ȥ��������ĸ 
	output=change(a,j);				//��� 
	printf("%d",output);
	 
	return 0;
}

void cut(char a[], int *num1)
{
	int q;
	for(q=0;q<*num1;q++)						//����#֮ǰ���ַ� 
	{
		if(a[q]=='#')							//�ж��Ƿ�#�Ѿ�ǰ�Ƶ��˵�pλ���Ϳ�����ѭ�� 
			break;
		else if (isdigit(a[q])||(a[q]>96&&a[q]<103))  		//����������ַ� 
			;
		else
		{
			move(a,q,*num1);					//ǰ�Ƹ��ǵ��������������ַ� 
			q-=1;								//q-1��Ϊ�˼��ǰ�Ƶ���һλ����qλ�����ַ��Ƿ�������� 
			*num1-=1;							//ǰ��֮��j-1���������������ַ�����һ����ȥ�������һλ��#�� 
		}
	}
}
void move(char a[], int count, int num2)		//a[]�����ǰnumλ���ִӵ�countλ��ʼ����ǰ�ƶ�һλ 
{
	int p;
	for(p=count;p<num2;p++) 
	{
		a[p]=a[p+1];							//ǰ�� 
	}
} 
int change(char a[], int num3)					//ת������ 
{
	int x,out=0;
	for(x=0;x<num3;x++)
	{
		if(isdigit(a[x]))						//�ж��Ƿ����� 
			out+=(a[x]-48)*pow(16,num3-1-x);
		else									//a~f���ַ� 
			out+=(a[x]-87)*pow(16,num3-1-x);
	}
	return out;
}

