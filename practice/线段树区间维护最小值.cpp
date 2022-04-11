/*
思路：
把（变为+1，）变为-1；
假设在i点发生变化：

（1）总和一定发生变化，所以判断sum（1……n） == 0 ？

（2）对于区间和，只有起点在i前面终点在i后面的区间的值发生了变化，
 所以只考虑发生变化的值；

利用线段树，每次经过修改区间，判断被修改的区间发生的变化；
如果是+2，结果肯定是个正数，
如果是-2，就要判断前面有没有（括号可以匹配，
如果没有可以匹配的可能出现了负数，
所以可以通过判断最小值来解决。
*/ 

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char ss[N];
int tree[N] = {0},mi[N] = {0};
void up(int rt,int l,int r,int pos,int x)
{
    if(l == r)
    {
        tree[rt] = x;
        return ;
    }
    int mid = (l+r)>>1;
    if(pos <= mid) up(rt<<1,l,mid,pos,x);
    else up(rt<<1|1,mid+1,r,pos,x);
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];

    //发生两种变化
    //一、+2，然后总和可能会超过零，用总和判断就好了
    //二、-2，判断前面是否有+1可以抵消现在的值，如果抵消不了最小值就小于0
    mi[rt] = min(mi[rt<<1],tree[rt<<1] + mi[rt<<1|1]);
}
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",ss+1);
    for(int i=1;i<=n;i++)
    {
        if(ss[i] == ')') up(1,1,n,i,-1);
        else up(1,1,n,i,1);
    }
    while(m--)
    {
        int x;scanf("%d",&x);
        if(ss[x] == ')')
        {
            ss[x] = '(';
            up(1,1,n,x,1);
        }
        else{
            ss[x] = ')';
            up(1,1,n,x,-1);
        }
 
        if(tree[1] == 0 && mi[1] >= 0)
        {
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
