#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500



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
    int dlen=0; // 记录数据字节数
    int cnt=0;  // 记录分组数
    int mor=0;  // 余数

	fseek(fpIn,0,SEEK_END);  // 求出总长度
	dlen=ftell(fpIn);         // byte长度
    rewind(fpIn);            // 重置指针到开头

    cnt=dlen/(1500-20);           // 分组数
    mor=dlen%(1500-20);           

    // fputc中每次写入一个字节，也就是两个16进制数(8b，1B)。如：0xaa
    // 所以6个Byte的MAC地址需要用长度为6的数组存储。
    int ser=0;     // 可选服务
    

    int src[4];     // 源MAC
    int dst[4];
	printf("%s","请输入源ip(8位) :");
    scanf("%d %d %d %d",src,src+1,src+2,src+3);
    printf("%s","请输入mudiip(8位) :");
    scanf("%d %d %d %d",dst,dst+1,dst+2,dst+3);

    printf("%s","请输入可选服务:");
    scanf("%x",&ser);

    // 开始封装帧，并写入文件
    for(int j=0;j<=cnt;j++){
        //写入0.5B的版本号 + 写入0.5B首部长度
		fputc(0x45,fpOut);   

        //写入1B的区分服务
		fputc(ser,fpOut);   

        //写入2B总长度
        int total[2];   // 总长度
        int tlen=1500;
        int lastCnt=0;  // 已经到最后一个ip报
        if(j==cnt){
            lastCnt=ftell(fpIn);
            tlen=dlen-lastCnt + 20;
        }
        printf("tlen:%d \n",tlen);
        total[0]=(tlen & 0xff00) >> 8 ;
        total[1]=(tlen +20) & 0x00ff;
		for(int i=0;i<2;i++){
			fputc(total[i],fpOut);   
		}

		//写入2B标识符
        for(int i=0;i<2;i++){
            fputc(0x0,fpOut);
        }
        int pianyi=0;
        int offset[2];  // 2*8 > 13
        //写入标志，DF默认位0,MF看情况
        pianyi=j*1480/8;    // 偏移量
        offset[0]=(pianyi && 0xff00)>>8;
        offset[1]=(pianyi && 0x00ff);
        // 00(MF)(offset[0])
        if(j!=cnt){ // MF=1
            int temp= 1<<5 + offset[0];
            fputc(temp,fpOut);
        }else{  // MF=0
            fputc(0+offset[0],fpOut);
        }
        fputc(offset[1],fpOut);

        // 1B生存时间
        fputc(255,fpOut);

        // 1B协议   TCP是6，UDP是17
        fputc(6,fpOut);

        // 2B首部校验和
        for(int i=0;i<2;i++){
            fputc(0x00,fpOut);
        }
        
        // 写入源地址
        for(int i=0;i<4;i++){
            fputc(src[i],fpOut);
        }

        // 写入目的地址
        for(int i=0;i<4;i++){
            fputc(dst[i],fpOut);
        }

        //写入数据部分
        if(j!=cnt){
		// 不是最后一个数据,则前面的数据都应该是1500-20
			fread(data,sizeof(char),1480,fpIn);
			fwrite(data,sizeof(char),1480,fpOut);
		}else{
			//最后一段数据,需要额外处理,获取长度
			lastCnt=ftell(fpIn);
			fread(data,sizeof(char),dlen-lastCnt,fpIn);
			fwrite(data,sizeof(char),dlen-lastCnt,fpOut);
		}
    }

    fclose(fpIn);
    fclose(fpOut);

    printf("%s","封装结束.\n");
    return 0;
}

int main(){
	Pack();
}
