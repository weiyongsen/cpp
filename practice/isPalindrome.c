#include <stdio.h>

int main()
{
	int x,isPalindrome;
	scanf("%d",&x);
	if(x=0)
		isPalindrome=0;
    else if(x<0||x%10==0)
	    isPalindrome=0;
    
    int t;
    t=x;
    int y;
    for (y=0;t>0;t/=10)
    {
        y=y*10+t%10;
    }
    if (y==x)
        isPalindrome=1;
    if (isPalindrome)
        printf("它是一个回文数\n");
    else
		printf("它不是一个回文数\n");
    return 0;
}




