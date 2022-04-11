#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void add_a(char a[11][11]);				//填充a数组的函数声明 
void add_b(char b[11][11]);				//填充b数组的函数声明 
void add(char a[11][11],int n);		  	//在a数组中填充a个雷的函数声明 
void addelse(char a[11][11]);			//在a数组中填充雷旁边的数字函数声明 
void print(char a[11][11]);				//输出数组的函数声明 
int main()
{
	srand((unsigned)time (NULL));		//初始化随机数发生器 
	char a[11][11]; 					//扫雷数组 
	char b[11][11];						//星号数组 
	int num;							//雷数 
	int m,n,count=0;					//输入的行和列 ,还有输入的次数 
	add_a(a);
	add_b(b);
	printf("请输入地雷数(0-121之间)=");
	scanf("%d",&num); 
	add(a,num);
	print(a);
	addelse(a); 
	printf("随机地雷阵如下\n");
	print(a);
	printf("实际地雷数%d\n",num); 
	while(1)							//进行游戏，重复输入行和列 
	{
		printf("请输入下标(空格隔开)："); 
		scanf("%d %d",&m,&n);
		if(a[m-1][n-1]==57)
		{
			printf("You lose.");		//点到雷，则失败 
			break;						//结束循环 
		}
		else							//正常进行游戏 
		{
			b[m-1][n-1]=a[m-1][n-1];	//将a数组中的数字一个个赋值到全为 * 的b数组中 
			print(b);					//输出b数组 
		}
		count++;
		if(count==121-num)				//当除雷以外的格子都被扫清时，胜利。 
		{
			printf("You win!");
			break;						//结束循环 
		}	 
		
	}
	return 0;							//程序结束 
} 
void add_a(char a[11][11])		
{
	int i,j;
	for(i=0;i<11;i++) 					//用 0 填充a数组 
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
	for(i=0;i<11;i++) 					//用 * 填充b数组 
	{
		for(j=0;j<11;j++)
		{
			b[i][j]=42;
		}
	} 
}
void add(char a[11][11],int n)			//在数组a中随机填充n个雷
{
	int k=0;
	int x,y;
	while(1)
	{
		x=rand()%11;					//产生在随机一行 
		y=rand()%11;					//随机一列 
		if(a[x][y]!=57)
		{
			a[x][y]=57;					//判断这个随机的位置是否已经是* 
			k++;
		}
		if(k==n)
		{
			break;						//当有n个雷时，退出循环 
		}
	}	
} 
void addelse(char a[11][11])			//计算每个格子周围雷数，并赋值。 
{
	int r=0,c=0;
	int z=0;
	for(r=0;r<11;r++)
	{
		for(c=0;c<11;c++)				//遍历数组 
		{
			if(a[r][c]!=57)				//如果这个字符不是雷，才判断它周围的雷数 
			{
				if(r==0&&c==0)  		//填充a[0][0] 
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
				
				else if(r==0&&c==10)	//填充a[0][10] 
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
				
				else if(r==10&&c==0)	//填充a[10][0] 
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
				
				else if(r==10&&c==10)	//填充a[10][10] 
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
				
				else if(r==0&&c>0&&c<10)//第0行的边 a[0][c]
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
				
				else if(c==0&&r>0&&r<10)//第0列的边 a[r][0]
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
			
				else if(r==10&&c>0&&c<10)//第10行的边 a[10][c]
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
				
				else if(c==10&&r>0&&r<10)//第10列的边 a[r][10]
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
					if(a[r][c-1]==57)//其他位置的数字 
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
void print(char a[11][11])				//输出数组 
{
	int p,q;
	for(p=0;p<11;p++)
	{
		for(q=0;q<11;q++)				//遍历数组 
		{
			printf("%5c",a[p][q]);
		}
		printf("\n");
	}
}
