#include <stdio.h>

int main()   //ifǶ�� 
{
	float grades;
	printf("��������ĳɼ���\n");
	scanf("%f",&grades);
	if (grades <60) 
		printf ("��ĳɼ���E");
	else
		if (grades >=80)
			if(grades>=90)
				printf ("��ĳɼ���A!");
			else
				printf ("��ĳɼ���B");
		else
			if (grades >=70) 
				printf ("��ĳɼ���C");
			else
				printf ("��ĳɼ���D");
	return 0;
}

/*
int main()//  else if���֧ 
{	float grades;
	printf("��������ĳɼ���\n");
	scanf("%f",&grades);
	if(grades>=90)
		printf ("��ĳɼ���A!");
	else if (grades >=80)
		printf ("��ĳɼ���B");
	else if (grades >=70) 
		printf ("��ĳɼ���C");
	else if (grades >=60) 
		printf ("��ĳɼ���D");
	else 
		printf ("��ĳɼ���E");
	return 0;
}
*/
/*
int main()  //switch-case �ṹ 
{
	float grades;
	printf("��������ĳɼ���\n");
	scanf("%f",&grades);
	int score=(int)grades;
	switch(score/10)
	{
		case 10: ;
		case 9:printf ("��ĳɼ���A!");
			break;
		case 8:printf ("��ĳɼ���B");
			break;
		case 7:printf ("��ĳɼ���C");
			break;
		case 6:printf ("��ĳɼ���D");
			break;
		deflaut:printf ("��ĳɼ���E");
	}
	return 0;
}
*/	

