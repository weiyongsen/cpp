#include <stdio.h>


int main()
{
	long fac(long n);
	long n,result;
	scanf("%ld",&n);
	result = fac(n);
	printf("%ld",result);
	return 0;
}
long fac(long n)
{
	if(n==1)
		return 1;
	else
		return fac(n-1)*n;
}
