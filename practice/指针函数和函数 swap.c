#include <stdio.h>

void swap1(int *pt1,int *pt2)
{
 	int temp;
 	temp=*pt1;
 	*pt1=*pt2;
 	*pt2=temp;
 	printf("swap1������:  a=%d,b=%d \n",*pt1,*pt2); 
}
void swap2(int x,int y) 
{
 	int t;
 	t=x;
 	x=y;
 	y=t;
 	printf("swap2������:  a=%d,b=%d \n",x,y); 
}

int main()
{ 	
	void swap(int x,int y);
	int a=3,b=5;
	printf("swap1����ǰ:  a=%d,b=%d \n",a,b); 
	int *p1,*p2;
	p1= &a;
	p2= &b; 
	swap1(p1,p2);
	printf("swap1���ú� a=%d,b=%d \n\n",a,b); 
	printf("swap2����ǰ�� a=%d,b=%d \n",a,b); 
	swap2(a,b);
	printf("swap2���ú� a=%d,b=%d \n",a,b); 
	return 0;
}

