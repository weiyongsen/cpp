/*
�����ʵ�ֹ��ܣ�����һ������Ϊ100���������飬������ķ�ʽ��ʼ���������ݣ�
����int a[100]={23,45,60,67,88}��
��������ʱ����������һ�����������������в����Ƿ����������
�����򽫸�����������ɾ������������������û���򽫸������뵽���鲢������������
�������е����ݴﵽ100��ʱ������棬����������������븺�������������С�
*/
#include <stdio.h>
int len(int a[]); 								//���㳤�Ⱥ������� 
void Find(int a[], int *num, int digit);		//ɾȥ����Ӻ������� 
void daoxu(int a[], int num);					//������ 
void shunxu(int a[], int num);					//˳���� 
void printa(int a[]) ;							//������� 
int main()
{
	int i,j,n;
	int a[100]={23,45,60,67,88};
	j=len(a);					//�Ȳ�������ʱ�����г�0֮���Ԫ�ظ��� 
	while(1)
	{
		printf("Input n(1 ����1000000):");
		scanf("%d",&n);				//������Ҫ����Ƿ��е����� 
		if(n==0)					//����Ϊ0 
		{
			printf("��������������\n");
			continue; 
		 } 
		if(n<0)						//������� 
		{
			printf("������%d����\n",j);		//������ֹ���� 
			printa(a);						//������� 
			printf("\n������ֹ.");
			break;
		}
		else
		{
			
			if(j>100)
			{
				printf("�Ѿ���һ�ٸ����ˡ�");
				continue;				//����һ�ٸ��������档��Ȼִ��ѭ�����������ּӲ���ȥ�� 
			}
			else
			{
				Find(a,&j,n);			//�����������ɾ��������� 
				printf("������%d����\n",j);			//�㱨Ŀǰ���� 
				daoxu(a,100);			//�������У�ʹ����ǰ��j������Ϊ0 
				shunxu(a,j);			//����j������������������ 
				printa(a);				//�����������в�Ϊ0���������е��� 
				printf("\n\n");			//����һ��������һ�С� 
			}
		}
	}
	return 0;
}

int len(int a[])				//�������鳤�ȣ��������һλ��Ϊ���������λ���� 
{
 	int i=0;
 	while(a[i]!=0)
	{
		i++;
	} 
	return i;
} 
void Find(int a[], int *num, int digit)		//������a[100]Ѱ������digit����ɾ������,������� ʹa[num]=digit. 
{
	int p,q;
	q=*num;				//�����ָ�룬�����޸�������j=len��a����ֵ�� 
	daoxu(a,100);
	for (p=0;p<q;p++)
	{
		if(digit==a[p])
		{
			a[p]=0;
			printf("�������������ɾȥ��\t"); 
			*num-=1;	//���ָ�����һ 
			break;		//ʹ�����q������p�����Ϊ1������֮���if�ж� 
		}
	} 
	if(p>=q)
	{
		printf("������û���������\t"); 
		a[*num]=digit;
		*num+=1;		//���ָ�����һ 
	} 
}
void daoxu(int a[], int num)  	//ð�ݵ������� 
{
	int i,j,temp;
	for(i=0;i<num-1;i++)
	{
		for(j=1;j<num-i;j++)
		{
			if(a[j-1]<a[j])
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
 } 
void shunxu(int a[], int num)	//˳��ð����������
{
		int i,j,temp;
	for(i=0;i<num-1;i++)
	{
		for(j=1;j<num-i;j++)
		{
			if(a[j-1]>a[j])
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
 } 
void printa(int a[]) 			//�����Ϊ0������Ԫ�� 
{
	int i=0;
	while(a[i]!=0)
	{
		printf("%8d",a[i]);		//�������Ϊ8λ 
		i++;
	}
}
