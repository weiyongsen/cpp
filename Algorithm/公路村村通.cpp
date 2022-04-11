/*
现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路
的成本，求使每个村落都有公路连通所需要的最低成本。

输入格式:
输入数据包括城镇数目正整数N（≤1000）和候选道路数目M（≤3N）；
随后的M行对应M条道路，每行给出3个正整数，
分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。
为简单起见，城镇从1到N编号。

输出格式:
输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出-1，
表示需要建设更多公路。

输入样例:
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3
输出样例:
12
*/ 


#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int pre[1005];
int n, m;

struct Node{
    int u, v, w;
    bool operator <= (const Node x){
        return w <= x.w;
    }
    bool operator >= (const Node x){
        return w >= x.w;
    }
}road[3*maxn];

void quicksort(int left, int right){
    int i, j;
    Node t, tmp;
    if(left>right) return ;
    tmp = road[left];
    i = left, j = right;
    while(i!=j){
        while(road[j]>=tmp && i<j) j--;
        while(road[i]<=tmp && i<j) i++;

        if(i<j){
            t = road[i];
            road[i] = road[j];
            road[j] = t;
        }
    }
    road[left] = road[i];
    road[i] = tmp;
    quicksort(left, i-1);
    quicksort(i+1, right);
}

int unionsearch(int root){
    int son, tmp;
    son = root;
    while(root!=pre[root])
        root = pre[root];
    //路径压缩
    while(son!=pre[son]){
        tmp = pre[son];
        pre[son] = root;
        son = tmp;
    }
    return root;
}

void Kruscal(int &ans){
    ans = 0;
    int num_edge = 0;
    quicksort(0,m-1);
    for(int i = 0; i < m; i++){
        int fau = unionsearch(road[i].u);
        int fav = unionsearch(road[i].v);
        if(fau!=fav){
            pre[fau] = fav;//建边
            ans += road[i].w;
            num_edge++;
            if(num_edge == n-1) break;//完成
        }
    }
    if(num_edge<n-1) ans = -1;//未完成
}

int main(){
    scanf("%d%d",&n,&m);
    //初始化
    for(int i = 1; i <= n; i++)
        pre[i] = i;

    int u, v, w, ans = 0;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d",&road[i].u,&road[i].v, &road[i].w);
    }

    Kruscal(ans);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}



