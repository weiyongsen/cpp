#include<iostream> 
using namespace std;
int n,q,check[10000005]={0};
int prime[1000005],cnt=0,i,j;
int isPalindrome(int x) {//»ØÎÄÊý 
    int t=x;
    int sum=0;
    while(t){
        sum=sum*10+t%10;
        t/=10;
    }
    return sum==x;
}
int main() {
	check[1]=1;
    int a,b;
    cin>>a>>b;
    if(b>10000000)
        b=10000000;
    for(i=2;i<=b;i++){
        if(!check[i]) prime[cnt++]=i;
        for(j=0;j<cnt && i*prime[j]<=b;j++){
            check[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    if(a>b)
        return 0;
    if(a%2==0) a++; 
    for (int i=a;i<=b;i+=2) {
        if (check[i] == 0 && isPalindrome(i))
            cout<<i<<endl;
    }
    return 0;
}
