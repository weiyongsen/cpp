#include <stdio.h>
int isPalindrome(int x);             //ÉùÃ÷
int main()
{
    int x;
    scanf("%d",&x);
    if (isPalindrome(x))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
int isPalindrome(int x)
{
	if(x<0){
		return 0;
	} 
	else{
		int t=x;
	    int sum=0;
	    while(t){
	        sum=sum*10+t%10;
	        t/=10;
	    }
	    return sum==x;
	}
}

