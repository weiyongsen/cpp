//六表格猜数（二进制问题）  60以内 
#include <stdio.h>
int main()
{
    char ans; //你的回答 
    int num=0;
    printf("Think a number in 1-60\n");
    char card1[]="\
     1 11 21 31 41 51\n\
     3 13 23 33 43 53\n\
     5 15 25 35 45 55\n\
     7 17 27 37 47 57\n\
     9 19 29 39 49 59";
    printf ("card1=\n%s\n",card1); //输出表格数字，格式控制%s。 
    printf("Is your number in it?(y or n):");
    scanf ("%c",&ans);  
    if (ans == 'y')
    	num=1;
    char card2[]="\
     2 11 22 31 42 51\n\
     3 14 23 34 43 54\n\
     6 15 26 35 46 55\n\
     7 18 27 38 47 58\n\
    10 19 30 39 50 59";
    printf ("card2=\n%s\n",card2);
    printf("Is your number in it?(y or n):");
    getchar();  //消除掉输入ans后按的回车，不然第二次读入的字符会是回车。 
    scanf ("%c",&ans);
    if (ans == 'y')
    	num=num+2;
    char card3[]="\
     4 13 22 31 44 53\n\
     5 12 23 36 45 54\n\
     6 15 28 37 46 55\n\
     7 20 29 38 47 60\n\
    12 21 30 39 52 *";
    printf ("card3=\n%s\n",card3);
    printf("Is your number in it?(y or n):");
    getchar();
    scanf ("%c",&ans);
    if (ans == 'y')
        num=num+4;
    char card4[]="\
     8 13 26 31 44 57\n\
     9 14 27 40 45 58\n\
    10 15 28 41 46 59\n\
    11 24 29 42 47 60\n\
    12 25 30 43 56 *";
    printf ("card4=\n%s\n",card4);
    printf("Is your number in it?(y or n):");
    getchar();
    scanf ("%c",&ans);
    if (ans == 'y')
        num=num+8;
    char card5[]="\
    16 21 26 31 52 57\n\
    17 22 27 48 53 58\n\
    18 23 28 49 54 59\n\
    19 24 29 50 55 60\n\
    20 25 30 51 56 *";
    printf ("card5=\n%s\n",card5);
    printf("Is your number in it?(y or n):");
    getchar();
    scanf ("%c",&ans);
    if (ans == 'y')
        num=num+16;
    char card6[]="\
    32 37 42 47 52 57\n\
    33 38 43 48 53 58\n\
    34 39 44 49 54 59\n\
    35 40 45 50 55 60\n\
    36 41 46 51 56 *";
    printf ("card6=\n%s\n",card6);
    printf("Is your number in it?(y or n):");
    getchar();
    scanf ("%c",&ans);
    if (ans == 'y')
        num=num+32;
    printf("Your number is:%d",num);
    return 0;
}

