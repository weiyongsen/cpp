#include<bits/stdc++.h>        //ת�������  ��׺����׺2+3*(7-4)+8/4 --->  2 3 7 4 - * + 8 4 / +
using namespace std;
int main(){
   string a;
   map<char,int>p;//������¼���ŵ����ȼ�
   p['(']=p[')']=2;
   p['*']=p['/']=1;
   cin>>a;
   stack<char>s;
   int flag=0;
   for(int i=0;i<a.size();i++){
   if((i<1||a[i-1]=='(')&&(a[i]=='+'||a[i]=='-')||(a[i]=='.')||(a[i]>='0'&&a[i]<='9')){//��1�ε�ʱ������ֱ������������ź���ķ��ţ�����Ҳ��ֱ�������
	if(flag)
	cout<<" ";
	flag=1;
        if(a[i]!='+')cout<<a[i];
        while(a[i+1]=='.'||a[i+1]>='0'&&a[i+1]<='9'){//������С������λ�������
		i++;
		cout<<a[i];
        }
   }
else{
   if(a[i]==')'){//�����ţ���ջ����ķ����ó���ֱ��ջ�ջ�����������
	while(s.size()&&s.top()!='('){
		cout<<" "<<s.top();
		s.pop();
	}
	s.pop();
   }
   else if(s.size()==0||p[a[i]]>p[s.top()]){
	s.push(a[i]);//ջ�գ����ߵ�ǰ����������ȼ�����ջ�������ȼ�ʱ��ֱ����ջ
   }
   else {
	while(s.size()&&s.top()!='('){
		cout<<" "<<s.top();//���������ֱ�ӳ�ջ����ջ
		s.pop();
	}
	s.push(a[i]);
   }
}
   }
   while(s.size()){//����ȡ��ʣ����ַ�
	cout<<" "<<s.top();
	s.pop();
   }
   return 0;
}
