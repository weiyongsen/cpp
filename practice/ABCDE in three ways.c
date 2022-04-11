#include <stdio.h>

int main()   //if嵌套 
{
	float grades;
	printf("请输入你的成绩：\n");
	scanf("%f",&grades);
	if (grades <60) 
		printf ("你的成绩是E");
	else
		if (grades >=80)
			if(grades>=90)
				printf ("你的成绩是A!");
			else
				printf ("你的成绩是B");
		else
			if (grades >=70) 
				printf ("你的成绩是C");
			else
				printf ("你的成绩是D");
	return 0;
}

/*
int main()//  else if多分支 
{	float grades;
	printf("请输入你的成绩：\n");
	scanf("%f",&grades);
	if(grades>=90)
		printf ("你的成绩是A!");
	else if (grades >=80)
		printf ("你的成绩是B");
	else if (grades >=70) 
		printf ("你的成绩是C");
	else if (grades >=60) 
		printf ("你的成绩是D");
	else 
		printf ("你的成绩是E");
	return 0;
}
*/
/*
int main()  //switch-case 结构 
{
	float grades;
	printf("请输入你的成绩：\n");
	scanf("%f",&grades);
	int score=(int)grades;
	switch(score/10)
	{
		case 10: ;
		case 9:printf ("你的成绩是A!");
			break;
		case 8:printf ("你的成绩是B");
			break;
		case 7:printf ("你的成绩是C");
			break;
		case 6:printf ("你的成绩是D");
			break;
		deflaut:printf ("你的成绩是E");
	}
	return 0;
}
*/	

