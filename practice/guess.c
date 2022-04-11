//猜一个100以内的数，每次都会提示你是大了还是小了。 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{	
	
    srand(time(0));
    int number=rand()%100;
    int count=0;
    int a;
    printf("我想好了一个数,你来猜猜吧\n");
    {
      A:printf("请你输入这个数\n");
        scanf("%d",&a);
        if(a<number)
        {
            printf("小了\n");
            count++;goto A;
        }
        else {
              if(a>number)
                {   printf("大了\n");
                    count++;goto A;
                }
                else {
                    printf("恭喜你答对了\n");
                    count++;
                }
            }
        }
        printf("你猜了%d次\n",count);
        return 0;
    }
