#include <stdio.h>

int main()
{
	int i,a[10],*p=a;//p的初值是a，p指向a[0] 
	printf("请输入十个数：\n");
	for (i=0;i<10;i++)
		scanf("%d",p++);
		p=a;
	for (i=0;i<10;i++,p++)
		printf("%d ",*p);
	printf("\n");
	return 0;
}
