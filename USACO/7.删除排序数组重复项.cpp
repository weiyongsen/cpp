#include<iostream>
#include<set>
using namespace std;
int main(){
	int n;
	int k;
	
	set<int>st;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>k;
		st.insert(k);
	}
//	for(set<int>::iterator i=st.begin();i!=st.end();i++)     //µü´úÆ÷±éÀú 
//		cout << *i << endl;
	cout<<"size:"<<st.size();
	return 0;
}
