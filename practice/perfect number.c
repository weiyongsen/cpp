/*�ҳ�200���ڵ���������������������ӡ�   1���Գ��⡣���������������ӡ���ˣ� 
���磬6=1+2+3������1,2,3�����ӣ�6Ϊ����֮�͡�*/
#include <stdio.h>
int main()
{
	int num,factor,i,j;    //i��ʾ������ӣ�j��ʾȷ������֮�����ҳ������� �� 
	for (num=1;num<=200;num++)   //����200�������ҳ������� 
	{
		if (num==1)          //�����һֱ�Ӵ�ӡ 
		{
			printf("1=1\n");
		}
		for (factor=1,i=0;factor<num;factor++)   //ÿ�ζ�i��ʼ��������ÿ��ѭ�����i��ֵ�ҳ����� �� 
		{
			if (num%factor==0)
			{
				i=i+factor;
			}
		}
		if (i==num)            //���ҳ��������ٽ������ӷֽ� �� 
		{
			printf("%d=1",num);         //��Ϊ���ӡ�1���͡�+��λ�õ�Ե�ʣ��ȴ�ӡ����num��=��1�������ټ����������� 
			for (j=2;j<num;j++)         //�����������ҳ����ӡ� 
			{
				if (num%j==0)
				{
					printf("+%d",j);    //��ӡ����+���� ����ʽ �� 
				}
			}
		printf("\n");   //ÿ������д�꣬ ��һ���С� 
		}
	}
	return 0;
}