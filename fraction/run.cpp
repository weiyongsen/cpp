#include "Fraction.h"

int main(){
    int exit=0; //标记退出计算器
    while(1){			
            if(exit){
                cout << "~结束运行,感谢您对本程序的支持。" << endl;
                break;
            }	
            cout << "请选择功能" << endl;
            cout << "1.分数计算" << endl; 
            cout << "2.分数排序" << endl;
            cout << "输入#退出程序,现在请输入您需要使用的功能——:\n";
            int n=0; // 标记选择的功能
            cin >> n;
            int flag=0; // 在排序功能需要跳出时，标记为1
            switch(n){
                case 1:	
                        while(1){
                            cout << "请输入分数计算式（如 1/2+3/4 回车），输入 # 号返回上一级目录" << endl;
                            char op='0';
                            Fraction f1,f2;
                            cin >> f1 ;
                            if(f1.getDeno()==20192242){
                                cout << "~退出计算功能" << endl;
                                string s;
                                getline(cin,s); // 对该行后续输入进行处理，使其不影响下次输入
                                break;
                            }
                            cin >> op >> f2;
                            // cout << "检查操作数:" << f1 << " " << f2 << endl;
                            if(f1.getDeno()==0 || f2.getDeno()==0){
                                cout << "warning:输入分数不合分数规范！" << endl;
                                string s;
                                getline(cin,s); // 对该行后续输入进行处理，使其不影响下次输入
                                continue;
                            }
                            int func=0;     // 看op是否属于加减乘除四种情况
                            switch(op){
                                case '+':
                                        cout << "=" << f1+f2 << endl;
                                        func=1;
                                        break;
                                case '-':
                                        cout << "=" << f1-f2 << endl;
                                        func=1;
                                        break;
                                case '*':
                                        cout << "=" << f1*f2 << endl;
                                        func=1;
                                        break;
                                case '/':
                                        cout << "=" << f1/f2 << endl;
                                        func=1;
                                        break;                                                                                                                       
                            }
                            if(!func ){     // 如果func值未改变，说明op输入不合格
                                cout << "warning:分数计算符号输入错误！" << endl;
                            }
                        }
                        break;
                case 2:	
                        flag=0;
                        while(1){
                            if(flag){
                                cout << "~退出排序功能" << endl;
                                break;
                            }
                            cout << "请输入一组分数，用逗号隔开，如需由小到大排序用符号<结尾，由大到小排序用符号>结尾（如1/2,1/4,3/5<回车），输入#号键返回上一层目录：" << endl;
                            vector<Fraction> a;     // 使用vector可以动态添加输入的分数，并且可以很快地得到长度。
                            char op;                // 记录输入的分割符号
                            Fraction f;             
                            while(1){
                                cin >> f;
                                if(f.getDeno()==20192242){
                                    flag=1;     // 说明输入了#，跳出
                                    break;
                                }
                                if(f.getDeno()==0){
                                    cout << "warning:输入出错!本次输入结束。" << endl;
                                    string s;
                                    getline(cin,s); // 这一行的后续数字应该被处理掉
                                    break;
                                }
                                a.push_back(f);
                                cin >> op;
                                if(op==',')
                                    continue;
                                else if(op=='<'){
                                    cout << "从小到大排序:";
                                    int len=a.size();           // 得到fraction个数，建立数组
                                    Fraction b[len];            // 将vector转化为fractor数组，然后就可以调用自己在类中实现的排序方法。
                                    for(int i=0;i<len;i++){
                                        b[i]=a[i];
                                    }
                                    sortFraction(b,len,1);      // 调用排序函数，flag设置为1，顺序排序
                                    for(int i=0;i<len;i++){     // 输出结果
                                        cout << b[i] << " ";
                                    }
                                    cout << endl;
                                    break;
                                }else if(op=='>'){
                                    cout << "从大到小倒排:";
                                    int len=a.size();
                                    Fraction b[len];
                                    for(int i=0;i<len;i++){
                                        b[i]=a[i];
                                    }
                                    sortFraction(b,len,2);      // 调用排序函数，flag设置为2，倒序排序
                                    for(int i=0;i<len;i++){
                                        cout << b[i] << " ";
                                    }
                                    cout << endl;
                                    break;
                                }else{
                                    cout << "warning:输入出错!" << endl;
                                    string s;
                                    getline(cin,s); // 这一行的后续数字应该被处理掉
                                    break;
                                }
                            }
                        }
                        break;
                default:
                        exit=1;
                        break;
            }
        }


    return 0;
}