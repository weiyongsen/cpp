# include <stdio.h>
# include <math.h>
#define ESP 1e-6
#define e 2.7182818
int fac(int n);//�׳˺��� ���� 
int main()
{
	int k;//�����ۼӴ��� 
	double e1=0;//��ʾ��������e��ֵ 
	while (fabs(e-e1)>=ESP)//��������e1��e����Ĳ�ֵ����1e-6�������� 
	{
		e1=k*1.0/fac(k)+e1;
		k++;
	}
	printf("e�Ľ���ֵΪ%lf",e1);
	return 0;
}
int fac(int n)
{
	int j,m;
	for (j=1,m=1;j<=n;j++)//��ʼ��m��������m��ֵ��j����ѭ������ 
	{
		m=m*j;//�׳˵Ĺ��� 
	}
	return m;
}

