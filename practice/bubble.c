#include <stdio.h>

int main()
{
	int a[10];
	int i,j,t;
	printf("��������Ҫ�����10����:\n");
	for (i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("\n");
	for(j=0;j<9;j++)          //����9��ѭ���Ƚ� 
		for(i=0;i<9-j;i++)    // ��ÿ���н���9-j�αȽ� 
			if(a[i]>a[i+1])   //�����������Ƚ� 
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
	printf("��С�������У�\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;	
}
