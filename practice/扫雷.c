#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void add_a(char a[11][11]);
void add_b(char b[11][11]);
void add(char a[11][11],int n);
void addelse(char a[11][11]);
void print(char a[11][11]);
int main()
{
	srand((unsigned)time (NULL));
	char a[11][11]; 			//扫雷数组 
	char b[11][11];				//星号数组 
	int num;					//雷数 
	int m,n,count=0;					//输入的行和列 ,还有输入的次数 
	add_a(a);
	add_b(b);
	printf("请输入地雷数=");
	scanf("%d",&num); 
	add(a,num);
	print(a);
	addelse(a); 
	printf("随机地雷阵如下\n");
	print(a);
	printf("实际地雷数%d\n",num); 
	while(1)					//进行游戏，输入行和列 
	{
		printf("请输入下标(空格隔开)："); 
		scanf("%d %d",&m,&n);
		if(a[m-1][n-1]==57)
		{
			printf("shibai.");	//点到雷，则失败 
			break;
		}
		else
		{
			b[m-1][n-1]=a[m-1][n-1];
			print(b);
		}
		count++;
		if(count==121-num)					//当除雷以外的格子都被扫清时，胜利。 
		{
			printf("You win!");
			break;
		}	 
		
	}
	
	return 0;
} 
void add_a(char a[11][11])
{
	int i,j;
	for(i=0;i<11;i++) 			//用 0 填充a 
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
	for(i=0;i<11;i++) 			//用 * 填充b
	{
		for(j=0;j<11;j++)
		{
			b[i][j]=42;
		}
	} 
}
void add(char a[11][11],int n)				//在数组a中随机填充n个雷
{
	int k=0;
	int x,y;
	while(1)
	{
		x=rand()%10;
		y=rand()%10;
		if(a[x][y]!=57)
		{
			a[x][y]=57;
			k++;
		}
		if(k==n)
		{
			break;
		}
	}
	
} 
void addelse(char a[11][11])				//计算每个格子周围雷数，并赋值。 
{
	int r=0,c=0;
	int z=0;
	for(r=0;r<11;r++)
	{
		for(c=0;c<11;c++)					//遍历数组 
		{
			if(a[r][c]!=57)
			{
				if(r==0&&c==0)  			//填充a[0][0] 
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
				
				else if(r==0&&c==10)		//填充a[0][10] 
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
				
				else if(r==10&&c==0)		//填充a[10][0] 
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
				
				else if(r==10&&c==10)		//填充a[10][10] 
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
				
				else if(r==0&&c>0&&c<10)	//第0行的边 a[0][c]
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
				
				else if(c==0&&r>0&&r<10)	//第0列的边 a[r][0]
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
			
				else if(r==10&&c>0&&c<10)	//第10行的边 a[10][c]
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
				
				else if(c==10&&r>0&&r<10)	//第10列的边 a[r][10]
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
					if(a[r][c-1]==57)	//其他位置的数字 
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
void print(char a[11][11])
{
	int p,q;
	for(p=0;p<11;p++)
	{
		for(q=0;q<11;q++)
		{
			printf("%5c",a[p][q]);
		}
		printf("\n");
	}
}
