#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void add_a(char a[11][11]);				//���a����ĺ������� 
void add_b(char b[11][11]);				//���b����ĺ������� 
void add(char a[11][11],int n);		  	//��a���������a���׵ĺ������� 
void addelse(char a[11][11]);			//��a������������Աߵ����ֺ������� 
void print(char a[11][11]);				//�������ĺ������� 
int main()
{
	srand((unsigned)time (NULL));		//��ʼ������������� 
	char a[11][11]; 					//ɨ������ 
	char b[11][11];						//�Ǻ����� 
	int num;							//���� 
	int m,n,count=0;					//������к��� ,��������Ĵ��� 
	add_a(a);
	add_b(b);
	printf("�����������(0-121֮��)=");
	scanf("%d",&num); 
	add(a,num);
	print(a);
	addelse(a); 
	printf("�������������\n");
	print(a);
	printf("ʵ�ʵ�����%d\n",num); 
	while(1)							//������Ϸ���ظ������к��� 
	{
		printf("�������±�(�ո����)��"); 
		scanf("%d %d",&m,&n);
		if(a[m-1][n-1]==57)
		{
			printf("You lose.");		//�㵽�ף���ʧ�� 
			break;						//����ѭ�� 
		}
		else							//����������Ϸ 
		{
			b[m-1][n-1]=a[m-1][n-1];	//��a�����е�����һ������ֵ��ȫΪ * ��b������ 
			print(b);					//���b���� 
		}
		count++;
		if(count==121-num)				//����������ĸ��Ӷ���ɨ��ʱ��ʤ���� 
		{
			printf("You win!");
			break;						//����ѭ�� 
		}	 
		
	}
	return 0;							//������� 
} 
void add_a(char a[11][11])		
{
	int i,j;
	for(i=0;i<11;i++) 					//�� 0 ���a���� 
	{
		for(j=0;j<11;j++)
		{
			a[i][j]=48;
		}
	} 
}
void add_b(char b[11][11])
{
	int i,j;
	for(i=0;i<11;i++) 					//�� * ���b���� 
	{
		for(j=0;j<11;j++)
		{
			b[i][j]=42;
		}
	} 
}
void add(char a[11][11],int n)			//������a��������n����
{
	int k=0;
	int x,y;
	while(1)
	{
		x=rand()%11;					//���������һ�� 
		y=rand()%11;					//���һ�� 
		if(a[x][y]!=57)
		{
			a[x][y]=57;					//�ж���������λ���Ƿ��Ѿ���* 
			k++;
		}
		if(k==n)
		{
			break;						//����n����ʱ���˳�ѭ�� 
		}
	}	
} 
void addelse(char a[11][11])			//����ÿ��������Χ����������ֵ�� 
{
	int r=0,c=0;
	int z=0;
	for(r=0;r<11;r++)
	{
		for(c=0;c<11;c++)				//�������� 
		{
			if(a[r][c]!=57)				//�������ַ������ף����ж�����Χ������ 
			{
				if(r==0&&c==0)  		//���a[0][0] 
				{
					if(a[r][c+1]==57)
						z++;
					if(a[r+1][c]==57)
						z++;
					if(a[r+1][c+1]==57)	
						z++;
					a[r][c]=z+48;
					z=0;
					continue;
				} 
				
				else if(r==0&&c==10)	//���a[0][10] 
				{
					if(a[r][c-1]==57)
						z++;
					if(a[r+1][c-1]==57)
						z++;
					if(a[r+1][c]==57)	
						z++;
					a[r][c]=z+48;
					z=0;
					continue;
				}
				
				else if(r==10&&c==0)	//���a[10][0] 
				{
					if(a[r-1][c]==57)
						z++;
					if(a[r-1][c+1]==57)
						z++;
					if(a[r][c+1]==57)	
						z++;
					a[r][c]=z+48;
					z=0;
					continue;
				}
				
				else if(r==10&&c==10)	//���a[10][10] 
				{
					if(a[r-1][c]==57)
						z++;
					if(a[r-1][c-1]==57)
						z++;
					if(a[r][c-1]==57)	
						z++;
					a[r][c]=z+48;
					z=0;
					continue;
				}
				
				else if(r==0&&c>0&&c<10)//��0�еı� a[0][c]
				{
					if(a[r][c-1]==57)
						z++;
					if(a[r][c+1]==57)
						z++;
					if(a[r+1][c]==57)
						z++;
					if(a[r+1][c-1]==57)
						z++;
					if(a[r+1][c+1]==57)
						z++;
					a[r][c]=z+48;
					z=0;
					continue;
				}
				
				else if(c==0&&r>0&&r<10)//��0�еı� a[r][0]
				{
					if(a[r][c+1]==57)
						z++;
					if(a[r-1][c]==57)
						z++;
					if(a[r-1][c+1]==57)
						z++;
					if(a[r+1][c]==57)
						z++;
					if(a[r+1][c+1]==57)
						z++;
					a[r][c]=z+48;
					z=0;
					continue;
				}
			
				else if(r==10&&c>0&&c<10)//��10�еı� a[10][c]
				{
					if(a[r][c-1]==57)
						z++;
					if(a[r][c+1]==57)
						z++;
					if(a[r-1][c]==57)
						z++;
					if(a[r-1][c-1]==57)
						z++;
					if(a[r-1][c+1]==57)
						z++;
					a[r][c]=z+48;
					z=0;
					continue;
				}
				
				else if(c==10&&r>0&&r<10)//��10�еı� a[r][10]
				{
					if(a[r][c-1]==57)
						z++;
					if(a[r-1][c-1]==57)
						z++;
					if(a[r+1][c-1]==57)
						z++;
					if(a[r-1][c]==57)
						z++;
					if(a[r+1][c]==57)
						z++;
					a[r][c]=z+48;
					z=0;
					continue;
				}
				else
				{
					if(a[r][c-1]==57)//����λ�õ����� 
						z++;
					if(a[r][c+1]==57)
						z++;
					if(a[r-1][c]==57)
						z++;
					if(a[r+1][c]==57)
						z++;
					if(a[r-1][c-1]==57)
						z++;
					if(a[r-1][c+1]==57)
						z++;
					if(a[r+1][c-1]==57)
						z++;
					if(a[r+1][c+1]==57)
						z++;
					a[r][c]=z+48;
					z=0;
				}
			}
		}
	} 
}
void print(char a[11][11])				//������� 
{
	int p,q;
	for(p=0;p<11;p++)
	{
		for(q=0;q<11;q++)				//�������� 
		{
			printf("%5c",a[p][q]);
		}
		printf("\n");
	}
}
