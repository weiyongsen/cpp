/*
Ŀ��:
��װ
1.��inputFile�ļ��е����ݷ�װ��MAC֡,��װ�õ�MAC֡д��outputFile�ļ���.
2.������ݳ���С��46�ֽ�,��ȫ��46�ֽ�
3.������ݳ��ȴ���1500,���װ�ɶ��MAC֡
���װ:
��ȡoutputFile�е�����,�������ʾ֡����Ϣ
��ʵ����Ҫ�������͵�,�����кö����Լ���ӵ�
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500
#define echo(format,str) printf("%"#format,str)
#define inputFile "in.txt" 
#define outputFile "out.txt" 
void flush()
{
	fflush(stdin);
	fflush(stdout);
}
 
 
unsigned int  crc8(unsigned char *ptr,unsigned  int len)
/*
CRCУ��,ptr����Ҫ����������׵�ַ,len����Ҫ����ĳ���
*/
{
    unsigned int  CRC = 0;
    unsigned int  i;
	
    while(len--){
        CRC = CRC^ *ptr++;
        for(i = 0; i < 8; i++){
            if(CRC & 0x01){
                CRC = (CRC >> 1 )^ 0x8c;
            }
			else{
				CRC >>= 1;
			}
        }                   
    }
	
    return CRC;  
}
 
 
int encapsulation()
/*֡��װ����*/
{
	int i,dataCrc,nu,j,lastNu,sum;
	FILE *fpIn,*fpOut;
	int src[6],des[6];
	char type[2],data[MAXSIZE];
	if((fpIn=fopen(inputFile,"a+"))==NULL)
	{
		echo(s,"���ļ�ʧ��!");
		return 1;
	}
	if((fpOut=fopen(outputFile,"wb"))==NULL)
	{
		echo(s,"д���ļ�ʧ��");
		return 1;
	}
 
	fseek(fpIn,0,SEEK_END);
	sum=ftell(fpIn);
	nu=sum/1500;
	if((sum-nu*1500)<46)
	{
		for(i=0;i<(46-(sum-nu*1500));i++)
			fputc(0x0,fpIn);   //�������,�����
	}
 
	rewind(fpIn);
 
	echo(s,"����ԴMAC:");
	scanf("%x-%x-%x-%x-%x-%x",src,src+1,src+2,src+3,src+4,src+5);
	fflush(stdin);
	echo(s,"������Ŀ��MAC:");
	scanf("%x-%x-%x-%x-%x-%x",des,des+1,des+2,des+3,des+4,des+5);
	flush();
	echo(s,"�����������ֶ�:");
	flush();
	scanf("%2x%2x",type,type+1);
 
	for(j=0;j<nu+1;j++)
	{
		for(i=0;i<7;i++)
			fputc(0xaa,fpOut);   //д��֡ǰ����
		fputc(0xab,fpOut);       //д��֡�����
 
		for(i=0;i<6;i++)
		{
			fputc(des[i],fpOut);    //д��Ŀ��MAC
		}
		for(i=0;i<6;i++)
		{
			fputc(src[i],fpOut);   //д��ԴMAC
		}
		
		fputc(type[0],fpOut);     //д�����ͺ�
		fputc(type[1],fpOut);
 
 
		if(j!=nu)
		/*�������һ������,��ǰ������ݶ�Ӧ����1500*/
		{
			fread(data,sizeof(char),1500,fpIn);
			fwrite(data,sizeof(char),1500,fpOut);
			dataCrc=crc8(data,1500);
			fputc(dataCrc,fpOut);
		}
		else
		{
			//���һ������,��Ҫ���⴦��,��ȡ����
			lastNu=ftell(fpIn);
			fread(data,sizeof(char),sum-lastNu,fpIn);
			fwrite(data,sizeof(char),sum-lastNu,fpOut);
			dataCrc=crc8(data,sum-lastNu);
			fputc(dataCrc,fpOut);
		}
	}
	
	fclose(fpIn);
	fclose(fpOut);
 
	echo(s,"\n\n");
 
	return 0;
}
 
 
int unPack()
/*���װ����*/
{	
	int i,dataStart,dataEnd,srcCrc,nowCrc,dataLength,frameNu=0,sum,j;
	char c,data[MAXSIZE];
	FILE *fpOut;
	if((fpOut=fopen(outputFile,"rb"))==NULL)
	{
		echo(s,"���ļ�ʧ��!");
		return 1;
	}
 
	fseek(fpOut,0,SEEK_END);
	sum=ftell(fpOut);
	rewind(fpOut);
 
	while(1)
		/*��ѭ��Ϊ�˻�ȡ֡�ĸ���
		��Ҫ˼·:����7��0xaa,��8����0xab
		*/
	{
		if(ftell(fpOut)>=sum)
		{
			break;
		}
		for(i=0;i<7;i++)
		{
			if(ftell(fpOut)>=sum)
			{
				break;
			}
 
			if(fgetc(fpOut)!=0xaa)
			{
				i=-1;
			}
		}
		if(ftell(fpOut)>=sum)
		{
			break;
		}
		if(fgetc(fpOut)==0xab)
		{
			++frameNu;
		}
	}
	rewind(fpOut);
 
	for(j=0;j<frameNu;j++)
		/*ѭ��������֡����Ϣ*/
	{
		printf("\n\n֡���: %d\n\n",j+1);
		echo(s,"֡ǰ����: ");
		for (i=0;i<7;i++)
		{
			c=fgetc(fpOut);
			echo(.2X,c);
		}
		echo(s,"\n\n");
 
		echo(s,"֡ǰ�����: ");
		{
			c=fgetc(fpOut);
			echo(.2X,c);
		}
 
		echo(s,"\n\n");
 
		echo(s,"Ŀ��MAC��ַ: ");
		for (i=0;i<6;i++)
		{
			c=fgetc(fpOut);
			echo(.2X,c);
			if (i!=5)
				echo(s,"-");	
		}
		echo(s,"\n\n");	
 
		echo(s,"ԴMAC��ַ: ");
		for (i=0;i<6;i++)
		{
			c=fgetc(fpOut);
			echo(.2X,c);
			if (i!=5)
				echo(s,"-");	
		}
		echo(s,"\n\n");
 
		echo(s,"���ͺ�: ");
 
		c=fgetc(fpOut);
		echo(.2X,c);
		c=fgetc(fpOut);
		echo(.2X,c);
 
		if(j!=frameNu-1)
			//�������һ��֡,�����ݳ��ȶ���1500
		{
			fread(data,sizeof(char),1500,fpOut);
			srcCrc=fgetc(fpOut);
			nowCrc=crc8(data,1500);
		}
		else
		{
			//���һ��֡,���⴦��
			dataStart=ftell(fpOut);
			fseek(fpOut,-1,SEEK_END);
			dataEnd=ftell(fpOut)-1;
			dataLength=dataEnd-dataStart+1;
			srcCrc=fgetc(fpOut);
			fseek(fpOut,dataStart,SEEK_SET);
			fread(data,sizeof(char),dataLength,fpOut);
			nowCrc=crc8(data,dataLength);
		}
 
		printf("\n\n����CRC:  %d",nowCrc);
		echo(s,"\n\n��Ϊ: ");
		if (nowCrc==srcCrc) //�Ƚ�CRC,�Ƿ����
			echo(s,"����");
		else
			echo(s,"����");
			printf("  ǰ��CRC:%d",srcCrc);
	
	}
	fclose(fpOut);
	echo(s,"\n\n");
	return 0;
}
void choice()
{
	int choice;
	echo(s,"1.֡��װ\n");
	echo(s,"2.֡����\n");
	echo(s,"3.�˳�\n");
	echo(s,"\t��ѡ�����:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		encapsulation();
		break;
	case 2:
		unPack();
		break;
	case 3:
		echo(s,"��ӭʹ��....\n");
		exit(0);
	default:
		putchar('\a');
		echo(s,"�����1-3��������ѡ��\n");
			
	}
}
int main(int argc,char **argv)
{
	while(1)
	{
		
		choice();
		echo(s,"\n");
	}
	return 0;
	
}