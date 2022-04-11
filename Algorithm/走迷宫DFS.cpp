//走迷宫
//4 5

//. . . . #
//. . . . .
//# @ . . .
//. # . . #

//  .代表可以走，#代表不能走，@代表起点 
#include <bits/stdc++.h>
using namespace std;
char room[23][23];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int Wx,Hy,num;
#define check(x,y)(x<Wx&&x>=0&&y<Hy&&y>=0)
struct node {
	int x,y;
};
void DFS(int dx,int dy){
	room[dx][dy]='#';
	num++;
	for(int i=0;i<4;i++){
		int newx=dx+dir[i][0];
		int newy=dy+dir[i][1];
		if(check(newx,newy)&&room[newx][newy]=='.'){
			DFS(newx,newy);
			//cout << "    back:"<<dx<<dy<<endl;     //打印退回的点 
		}
	}
}
int main(){
	int x,y,dx,dy;
	while(cin>>Wx>>Hy){
		if(Wx==0&&Hy==0)
			break;
		for(x=0;x<Wx;x++){
			for(y=0;y<Hy;y++){
				cin >> room[x][y];
				if(room[x][y]=='@'){
					dx=x;
					dy=y;
					//cout << "@:" << dx << dy << endl;
				}
			}
		}
		num=0;
		DFS(dx,dy);
		cout<< num << endl;
	}
	return 0;
}
				
				
