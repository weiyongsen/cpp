//�ڶ�С���� 
//���������Ƽ�� 007 ��Ҫִ��һ������
//��ȡ�з��Ļ����鱨����֪�鱨����һ�������Թ���Թ�ֻ��һ����ڣ�
//�����кܶ���ͨ·��ÿ��·ͨ��һ���š�
//ÿһ���ű��������һ�����䣬�������кܶ���·��
//ͬ����ÿ��·ͨ��һ���š��� 
//����������һ�ű����������������ռ������鱨��
//���Ǽ�����ÿ���ŵı�ţ�
//�Լ������ű����ÿһ��ͨ·��������ŵı�š�
//007 ���ֲ���������·ͨ��ͬһ���š�

//���߸��������鱨�Ͳ����Թ����������������Թ�̫���ˣ�
//����Ҫ��İ��� ���� ���̰����ҳ����������Զ�������š�
//���룺
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
//����� 
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
    for(int i=1;i<=n;i++){ //Ѱ�Ҹ����
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


