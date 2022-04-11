#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500

// 解封装函数
int Unpack(){
	char c,data[MAXSIZE];
    int temp[10];
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
	int frameCnt=1;

	for(int j=0;j<frameCnt;j++){
        int iplen=0;
		/*循环逐个输出帧的信息*/
		// 序号
		printf("\n数据包序号: %d\n",j+1);
		// 前导码
		printf("%s","版本号: ");
		// for (int i=0;i<7;i++){
		// 	c=fgetc(fpOut);
		// 	printf("%.2X\n",(unsigned char)c);
		// }
        c=fgetc(fpOut);
        temp[0]=c;
        printf("%x\n",(unsigned char)(c>>4));

        printf("%s","首部长度: ");
  
        printf("%.x\n",(unsigned char)(c & 0xf));
		// 区分服务
		printf("%s","区分服务: ");
		c=fgetc(fpOut);
		printf("%.2X\n",(unsigned char)c);
        temp[0] = (temp[0]<<8)+c;
		// 总长度
		printf("%s","总长度: ");
        int tlen=0;
		for (int i=0;i<2;i++){
			c=fgetc(fpOut);
            tlen= (tlen<<8) + c;
			printf("%.2X",(unsigned char)c);
		}
        printf("\n");
        iplen=tlen-20;
        temp[1]=tlen;

        // 标识
		printf("%s","标识: ");
		for (int i=0;i<2;i++){
			c=fgetc(fpOut);
            temp[2] = (temp[2]<<8) +c;
			printf("%.2X",(unsigned char)c);
		}
		printf("\n");	
        // 标志
		printf("%s","标志:  ");
        c=fgetc(fpOut);
        printf("DF: %d\t",0);
        printf("MF: %.1x\n",c>>5);
        temp[3]=c;
        int tempt=c & 0x1f;
        c=fgetc(fpOut);
        temp[3] = (temp[3]<<8) +c;
        printf("片偏移：%.4x\n",tempt<<8 + c);
		
		// 生存时间
        printf("%s","生存时间: ");
        c=fgetc(fpOut);
        temp[4]=c;
        printf("%.2x\n",(unsigned char)c);
        // 协议
        printf("%s","协议: ");
        c=fgetc(fpOut);
        temp[4]=(temp[4]<<8) +c;
        printf("%.2x\n",(unsigned char)c);
        // 首部校验和
        printf("%s","首部校验和: ");
        for(int i=0;i<2;i++){
            c=fgetc(fpOut);
            temp[5] = (temp[5]<<8) + c;
            printf("%.2x",(unsigned char)c);
        }
        printf("\n");
        // 源地址
		printf("%s","源ip地址: ");
		for (int i=0;i<4;i++){
			c=fgetc(fpOut);
            if(i==0){
                temp[6]=c;
            }
            if(i==1){
                temp[6] = (temp[6]<<8) + c;
            }
            if(i==2){
                temp[7]=c;
            }
            if(i==3){
                temp[7] = (temp[7]<<8) + c;
            }
			printf("%.3d",(unsigned char)c);
			if (i!=3)
				printf("%s",".");	
		}
		printf("%s","\n");
        //目的地址
		printf("%s","目的ip地址: ");
		for (int i=0;i<4;i++){
			c=fgetc(fpOut);
            if(i==0){
                temp[8]=c;
            }
            if(i==1){
                temp[8] = (temp[8]<<8) + c;
            }
            if(i==2){
                temp[9]=c;
            }
            if(i==3){
                temp[9] = (temp[9]<<8) + c;
            }
			printf("%.3d",(unsigned char)c);
			if (i!=3)
				printf("%s",".");	
		}
		printf("%s","\n");


        printf("%s","数据：");
        while(iplen--){
 			c=fgetc(fpOut);
			printf("%.2X",(unsigned char)c);           
        }

        printf("\n");
        int end=0;
        for(int i=0;i<10;i++){
            end+=temp[i];
        }
        int sum=((end & 0xff00)>>16) + (end& 0x00ff);
        int jy=~sum;
        jy=(unsigned char)temp[5];
        printf("\n首部校验和：%.4x",jy);
	}

	fclose(fpOut);
	printf("\n %s","解封装结束.\n");
	return 0;
}

int main(){
	Unpack();
    return 0;
}
