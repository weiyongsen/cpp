#include "fraction.h"

int main(){
    // 计算测试
    
    // while(1){
    //     cout << "请输入分数计算式（如 1/2+3/4 回车），输入 # 号返回上一级目录" << endl;
    //     char op='0';
    //     Fraction f1,f2;
    //     cin >> f1 ;
    //     if(f1.getDeno()==20192242){
    //         cout << "退出计算" << endl;
    //         break;
    //     }
    //     cin >> op >> f2;
    //     cout << "检查操作数:" << f1 << " " << f2 << endl;
    //     if(f1.getDeno()==0 || f2.getDeno()==0){
    //         cout << "warning:分数算式输入错误！" << endl;
    //         continue;
    //     }
    //     int func=0;
    //     switch(op){
    //         case '+':
    //                 cout << "=" << f1+f2 << endl;
    //                 func=1;
    //                 break;
    //         case '-':
    //                 cout << "=" << f1+f2 << endl;
    //                 func=1;
    //                 break;
    //         case '*':
    //                 cout << "=" << f1+f2 << endl;
    //                 func=1;
    //                 break;
    //         case '/':
    //                 cout << "=" << f1+f2 << endl;
    //                 func=1;
    //                 break;                                                                                                                       
    //     }
    //     if(!func ){
    //         cout << "warning:分数算式输入错误！" << endl;
    //     }
    // }




    // // 排序测试
    // int flag=0;
    // while(1){
    //     if(flag){
    //         cout << "退出测试" << endl;
    //         break;
    //     }
    //     cout << "开始排序测试,输入#结束" << endl;
    //     vector<Fraction> a;
    //     char c;
    //     Fraction f;
    //     while(1){
    //         cin >> f;
    //         if(f.getDeno()==20192242){
    //             flag=1;
    //             break;
    //         }
    //         a.push_back(f);
    //         cin >> c;
    //         if(c==',')
    //             continue;
    //         else if(c=='<'){
    //             cout << "顺排" << endl;
    //             int len=a.size();
    //             Fraction b[len];
    //             for(int i=0;i<len;i++){
    //                 b[i]=a[i];
    //             }
    //             sortFraction(b,len,1);
    //             for(int i=0;i<len;i++){
    //                 cout << b[i] << " ";
    //             }
    //             cout << endl;
    //             break;
    //         }else if(c=='>'){
    //             cout << "倒排" << endl;
    //             int len=a.size();
    //             Fraction b[len];
    //             for(int i=0;i<len;i++){
    //                 b[i]=a[i];
    //             }
    //             sortFraction(b,len,2);
    //             for(int i=0;i<len;i++){
    //                 cout << b[i] << " ";
    //             }
    //             cout << endl;
    //             break;
    //         }else{
    //             cout << "输入出错!" << endl;
    //             string s;
    //             getline(cin,s); //处理掉后续错误数字。
    //             break;
    //         }
    //     }
    // }


    // 基础测试
    int n=-2;
    int d=4;
    Fraction f1(n,d);
    Fraction f2;
    // 输入
    cout << "测试输入" << endl;
    cout << "输入1:";
    cin >> f1;
    cout << "输入2:";
    cin >> f2;

    // 输出
    cout << "测试输出" << endl << "原操作数:" << endl;
    cout << "1:\t" << f1 << endl;
    cout << "2:\t" << f2 << endl;
    cout << "测试运算" << endl;
    cout << "和:\t" << f1+f2 << endl;
    cout << "差:\t" << f1-f2 << endl;
    cout << "积:\t" << f1*f2 << endl;
    cout << "商:\t" << f1/f2 << endl;
    // 比较
    cout << "测试比较" << endl;
    cout << "f1==f2:\t" << (f1==f2) << endl;
    cout << "f1<f2:\t" << (f1<f2) << endl;
    cout << "f1>f2:\t" << (f1>f2) << endl;
    return 0;
}