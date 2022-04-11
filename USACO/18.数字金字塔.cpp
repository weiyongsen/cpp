#include<stdio.h>
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
int main()
{
    int n;
    int a[1002][1002];
    int dp[1002][1002];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int j=1;j<=n;j++) dp[n][j]=a[n][j];
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    printf("%d",dp[1][1]);
    return 0;
}
