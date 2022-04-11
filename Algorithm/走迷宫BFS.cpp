//���Թ�
//4 5

//. . . . #
//. . . . .
//# @ . . .
//. # . . #

//  .��������ߣ�#�������ߣ�@������� 
#include <bits/stdc++.h>
using namespace std;
char room[23][23];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int Wx,Hy,num;
#define check(x,y)(x<Wx&&x>=0&&y<Hy&&y>=0)
struct node {
	int x,y;
};
void BFS(int dx,int dy){
	num=1;
	queue<node>q;
	node start,next;
	start.x=dx;
	start.y=dy;
	q.push(start);
	while(!q.empty()){
		start=q.front();
		q.pop();
		//cout << num <<  " out:" << start.x << start.y << endl;
		for(int i=0;i<4;i++){
			next.x=start.x+dir[i][0];
			next.y=start.y+dir[i][1];
			if(check(next.x,next.y)&&room[next.x][next.y]=='.'){
				room[next.x][next.y]='#';
				num++;
				q.push(next);
			}
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
		BFS(dx,dy);
		cout<< num << endl;
	}
	return 0;
}
				
				
