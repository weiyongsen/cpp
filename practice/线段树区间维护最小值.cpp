/*
˼·��
�ѣ���Ϊ+1������Ϊ-1��
������i�㷢���仯��

��1���ܺ�һ�������仯�������ж�sum��1����n�� == 0 ��

��2����������ͣ�ֻ�������iǰ���յ���i����������ֵ�����˱仯��
 ����ֻ���Ƿ����仯��ֵ��

�����߶�����ÿ�ξ����޸����䣬�жϱ��޸ĵ����䷢���ı仯��
�����+2������϶��Ǹ�������
�����-2����Ҫ�ж�ǰ����û�У����ſ���ƥ�䣬
���û�п���ƥ��Ŀ��ܳ����˸�����
���Կ���ͨ���ж���Сֵ�������
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

    //�������ֱ仯
    //һ��+2��Ȼ���ܺͿ��ܻᳬ���㣬���ܺ��жϾͺ���
    //����-2���ж�ǰ���Ƿ���+1���Ե������ڵ�ֵ���������������Сֵ��С��0
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
