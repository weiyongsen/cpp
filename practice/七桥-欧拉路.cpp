#include <stdio.h>
 
int f[1003];
int indegree[1003];
 
void init(){
    for(int i=1;i<1003;i++)
        f[i]=i;
}
int getdad(int v){
    if(f[v]==v)
        return v;
    return f[v]=getdad(f[v]);
}
int mer(int v,int u){
    int f1,f2;
    f1=getdad(v);
    f2=getdad(u);
    if(f1!=f2){
        f[f2]=f1;
        return 1;
    }
    return 0;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init();
    int a,b;
    int cnt=0;
    for(int i=1;i<=m;i++){       //ŷ����·����Ϊż������ͨ�����鼯+�����жϼ���
        scanf("%d%d",&a,&b);
        indegree[a]++;indegree[b]++;
        mer(a, b);
    }
    for(int i=1;i<=n;i++){
        if(f[i]==i)
            cnt++;
    }
    if(cnt>1){  //��ͨ�Ļ�ֻ��һ����
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]%2==1){
            printf("0");
            return 0;
        }
    }
    printf("1");
 
}
