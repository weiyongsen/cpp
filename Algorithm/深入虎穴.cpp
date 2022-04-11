//第二小的数 
//著名的王牌间谍 007 需要执行一次任务，
//获取敌方的机密情报。已知情报藏在一个地下迷宫里，迷宫只有一个入口，
//里面有很多条通路，每条路通向一扇门。
//每一扇门背后或者是一个房间，或者又有很多条路，
//同样是每条路通向一扇门…… 
//他的手里有一张表格，是其他间谍帮他收集到的情报，
//他们记下了每扇门的编号，
//以及这扇门背后的每一条通路所到达的门的编号。
//007 发现不存在两条路通向同一扇门。

//内线告诉他，情报就藏在迷宫的最深处。但是这个迷宫太大了，
//他需要你的帮助 —— 请编程帮他找出距离入口最远的那扇门。
//输入：
//13
//3 2 3 4
//2 5 6
//1 7
//1 8
//1 9
//0
//2 11 10
//1 13
//0
//0
//1 12
//0
//0
//输出： 
//12
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

int main(){
    int n,root,door;
    scanf("%d",&n);
    vector<vector<int> > v(n+2);
    vector<int>a(n+2,0);
    for(int i=1;i<=n;i++){
        int k,t;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&t);
            v[i].push_back(t);
            a[t]=1;
        }
    }
    for(int i=1;i<=n;i++){ //寻找根结点
        if(a[i]==0){
            root=i;
            break;
        }
    }
    queue<int>q;
    q.push(root);
    door=root;
    while(!q.empty()){  //BFS
        int t=q.front();
        q.pop();
        door=t;
        for(int i=0;i<v[t].size();i++){
            q.push(v[t][i]);
        }
    }
    printf("%d",door);
    return 0;
}


