#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500

// ���װ����
int Unpack(){
	char c,data[MAXSIZE];
    int temp[10];
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
	int frameCnt=1;

	for(int j=0;j<frameCnt;j++){
        int iplen=0;
		/*ѭ��������֡����Ϣ*/
		// ���
		printf("\n���ݰ����: %d\n",j+1);
		// ǰ����
		printf("%s","�汾��: ");
		// for (int i=0;i<7;i++){
		// 	c=fgetc(fpOut);
		// 	printf("%.2X\n",(unsigned char)c);
		// }
        c=fgetc(fpOut);
        temp[0]=c;
        printf("%x\n",(unsigned char)(c>>4));

        printf("%s","�ײ�����: ");
  
        printf("%.x\n",(unsigned char)(c & 0xf));
		// ���ַ���
		printf("%s","���ַ���: ");
		c=fgetc(fpOut);
		printf("%.2X\n",(unsigned char)c);
        temp[0] = (temp[0]<<8)+c;
		// �ܳ���
		printf("%s","�ܳ���: ");
        int tlen=0;
		for (int i=0;i<2;i++){
			c=fgetc(fpOut);
            tlen= (tlen<<8) + c;
			printf("%.2X",(unsigned char)c);
		}
        printf("\n");
        iplen=tlen-20;
        temp[1]=tlen;

        // ��ʶ
		printf("%s","��ʶ: ");
		for (int i=0;i<2;i++){
			c=fgetc(fpOut);
            temp[2] = (temp[2]<<8) +c;
			printf("%.2X",(unsigned char)c);
		}
		printf("\n");	
        // ��־
		printf("%s","��־:  ");
        c=fgetc(fpOut);
        printf("DF: %d\t",0);
        printf("MF: %.1x\n",c>>5);
        temp[3]=c;
        int tempt=c & 0x1f;
        c=fgetc(fpOut);
        temp[3] = (temp[3]<<8) +c;
        printf("Ƭƫ�ƣ�%.4x\n",tempt<<8 + c);
		
		// ����ʱ��
        printf("%s","����ʱ��: ");
        c=fgetc(fpOut);
        temp[4]=c;
        printf("%.2x\n",(unsigned char)c);
        // Э��
        printf("%s","Э��: ");
        c=fgetc(fpOut);
        temp[4]=(temp[4]<<8) +c;
        printf("%.2x\n",(unsigned char)c);
        // �ײ�У���
        printf("%s","�ײ�У���: ");
        for(int i=0;i<2;i++){
            c=fgetc(fpOut);
            temp[5] = (temp[5]<<8) + c;
            printf("%.2x",(unsigned char)c);
        }
        printf("\n");
        // Դ��ַ
		printf("%s","Դip��ַ: ");
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
        //Ŀ�ĵ�ַ
		printf("%s","Ŀ��ip��ַ: ");
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


        printf("%s","���ݣ�");
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
        printf("\n�ײ�У��ͣ�%.4x",jy);
	}

	fclose(fpOut);
	printf("\n %s","���װ����.\n");
	return 0;
}

int main(){
	Unpack();
    return 0;
}
