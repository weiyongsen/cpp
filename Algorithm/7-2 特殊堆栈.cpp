/*��ջ��һ�־���ĺ���ȳ������Խṹ����صĲ�����Ҫ�С���ջ�����ڶ�ջ������һ��Ԫ�أ�
�͡���ջ������ջ��Ԫ�ط��ز��Ӷ�ջ��ɾ����������Ҫ����ʵ����һ�����ӵĲ�����
��ȡ��ֵ���������������ж�ջ��Ԫ�ؼ�ֵ����ֵ��
���� N ��Ԫ�أ���� N ��ż��������ֵ����Ϊ�� N/2 СԪ��������������Ϊ�� (N+1)/2 СԪ��
*/ 
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>v;
    stack<int> s;
    int n,t;
    cin>>n;
    string str;
    vector<int>::iterator it;
    while(n--) {
        cin>>str;
        if(str=="Push") {
            cin>>t;
            s.push(t);
            vector<int>::iterator tt = lower_bound(v.begin(),v.end(),t);
            v.insert(tt,t);
        } else if(str=="Pop") {
            if(s.empty())
                cout<<"Invalid"<<endl;
            else {
                cout<<s.top()<<endl;
                vector<int>::iterator i = lower_bound(v.begin(),v.end(),s.top());
                v.erase(i);
                s.pop();
            }
        } else {
            if(s.empty())
                cout<<"Invalid"<<endl;
            else {
                cout<<v[(v.size()+1)/2-1]<<endl;
            }
        }
    }
    return 0;
}
