#include <stdio.h>

int main()
{
	int i,a[10],*p=a;//p�ĳ�ֵ��a��pָ��a[0] 
	printf("������ʮ������\n");
	for (i=0;i<10;i++)
		scanf("%d",p++);
		p=a;
	for (i=0;i<10;i++,p++)
		printf("%d ",*p);
	printf("\n");
	return 0;
}
