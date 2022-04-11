#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500


unsigned int  crc8(char *ptr,unsigned  int len){
	// CRCУ��,ptr����Ҫ����������׵�ַ,len����Ҫ����ĳ���
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
		printf("%s","���ļ�ʧ��");
		return 1;
	}
	if((fpOut=fopen("out.txt","wb"))==NULL)
	{
		printf("%s","д���ļ�ʧ��");
		return 1;
    }
    int len=0;  // ��¼�ֽ���
    int cnt=0;  // ��¼������
    int mor=0;  // ����

	fseek(fpIn,0,SEEK_END);  // ����ܳ���
	len=ftell(fpIn);         // byte����
    rewind(fpIn);            // ����ָ�뵽��ͷ

    cnt=len/1500;            // ������
    mor=len%1500;
    // ����46bytes��Ҫ��䣬��Ϊ֡����Ҫ64B
    if(mor<46){
        for (int i=0;i<(46-mor);i++){
            fputc(0x0,fpIn);
        }
    }

    // fputc��ÿ��д��һ���ֽڣ�Ҳ��������16������(8b��1B)���磺0xaa
    // ����6��Byte��MAC��ַ��Ҫ�ó���Ϊ6������洢��
    int src[6];  // ԴMAC
    int dst[6];  // Ŀ��MAC
    int type[2]; // �����ֶ�


	printf("%s","������Ŀ��MAC(���� XX-XX-XX-XX-XX-XX) :");
    scanf("%x-%x-%x-%x-%x-%x",dst,dst+1,dst+2,dst+3,dst+4,dst+5);

	printf("%s","������ԴMAC(���� XX-XX-XX-XX-XX-XX) :");
    scanf("%x-%x-%x-%x-%x-%x",src,src+1,src+2,src+3,src+4,src+5);
    printf("%s","�����������ֶΣ�0x8000����0x8060��:");
    scanf("%2x%2x",type,type+1);


    // ��ʼ��װ֡����д���ļ�
    for(int j=0;j<=cnt;j++){
        //д��7B֡ǰ����
        for(int i=0;i<7;i++)
			fputc(0xaa,fpOut);   
        //д��1B֡�����
		fputc(0xab,fpOut);       
        //д��6BĿ��MAC
		for(int i=0;i<6;i++){
			fputc(dst[i],fpOut);    
		}
        //д��6BԴMAC
		for(int i=0;i<6;i++){
			fputc(src[i],fpOut);   
		}
		//д��2B���ͺ�
        for(int i=0;i<2;i++){
            fputc(type[i],fpOut);
        }
        //д�����ݲ���
        int lastCnt=0;
        int dataCrc=0;
        if(j!=cnt){
		/*�������һ������,��ǰ������ݶ�Ӧ����1500*/
			fread(data,sizeof(char),1500,fpIn);
			fwrite(data,sizeof(char),1500,fpOut);
			dataCrc=crc8(data,1500);
			fputc(dataCrc,fpOut);
		}else{
			//���һ������,��Ҫ���⴦��,��ȡ����
			lastCnt=ftell(fpIn);
			fread(data,sizeof(char),len-lastCnt,fpIn);
			fwrite(data,sizeof(char),len-lastCnt,fpOut);
			dataCrc=crc8(data,len-lastCnt);
			fputc(dataCrc,fpOut);
		}
    }

    fclose(fpIn);
    fclose(fpOut);

    printf("%s","��װ����.\n");
    return 0;
}

int main(){
	Pack();
    return 0;
}
