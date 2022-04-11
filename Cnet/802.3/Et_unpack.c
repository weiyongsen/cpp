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

// ���װ����
int Unpack(){
	char c,data[MAXSIZE];
	FILE *fpOut;
	if((fpOut=fopen("out.txt","rb"))==NULL)
	{
		printf("%s","�ļ���ʧ��!");
		return 1;
	}
	// ��ȡ�ܳ���
	int len=0;
	fseek(fpOut,0,SEEK_END);
	len=ftell(fpOut);
	rewind(fpOut);	// ����ָ��

	// ��ȡ֡����
	int frameCnt=0;
	while(1){
		// ��ѭ��Ϊ�˻�ȡ֡�ĸ�����Ҫ˼·:����7��0xaa,��8����0xab
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
		/*ѭ��������֡����Ϣ*/
		// ���
		printf("\n֡���: %d\n",j+1);
		// ǰ����
		printf("%s","֡ǰ����: ");
		for (int i=0;i<7;i++){
			c=fgetc(fpOut);
			printf("%.2X\n",(unsigned char)c);
		}
		// �����
		printf("%s","֡ǰ�����: ");
		c=fgetc(fpOut);
		printf("%.2X\n",(unsigned char)c);
		// Ŀ�ĵ�ַ
		printf("%s","Ŀ��MAC��ַ: ");
		for (int i=0;i<6;i++){
			c=fgetc(fpOut);
			printf("%.2X",(unsigned char)c);
			if (i!=5)
				printf("%s","-");	
		}
		printf("%s","\n");	
		// Դ��ַ
		printf("%s","ԴMAC��ַ: ");
		for (int i=0;i<6;i++){
			c=fgetc(fpOut);
			printf("%.2X",(unsigned char)c);
			if (i!=5)
				printf("%s","-");	
		}
		printf("%s","\n");
		// ���ͺ�
		printf("%s","���ͺ�: ");
		for(int i=0;i<2;i++){
			c=fgetc(fpOut);
			printf("%.2X",(unsigned char)c);
		}
		printf("%s","\n");
		// CRC
		int dataStart,dataEnd,srcCrc,nowCrc,extraLength;
		if(j!=frameCnt-1){
			//�������һ��֡,�����ݳ��ȶ���1500
			fread(data,sizeof(char),1500,fpOut);
			srcCrc=fgetc(fpOut);
			nowCrc=crc8(data,1500);
		}else{
			//���һ��֡,���⴦��
			dataStart=ftell(fpOut);
			fseek(fpOut,-1,SEEK_END);
			dataEnd=ftell(fpOut)-1;
			extraLength=dataEnd-dataStart+1;
			srcCrc=fgetc(fpOut);
			fseek(fpOut,dataStart,SEEK_SET);
			fread(data,sizeof(char),extraLength,fpOut);
			nowCrc=crc8(data,extraLength);
		}
 		printf("  ǰ��CRC: %d \n",srcCrc);
		printf("  ����CRC: %d \n",nowCrc-srcCrc);
		printf("%s","��Ϊ: ");
		if (nowCrc==srcCrc) //�Ƚ�CRC,�Ƿ����
			printf("%s","����");
		else
			printf("%s","����");

	}

	fclose(fpOut);
	printf("%s","���װ����.\n");
	return 0;
}

int main(){
	Unpack();
    return 0;
}
