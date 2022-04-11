//假设有无数个格子，从某一点开始出发
//走<=20步，有多少种走法
//每走一步时，只能从当前方格移动一格，走到某个相邻的方格上
//走过的格子立即塌陷无法再走第二次

//只能向南、东、西三个方向走
#include <iostream>
#include <cstring> 
using namespace std;
int visited[30][50];
int ways(int i, int j, int n){
	if(n==0)
		return 1;
	visited[i][j]=1;
	int num=0;
	if(!visited[i][j-1])
		num+=ways(i,j-1,n-1);
	if(!visited[i][j+1])
		num+=ways(i,j+1,n-1);
	if(!visited[i+1][j])
		num+=ways(i+1,j,n-1);
	visited[i][j]=0;
	return num;
}
int main(){
	int n;
	cin >> n;
	memset(visited,0,sizeof(visited));
	cout << ways(0,25,n) << endl;
	return 0;
}
