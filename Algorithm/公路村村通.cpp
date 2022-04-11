/*
���д�����·��ͳ�����ݱ��У��г����п��ܽ���ɱ�׼��·����������·
�ĳɱ�����ʹÿ�����䶼�й�·��ͨ����Ҫ����ͳɱ���

�����ʽ:
�������ݰ���������Ŀ������N����1000���ͺ�ѡ��·��ĿM����3N����
����M�ж�ӦM����·��ÿ�и���3����������
�ֱ��Ǹ�����·ֱ����ͨ����������ı���Լ��õ�·�Ľ���Ԥ��ɱ���
Ϊ������������1��N��š�

�����ʽ:
������ͨ��Ҫ����ͳɱ�������������ݲ����Ա�֤��ͨ�������-1��
��ʾ��Ҫ������๫·��

��������:
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
�������:
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
    //·��ѹ��
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
            pre[fau] = fav;//����
            ans += road[i].w;
            num_edge++;
            if(num_edge == n-1) break;//���
        }
    }
    if(num_edge<n-1) ans = -1;//δ���
}

int main(){
    scanf("%d%d",&n,&m);
    //��ʼ��
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



