#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int t[n];
    for(int i=0;i<n;i++){
        cin >> t[i];
    }
    sort(t,t+n);
    int min=0,max=0;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        a[i]=t[i];
        b[i]=t[i];
    }
    for(int i=0;i<n-1;i++){
        b[i+1]=b[i]+b[i+1];
        min+=(b[i+1]-1);
		sort(b+i+1,b+n); 
    }
    for(int i=n-1;i>0;i--){
        a[i-1]=a[i-1]+a[i];
        max+=(a[i-1]-1);
        sort(a,a+i);
    }
    cout << max << " " << min <<endl;
    return 0;
}
