#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500


unsigned int  crc8(char *ptr,unsigned  int len){
	// CRC校验,ptr是需要计算的数组首地址,len是需要计算的长度
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

int Pack(){
    FILE *fpIn, *fpOut;
    char data[MAXSIZE];
	if((fpIn=fopen("in.txt","a+"))==NULL)
	{
		printf("%s","打开文件失败");
		return 1;
	}
	if((fpOut=fopen("out.txt","wb"))==NULL)
	{
		printf("%s","写入文件失败");
		return 1;
    }
    int len=0;  // 记录字节数
    int cnt=0;  // 记录分组数
    int mor=0;  // 余数

	fseek(fpIn,0,SEEK_END);  // 求出总长度
	len=ftell(fpIn);         // byte长度
    rewind(fpIn);            // 重置指针到开头

    cnt=len/1500;            // 分组数
    mor=len%1500;
    // 不足46bytes需要填充，因为帧最少要64B
    if(mor<46){
        for (int i=0;i<(46-mor);i++){
            fputc(0x0,fpIn);
        }
    }

    // fputc中每次写入一个字节，也就是两个16进制数(8b，1B)。如：0xaa
    // 所以6个Byte的MAC地址需要用长度为6的数组存储。
    int src[6];  // 源MAC
    int dst[6];  // 目标MAC
    int type[2]; // 类型字段


	printf("%s","请输入目的MAC(形如 XX-XX-XX-XX-XX-XX) :");
    scanf("%x-%x-%x-%x-%x-%x",dst,dst+1,dst+2,dst+3,dst+4,dst+5);

	printf("%s","请输入源MAC(形如 XX-XX-XX-XX-XX-XX) :");
    scanf("%x-%x-%x-%x-%x-%x",src,src+1,src+2,src+3,src+4,src+5);
    printf("%s","请输入类型字段（0x8000或者0x8060）:");
    scanf("%2x%2x",type,type+1);


    // 开始封装帧，并写入文件
    for(int j=0;j<=cnt;j++){
        //写入7B帧前导码
        for(int i=0;i<7;i++)
			fputc(0xaa,fpOut);   
        //写入1B帧定界符
		fputc(0xab,fpOut);       
        //写入6B目的MAC
		for(int i=0;i<6;i++){
			fputc(dst[i],fpOut);    
		}
        //写入6B源MAC
		for(int i=0;i<6;i++){
			fputc(src[i],fpOut);   
		}
		//写入2B类型号
        for(int i=0;i<2;i++){
            fputc(type[i],fpOut);
        }
        //写入数据部分
        int lastCnt=0;
        int dataCrc=0;
        if(j!=cnt){
		/*不是最后一个数据,则前面的数据都应该是1500*/
			fread(data,sizeof(char),1500,fpIn);
			fwrite(data,sizeof(char),1500,fpOut);
			dataCrc=crc8(data,1500);
			fputc(dataCrc,fpOut);
		}else{
			//最后一段数据,需要额外处理,获取长度
			lastCnt=ftell(fpIn);
			fread(data,sizeof(char),len-lastCnt,fpIn);
			fwrite(data,sizeof(char),len-lastCnt,fpOut);
			dataCrc=crc8(data,len-lastCnt);
			fputc(dataCrc,fpOut);
		}
    }

    fclose(fpIn);
    fclose(fpOut);

    printf("%s","封装结束.\n");
    return 0;
}

// 解封装函数
int Unpack(){
	char c,data[MAXSIZE];
	FILE *fpOut;
	if((fpOut=fopen("out.txt","rb"))==NULL)
	{
		printf("%s","文件打开失败!");
		return 1;
	}
	// 获取总长度
	int len=0;
	fseek(fpOut,0,SEEK_END);
	len=ftell(fpOut);
	rewind(fpOut);	// 重置指针

	// 获取帧个数
	int frameCnt=0;
	while(1){
		// 此循环为了获取帧的个数主要思路:连续7个0xaa,第8个是0xab
		if(ftell(fpOut)>=len){
			break;
		}
		for(int i=0;i<7;i++){
			if(ftell(fpOut)>=len){
				break;
			}
			if(fgetc(fpOut)!=0xaa){
				i=-1;
			}
		}
		if(ftell(fpOut)>=len){
			break;
		}
		if(fgetc(fpOut)==0xab){
			++frameCnt;
		}
	}
	rewind(fpOut);

	for(int j=0;j<frameCnt;j++){
		/*循环逐个输出帧的信息*/
		// 序号
		printf("\n帧序号: %d\n",j+1);
		// 前导码
		printf("%s","帧前导码: ");
		for (int i=0;i<7;i++){
			c=fgetc(fpOut);
			printf("%.2X\n",(unsigned char)c);
		}
		// 定界符
		printf("%s","帧前定界符: ");
		c=fgetc(fpOut);
		printf("%.2X\n",(unsigned char)c);
		// 目的地址
		printf("%s","目的MAC地址: ");
		for (int i=0;i<6;i++){
			c=fgetc(fpOut);
			printf("%.2X",(unsigned char)c);
			if (i!=5)
				printf("%s","-");	
		}
		printf("%s","\n");	
		// 源地址
		printf("%s","源MAC地址: ");
		for (int i=0;i<6;i++){
			c=fgetc(fpOut);
			printf("%.2X",(unsigned char)c);
			if (i!=5)
				printf("%s","-");	
		}
		printf("%s","\n");
		// 类型号
		printf("%s","类型号: ");
		for(int i=0;i<2;i++){
			c=fgetc(fpOut);
			printf("%.2X",(unsigned char)c);
		}
		printf("%s","\n");
		// CRC
		int dataStart,dataEnd,srcCrc,nowCrc,extraLength;
		if(j!=frameCnt-1){
			//不是最后一个帧,则数据长度都是1500
			fread(data,sizeof(char),1500,fpOut);
			srcCrc=fgetc(fpOut);
			nowCrc=crc8(data,1500);
		}else{
			//最后一个帧,额外处理
			dataStart=ftell(fpOut);
			fseek(fpOut,-1,SEEK_END);
			dataEnd=ftell(fpOut)-1;
			extraLength=dataEnd-dataStart+1;
			srcCrc=fgetc(fpOut);
			fseek(fpOut,dataStart,SEEK_SET);
			fread(data,sizeof(char),extraLength,fpOut);
			nowCrc=crc8(data,extraLength);
		}
 
		printf("本次CRC: %d \n",nowCrc);
		printf("%s","行为: ");
		if (nowCrc==srcCrc) //比较CRC,是否出错
			printf("%s","接受");
		else
			printf("%s","丢弃");
		printf("  前次CRC: %d \n",srcCrc);
	}

	fclose(fpOut);
	printf("%s","解封装结束.\n");
	return 0;
}


void choice()
{
	int choice;
	printf("%s","1.帧封装\n");
	printf("%s","2.帧解析\n");
	printf("%s","3.退出\n");
	printf("%s","\t请选择序号:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		Pack();
		break;
	case 2:
		Unpack();
		break;
	case 3:
		printf("%s","欢迎使用....\n");
		exit(0);
	default:
		putchar('\a');
		printf("%s","序号在1-3，请重新选择\n");
			
	}
}
int main(){
	while(1){
		choice();
		printf("%s","\n");
	}

    return 0;
}
