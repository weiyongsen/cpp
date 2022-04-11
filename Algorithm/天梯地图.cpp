/*
���룺V1 V2 one-way length time 
����V1��V2�ǵ�·�������˵�ı�ţ���0��N-1��������õ�·�Ǵ�V1��V2�ĵ����ߣ���one-wayΪ1������Ϊ0��
length�ǵ�·�ĳ��ȣ�time��ͨ����·����Ҫ��ʱ�䡣������һ�������յ�ı�š�

�����
Time = T: ��� => �ڵ�1 => ... => �յ�
Distance = D: ��� => �ڵ�1 => ... => �յ�

�������������һ��·�ߣ������һ�оͿ��ԣ� 
Time = T; Distance = D: ��� => �ڵ�1 => ... => �յ� 

������
���룺 
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
5 4 0 2 3
5 9 1 1 4
0 6 0 1 1
7 3 1 1 2
8 3 1 1 2
2 5 0 2 2
2 1 1 1 1
1 5 0 1 3
1 4 0 1 1
9 7 1 1 3
3 1 0 2 5
6 3 1 2 1
5 3

�����
Time = 6: 5 => 4 => 8 => 3
Distance = 3: 5 => 1 => 3 
*/

#include <bits/stdc++.h>
using namespace std;
const int INF=1<<25; 
int n,m,s,d;				//�ص��������·��������ʼ�㣬�յ� 
int a[1001][1001]; 
int dis[1001][1001],tim[1001][1001];
int vis[1001]= {0},cnt[1001];		//�ڵ��Ƿ���ʣ��ѷ��ʽڵ���Ŀ 
int pr[1001],po[1001];		//��¼������·��
void lenfirst()
{
    vis[s]=1;
    int t=n-1;
    while(t--){
        int min=INF,f=-1;
        for(int i=0;i<n;i++){		//Ѱ�Ҿ����������ĵ� 
            if(!vis[i]&&dis[s][i]<min){
                min=dis[s][i];
                f=i;
            }
        }
        vis[f]=1;					
        for(int i=0;i<n;i++){
            if(!vis[i]&&dis[s][i]>dis[s][f]+dis[f][i]){//�������·��
                dis[s][i]=dis[s][f]+dis[f][i];
                pr[i]=f;
                cnt[i]=cnt[f]+1;
            }
            if(!vis[i]&&dis[s][i]==dis[s][f]+dis[f][i]){
                if(cnt[i]>cnt[f]+1){					//�����������
                    cnt[i]=cnt[f]+1;
                    pr[i]=f;
                }
            }
        }
    }
}
void timefirst(){
    vis[s]=1;
    int t=n-1;
    while(t--){
        int min=INF,f=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]&&tim[s][i]<min){
                min=tim[s][i];
                f=i;
            }
        }
        vis[f]=1;
        for(int i=0;i<n;i++){
            if(!vis[i]&&tim[s][i]>tim[s][f]+tim[f][i]){//�������ʱ��
                tim[s][i]=tim[s][f]+tim[f][i];
                po[i]=f;
                a[s][i]=a[s][f]+a[f][i];
            }
            if(!vis[i]&&tim[s][i]==tim[s][f]+tim[f][i]&&a[s][i]>a[s][f]+a[f][i]){//ʱ����ͬʱ·�����
                po[i]=f;
                a[s][i]=a[s][f]+a[f][i];
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){//��ʼ��
        cnt[i]=1;
        for(int j=0;j<n;j++){
            a[i][j]=dis[i][j]=INF;
            tim[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int q,w,e,r,t;
        cin>>q>>w>>e>>r>>t;
        if(e){
            dis[q][w]=a[q][w]=r;
            tim[q][w]=t;
        }
        else {
            a[q][w]=a[w][q]=dis[q][w]=dis[w][q]=r;
            tim[q][w]=tim[w][q]=t;
        }
    }
    cin>>s>>d;
    timefirst();
    memset(vis,0,sizeof(vis));//vis�ظ�ʹ��
    lenfirst();
    stack<int>s1,s2;//����ջ���洢
    s1.push(d);
    s2.push(d);
    int t1=d,t2=d;
    while(pr[t1]){
        s1.push(pr[t1]);
        t1=pr[t1];
    }
    while(po[t2]){
        s2.push(po[t2]);
        t2=po[t2];
    }
    if(s1==s2){
        cout<<"Time = "<<tim[s][d]<<"; Distance = "<<dis[s][d]<<": "<<s;
        while(!s1.empty()){
            cout<<" => "<<s1.top();
            s1.pop();
        }
        cout<<endl;
    }
    else {
        cout<<"Time = "<<tim[s][d]<<": "<<s;
        while(!s2.empty()){
            cout<<" => "<<s2.top();
            s2.pop();
        }
        cout<<endl;
        cout<<"Distance = "<<dis[s][d]<<": "<<s;
         while(!s1.empty()){
            cout<<" => "<<s1.top();
            s1.pop();
        }
        cout<<endl;
    }
}
 
