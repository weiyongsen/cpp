//����һ���ַ�������ʹ��ð�ݷ���������ַ���������������"aghTr"�������"Taghr"��
#include <stdio.h>
void sort(char *s);
main()
{
    char c[100];
    printf("Input string:");
    scanf("%s", c);
    sort(c);
    printf("output string:");
    puts(c);
}

void sort(char *s)
{
    int i, j, index, temp;
    for (i = 0; s[i] != '\0'; i++)
	{
        index = i;
        for (j = i; s[j] != '\0'; j++) 
		{
            if (s[index] > s[j]) 
			{
                index = j;
            }
        }
        temp = s[index];
        s[index] = s[i];
        s[i] = temp;
    }
}

