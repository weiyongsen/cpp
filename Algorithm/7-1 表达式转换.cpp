#include<bits/stdc++.h>        //转换运算符  中缀到后缀2+3*(7-4)+8/4 --->  2 3 7 4 - * + 8 4 / +
using namespace std;
int main(){
   string a;
   map<char,int>p;//用来记录符号的优先级
   p['(']=p[')']=2;
   p['*']=p['/']=1;
   cin>>a;
   stack<char>s;
   int flag=0;
   for(int i=0;i<a.size();i++){
   if((i<1||a[i-1]=='(')&&(a[i]=='+'||a[i]=='-')||(a[i]=='.')||(a[i]>='0'&&a[i]<='9')){//第1次的时候数字直接输出，左括号后面的符号，数字也可直接输出。
	if(flag)
	cout<<" ";
	flag=1;
        if(a[i]!='+')cout<<a[i];
        while(a[i+1]=='.'||a[i+1]>='0'&&a[i+1]<='9'){//可能是小数，多位数的情况
		i++;
		cout<<a[i];
        }
   }
else{
   if(a[i]==')'){//右括号，把栈里面的符号拿出来直到栈空或遇到左括号
	while(s.size()&&s.top()!='('){
		cout<<" "<<s.top();
		s.pop();
	}
	s.pop();
   }
   else if(s.size()==0||p[a[i]]>p[s.top()]){
	s.push(a[i]);//栈空，或者当前的运算符优先级高于栈顶的优先级时，直接入栈
   }
   else {
	while(s.size()&&s.top()!='('){
		cout<<" "<<s.top();//其他情况，直接出栈再入栈
		s.pop();
	}
	s.push(a[i]);
   }
}
   }
   while(s.size()){//继续取出剩余的字符
	cout<<" "<<s.top();
	s.pop();
   }
   return 0;
}
