#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500



int Pack(){
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
    int dlen=0; // ��¼�����ֽ���
    int cnt=0;  // ��¼������
    int mor=0;  // ����

	fseek(fpIn,0,SEEK_END);  // ����ܳ���
	dlen=ftell(fpIn);         // byte����
    rewind(fpIn);            // ����ָ�뵽��ͷ

    cnt=dlen/(1500-20);           // ������
    mor=dlen%(1500-20);           

    // fputc��ÿ��д��һ���ֽڣ�Ҳ��������16������(8b��1B)���磺0xaa
    // ����6��Byte��MAC��ַ��Ҫ�ó���Ϊ6������洢��
    int ser=0;     // ��ѡ����
    

    int src[4];     // ԴMAC
    int dst[4];
	printf("%s","������Դip(8λ) :");
    scanf("%d %d %d %d",src,src+1,src+2,src+3);
    printf("%s","������mudiip(8λ) :");
    scanf("%d %d %d %d",dst,dst+1,dst+2,dst+3);

    printf("%s","�������ѡ����:");
    scanf("%x",&ser);

    // ��ʼ��װ֡����д���ļ�
    for(int j=0;j<=cnt;j++){
        //д��0.5B�İ汾�� + д��0.5B�ײ�����
		fputc(0x45,fpOut);   

        //д��1B�����ַ���
		fputc(ser,fpOut);   

        //д��2B�ܳ���
        int total[2];   // �ܳ���
        int tlen=1500;
        int lastCnt=0;  // �Ѿ������һ��ip��
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

		//д��2B��ʶ��
        for(int i=0;i<2;i++){
            fputc(0x0,fpOut);
        }
        int pianyi=0;
        int offset[2];  // 2*8 > 13
        //д���־��DFĬ��λ0,MF�����
        pianyi=j*1480/8;    // ƫ����
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

        // 1B����ʱ��
        fputc(255,fpOut);

        // 1BЭ��   TCP��6��UDP��17
        fputc(6,fpOut);

        // 2B�ײ�У���
        for(int i=0;i<2;i++){
            fputc(0x00,fpOut);
        }
        
        // д��Դ��ַ
        for(int i=0;i<4;i++){
            fputc(src[i],fpOut);
        }

        // д��Ŀ�ĵ�ַ
        for(int i=0;i<4;i++){
            fputc(dst[i],fpOut);
        }

        //д�����ݲ���
        if(j!=cnt){
		// �������һ������,��ǰ������ݶ�Ӧ����1500-20
			fread(data,sizeof(char),1480,fpIn);
			fwrite(data,sizeof(char),1480,fpOut);
		}else{
			//���һ������,��Ҫ���⴦��,��ȡ����
			lastCnt=ftell(fpIn);
			fread(data,sizeof(char),dlen-lastCnt,fpIn);
			fwrite(data,sizeof(char),dlen-lastCnt,fpOut);
		}
    }

    fclose(fpIn);
    fclose(fpOut);

    printf("%s","��װ����.\n");
    return 0;
}

int main(){
	Pack();
}
