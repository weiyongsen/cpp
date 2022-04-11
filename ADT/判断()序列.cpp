//返回-1说明序列匹配 ，其他值为第一个右括号错误的地方 
#include <bits/stdc++.h>
using namespace std;
int balance(string str){
	stack<char> S;
	int pos=0;
	while(pos<str.length()){
		if(str[pos]=='('){
			S.push('(');
			pos=pos+1;
		}
			
		else if(str[pos]==')'){
			if(S.empty())
				return pos+1;
			else
				S.pop();
			pos=pos+1;
		}
	}
	if(S.empty())
		return -1;
	else
		return 0; 
}
int main(){
	string s;
	cin >> s;
	cout << balance(s);
	
	return 0;
}
