//N�����У����1��N�����м���R�������·��
//ÿ����·�����������У��г��Ⱥ͹�·���������ԡ�
//Bobֻ��K��Ǯ������ӳ���1�ߵ�����N������̹���Ҫ�߶೤��·�����������N����
//��-1
//2<=N<=100
//0<=K<=10000
//1<=R<=10000
//ÿ��·�ĳ��� L, 1 <= L <= 100
//ÿ��·�Ĺ�·��T , 0 <= T <= 100
/*���룺
		K
		N
		R
		s1 e1 L1 T1
		s1 e2 L2 T2
		...
		sR eR LR TR
		s e��·�����յ�
*/ 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int K,N,R;
struct Road {
 	int d,L,t;
};
vector<vector<Road> > cityMap(110);//�ڽӱ�cityMap[i]�Ǵӵ�i��·�����ĳ��м���
int minLen = 1 << 30; //��ǰ�ҵ�������·���ĳ���
int totalLen; //�����ߵ�·���ĳ���
int totalCost ; //�����ߵ�·���Ļ���
int visited[110]; //�����Ƿ��Ѿ��߹��ı��
int minL[110][10100]; //minL[i][j]��ʾ��1��i��ģ�����Ϊj�����·�ĳ���
void Dfs(int s) //�� s��ʼ��N����
{
	if( s == N ) {
		minLen = min(minLen,totalLen);
		return ;
	}
	for( int i = 0 ;i < cityMap[s].size(); ++i ) {
		int d = cityMap[s][i].d; //s ��·����d
		if(! visited[d] ) {
 			int cost = totalCost + cityMap[s][i].t;
 		if( cost > K)
			continue;
 		if( totalLen + cityMap[s][i].L >= minLen ||totalLen + cityMap[s][i].L >= minL[d][cost])
			continue;
		totalLen += cityMap[s][i].L;
		totalCost += cityMap[s][i].t;
		minL[d][cost] = totalLen;
		visited[d] = 1;
		Dfs(d);
		visited[d] = 0;
		totalCost-= cityMap[s][i].t;
		totalLen-= cityMap[s][i].L; 
		}
	}
}
int main()
{
	cin >>K >> N >> R;
	for( int i = 0;i < R; ++ i) {
		int s;
		Road r;
		cin >> s >> r.d >> r.L >> r.t;
		if( s != r.d )
			cityMap[s].push_back(r);
	}
	for( int i = 0;i < 110; ++i )
		for( int j = 0; j < 10100; ++ j )
			minL[i][j] = 1 << 30;
		memset(visited,0,sizeof(visited));
		totalLen = 0;
		totalCost = 0;
		visited[1] = 1;
		minLen = 1 << 30;
		Dfs(1);
		if( minLen < (1 << 30))
			cout << minLen << endl;
		else
			cout << "-1" << endl;
}


