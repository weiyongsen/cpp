#include "stdio.h"
int main()
{
	int c;
	scanf("%c",&c);
	if(isalpha(c)){
		if(islower(c))
			c=toupper(c);
		else if(isupper(c))
			c=tolower(c);
		printf("%c",c);	
	}
	else
		printf("%c",c);
	return 0;
}

