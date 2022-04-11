#include <stdio.h>
int main()
{
	char m[7],n[7];
	int sum1=1,sum2=1,i;
	scanf("%s %s",m,n);
	for(i=0;m[i]!='\0';i++)
	{
		sum1*=(m[i]-64);
	}
	for(i=0;n[i]!='\0';i++)
	{
		sum2*=(n[i]-64);
	}
	if((sum1%47)==(sum2%47))
	{
		printf("GO\n");
	}
	else
		printf("STAY\n");
	return 0;
}
