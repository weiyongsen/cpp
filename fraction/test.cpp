#include "fraction.h"

int main(){
    // �������
    
    // while(1){
    //     cout << "�������������ʽ���� 1/2+3/4 �س��������� # �ŷ�����һ��Ŀ¼" << endl;
    //     char op='0';
    //     Fraction f1,f2;
    //     cin >> f1 ;
    //     if(f1.getDeno()==20192242){
    //         cout << "�˳�����" << endl;
    //         break;
    //     }
    //     cin >> op >> f2;
    //     cout << "��������:" << f1 << " " << f2 << endl;
    //     if(f1.getDeno()==0 || f2.getDeno()==0){
    //         cout << "warning:������ʽ�������" << endl;
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
    //         cout << "warning:������ʽ�������" << endl;
    //     }
    // }




    // // �������
    // int flag=0;
    // while(1){
    //     if(flag){
    //         cout << "�˳�����" << endl;
    //         break;
    //     }
    //     cout << "��ʼ�������,����#����" << endl;
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
    //             cout << "˳��" << endl;
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
    //             cout << "����" << endl;
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
    //             cout << "�������!" << endl;
    //             string s;
    //             getline(cin,s); //����������������֡�
    //             break;
    //         }
    //     }
    // }


    // ��������
    int n=-2;
    int d=4;
    Fraction f1(n,d);
    Fraction f2;
    // ����
    cout << "��������" << endl;
    cout << "����1:";
    cin >> f1;
    cout << "����2:";
    cin >> f2;

    // ���
    cout << "�������" << endl << "ԭ������:" << endl;
    cout << "1:\t" << f1 << endl;
    cout << "2:\t" << f2 << endl;
    cout << "��������" << endl;
    cout << "��:\t" << f1+f2 << endl;
    cout << "��:\t" << f1-f2 << endl;
    cout << "��:\t" << f1*f2 << endl;
    cout << "��:\t" << f1/f2 << endl;
    // �Ƚ�
    cout << "���ԱȽ�" << endl;
    cout << "f1==f2:\t" << (f1==f2) << endl;
    cout << "f1<f2:\t" << (f1<f2) << endl;
    cout << "f1>f2:\t" << (f1>f2) << endl;
    return 0;
}