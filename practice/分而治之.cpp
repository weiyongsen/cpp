#include <bits/stdc++.h>
 
int tong[1005];
int de[1005];
 
void init(){
    for(int i=1;i<1005;i++)
        tong[i]=i;
}
int getd(int v){
    if(tong[v]==v)
        return v;
    return tong[v]=getd(tong[v]);
}
int mer(int v,int u){
    int f1,f2;
    f1=getd(v);
    f2=getd(u);
    if(f1!=f2){
        tong[f2]=f1;
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
    for(int i=1;i<=m;i++){      
        scanf("%d%d",&a,&b);
        de[a]++;de[b]++;
        mer(a, b);
    }
    for(int i=1;i<=n;i++){
        if(tong[i]==i)
            cnt++;
    }
    if(cnt>1){  
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(de[i]%2==1){
            printf("0");
            return 0;
        }
    }
    printf("1");
 
}
