/*
目标:
封装
1.将inputFile文件中的数据封装成MAC帧,封装好的MAC帧写入outputFile文件中.
2.如果数据长度小于46字节,则补全到46字节
3.如果数据长度大于1500,则封装成多个MAC帧
解封装:
读取outputFile中的数据,并逐个显示帧的信息
其实我们要求还是蛮低的,上面有好多是自己添加的
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
CRC校验,ptr是需要计算的数组首地址,len是需要计算的长度
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
/*帧封装函数*/
{
	int i,dataCrc,nu,j,lastNu,sum;
	FILE *fpIn,*fpOut;
	int src[6],des[6];
	char type[2],data[MAXSIZE];
	if((fpIn=fopen(inputFile,"a+"))==NULL)
	{
		echo(s,"打开文件失败!");
		return 1;
	}
	if((fpOut=fopen(outputFile,"wb"))==NULL)
	{
		echo(s,"写入文件失败");
		return 1;
	}
 
	fseek(fpIn,0,SEEK_END);
	sum=ftell(fpIn);
	nu=sum/1500;
	if((sum-nu*1500)<46)
	{
		for(i=0;i<(46-(sum-nu*1500));i++)
			fputc(0x0,fpIn);   //如果不足,则填充
	}
 
	rewind(fpIn);
 
	echo(s,"请输源MAC:");
	scanf("%x-%x-%x-%x-%x-%x",src,src+1,src+2,src+3,src+4,src+5);
	fflush(stdin);
	echo(s,"请输入目标MAC:");
	scanf("%x-%x-%x-%x-%x-%x",des,des+1,des+2,des+3,des+4,des+5);
	flush();
	echo(s,"请输入类型字段:");
	flush();
	scanf("%2x%2x",type,type+1);
 
	for(j=0;j<nu+1;j++)
	{
		for(i=0;i<7;i++)
			fputc(0xaa,fpOut);   //写入帧前导码
		fputc(0xab,fpOut);       //写入帧定界符
 
		for(i=0;i<6;i++)
		{
			fputc(des[i],fpOut);    //写入目的MAC
		}
		for(i=0;i<6;i++)
		{
			fputc(src[i],fpOut);   //写入源MAC
		}
		
		fputc(type[0],fpOut);     //写入类型号
		fputc(type[1],fpOut);
 
 
		if(j!=nu)
		/*不是最后一个数据,则前面的数据都应该是1500*/
		{
			fread(data,sizeof(char),1500,fpIn);
			fwrite(data,sizeof(char),1500,fpOut);
			dataCrc=crc8(data,1500);
			fputc(dataCrc,fpOut);
		}
		else
		{
			//最后一段数据,需要额外处理,获取长度
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
/*解封装函数*/
{	
	int i,dataStart,dataEnd,srcCrc,nowCrc,dataLength,frameNu=0,sum,j;
	char c,data[MAXSIZE];
	FILE *fpOut;
	if((fpOut=fopen(outputFile,"rb"))==NULL)
	{
		echo(s,"打开文件失败!");
		return 1;
	}
 
	fseek(fpOut,0,SEEK_END);
	sum=ftell(fpOut);
	rewind(fpOut);
 
	while(1)
		/*此循环为了获取帧的个数
		主要思路:连续7个0xaa,第8个是0xab
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
		/*循环逐个输出帧的信息*/
	{
		printf("\n\n帧序号: %d\n\n",j+1);
		echo(s,"帧前导码: ");
		for (i=0;i<7;i++)
		{
			c=fgetc(fpOut);
			echo(.2X,c);
		}
		echo(s,"\n\n");
 
		echo(s,"帧前定界符: ");
		{
			c=fgetc(fpOut);
			echo(.2X,c);
		}
 
		echo(s,"\n\n");
 
		echo(s,"目的MAC地址: ");
		for (i=0;i<6;i++)
		{
			c=fgetc(fpOut);
			echo(.2X,c);
			if (i!=5)
				echo(s,"-");	
		}
		echo(s,"\n\n");	
 
		echo(s,"源MAC地址: ");
		for (i=0;i<6;i++)
		{
			c=fgetc(fpOut);
			echo(.2X,c);
			if (i!=5)
				echo(s,"-");	
		}
		echo(s,"\n\n");
 
		echo(s,"类型号: ");
 
		c=fgetc(fpOut);
		echo(.2X,c);
		c=fgetc(fpOut);
		echo(.2X,c);
 
		if(j!=frameNu-1)
			//不是最后一个帧,则数据长度都是1500
		{
			fread(data,sizeof(char),1500,fpOut);
			srcCrc=fgetc(fpOut);
			nowCrc=crc8(data,1500);
		}
		else
		{
			//最后一个帧,额外处理
			dataStart=ftell(fpOut);
			fseek(fpOut,-1,SEEK_END);
			dataEnd=ftell(fpOut)-1;
			dataLength=dataEnd-dataStart+1;
			srcCrc=fgetc(fpOut);
			fseek(fpOut,dataStart,SEEK_SET);
			fread(data,sizeof(char),dataLength,fpOut);
			nowCrc=crc8(data,dataLength);
		}
 
		printf("\n\n本次CRC:  %d",nowCrc);
		echo(s,"\n\n行为: ");
		if (nowCrc==srcCrc) //比较CRC,是否出错
			echo(s,"接受");
		else
			echo(s,"丢弃");
			printf("  前次CRC:%d",srcCrc);
	
	}
	fclose(fpOut);
	echo(s,"\n\n");
	return 0;
}
void choice()
{
	int choice;
	echo(s,"1.帧封装\n");
	echo(s,"2.帧解析\n");
	echo(s,"3.退出\n");
	echo(s,"\t请选择序号:");
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
		echo(s,"欢迎使用....\n");
		exit(0);
	default:
		putchar('\a');
		echo(s,"序号在1-3，请重新选择\n");
			
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