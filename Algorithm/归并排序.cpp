/*
����һ�����У�������������Ԫ�أ�������k�Σ��ڽ���֮�����ٵ�������Ƕ���
����3 1     ������������1�� 
	2 2 1 
	
���1 
*/
#include <bits/stdc++.h>
const int MAXN=100005;
typedef long long ll;
ll a[MAXN],b[MAXN],cnt;
void merge(ll l, ll mid, ll r){
	ll i=l,j=mid+1,t=0;
	while(i<mid&&j<=r){
		if(a[i]>a[j]){
			b[t++]=a[j++];
			cnt += mid-i+1;
		}
		else
			b[t++]=a[i++];
	}
	
	while(i<=mid)
		b[t++]=a[i++];
	while(j<=r)
		b[t++]=a[j++];
	for(i=0;i<t;i++)
		a[l+i]=b[i];
} 
void mergesort(ll l,ll r){
	if(l<r){
		ll mid=(l+r)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}
int main(){
	ll n,k;
	while(scanf("%lld%lld",&n,&k)!=EOF){
		cnt=0;
		for(ll i=0;i<n;i++)
			scanf("%lld",&a[i]);
		mergesort(0,n-1);
		if(cnt<=k)
			printf("0\n");
		else
			printf("%d\n",cnt-k);
	}
	return 0;
}
