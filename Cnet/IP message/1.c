#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500


int main(){
    FILE *fpIn, *fpOut;
    char data[MAXSIZE];
	if((fpIn=fopen("in.txt","a+"))==NULL)
	{
		printf("%s","���ļ�ʧ��");
		return 1;
	}
	if((fpOut=fopen("out.txt","wb"))==NULL)
	{
		printf("%s","д���ļ�ʧ��");
		return 1;
    }
    
    unsigned int src[8];     // ԴMAC
    int dst[8];
	printf("%s","������Դip(8λ) :");
    scanf("%x-%x-%x-%x-%x-%x-%x-%x",src,src+1,src+2,src+3,src+4,src+5,src+6,src+7);
    printf("%s","������mudiip(8λ) :");
    scanf("%x-%x-%x-%x-%x-%x-%x-%x",dst,dst+1,dst+2,dst+3,dst+4,dst+5,dst+6,dst+7);
    // д��Դ��ַ
    for(int i=0;i<8;i++){
        printf("%d %d \n",i,src[i]);
    }
    printf("\n");
    // д��Դ��ַ
    for(int i=0;i<8;i++){
        printf("%d %d \n",i,dst[i]);
    }
    return 0;
}
