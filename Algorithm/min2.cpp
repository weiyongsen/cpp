//第二小的数 
#include <bits/stdc++.h>
using namespace std;

int main(){
	int cnt;
	cin >> cnt;
	while(cnt--){
		int n;
		int m;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> m;
			a[i]=m;
		}
		sort(a,a+n);
		int min2;
		min2=a[0];
		for(int i=0;i<n;i++){
			if(min2<a[i]){
				min2=a[i];
				cout << a[i] << endl;
				break;
			} 
		}
		if(min2==a[0]){
			cout << "NO" << endl;
		}
	}
	
	return 0;
} 
