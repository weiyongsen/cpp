/*堆栈是一种经典的后进先出的线性结构，相关的操作主要有“入栈”（在堆栈顶插入一个元素）
和“出栈”（将栈顶元素返回并从堆栈中删除）。本题要求你实现另一个附加的操作：
“取中值”——即返回所有堆栈中元素键值的中值。
给定 N 个元素，如果 N 是偶数，则中值定义为第 N/2 小元；若是奇数，则为第 (N+1)/2 小元。
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
