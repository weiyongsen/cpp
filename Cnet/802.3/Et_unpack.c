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
 		printf("  前次CRC: %d \n",srcCrc);
		printf("  本次CRC: %d \n",nowCrc-srcCrc);
		printf("%s","行为: ");
		if (nowCrc==srcCrc) //比较CRC,是否出错
			printf("%s","接受");
		else
			printf("%s","丢弃");

	}

	fclose(fpOut);
	printf("%s","解封装结束.\n");
	return 0;
}

int main(){
	Unpack();
    return 0;
}
