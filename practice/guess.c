//��һ��100���ڵ�����ÿ�ζ�����ʾ���Ǵ��˻���С�ˡ� 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{	
	
    srand(time(0));
    int number=rand()%100;
    int count=0;
    int a;
    printf("�������һ����,�����²°�\n");
    {
      A:printf("�������������\n");
        scanf("%d",&a);
        if(a<number)
        {
            printf("С��\n");
            count++;goto A;
        }
        else {
              if(a>number)
                {   printf("����\n");
                    count++;goto A;
                }
                else {
                    printf("��ϲ������\n");
                    count++;
                }
            }
        }
        printf("�����%d��\n",count);
        return 0;
    }
