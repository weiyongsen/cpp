#include "Fraction.h"

int main(){
    int exit=0; //����˳�������
    while(1){			
            if(exit){
                cout << "~��������,��л���Ա������֧�֡�" << endl;
                break;
            }	
            cout << "��ѡ����" << endl;
            cout << "1.��������" << endl; 
            cout << "2.��������" << endl;
            cout << "����#�˳�����,��������������Ҫʹ�õĹ��ܡ���:\n";
            int n=0; // ���ѡ��Ĺ���
            cin >> n;
            int flag=0; // ����������Ҫ����ʱ�����Ϊ1
            switch(n){
                case 1:	
                        while(1){
                            cout << "�������������ʽ���� 1/2+3/4 �س��������� # �ŷ�����һ��Ŀ¼" << endl;
                            char op='0';
                            Fraction f1,f2;
                            cin >> f1 ;
                            if(f1.getDeno()==20192242){
                                cout << "~�˳����㹦��" << endl;
                                string s;
                                getline(cin,s); // �Ը��к���������д���ʹ�䲻Ӱ���´�����
                                break;
                            }
                            cin >> op >> f2;
                            // cout << "��������:" << f1 << " " << f2 << endl;
                            if(f1.getDeno()==0 || f2.getDeno()==0){
                                cout << "warning:����������Ϸ����淶��" << endl;
                                string s;
                                getline(cin,s); // �Ը��к���������д���ʹ�䲻Ӱ���´�����
                                continue;
                            }
                            int func=0;     // ��op�Ƿ����ڼӼ��˳��������
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
                            if(!func ){     // ���funcֵδ�ı䣬˵��op���벻�ϸ�
                                cout << "warning:������������������" << endl;
                            }
                        }
                        break;
                case 2:	
                        flag=0;
                        while(1){
                            if(flag){
                                cout << "~�˳�������" << endl;
                                break;
                            }
                            cout << "������һ��������ö��Ÿ�����������С���������÷���<��β���ɴ�С�����÷���>��β����1/2,1/4,3/5<�س���������#�ż�������һ��Ŀ¼��" << endl;
                            vector<Fraction> a;     // ʹ��vector���Զ�̬�������ķ��������ҿ��Ժܿ�صõ����ȡ�
                            char op;                // ��¼����ķָ����
                            Fraction f;             
                            while(1){
                                cin >> f;
                                if(f.getDeno()==20192242){
                                    flag=1;     // ˵��������#������
                                    break;
                                }
                                if(f.getDeno()==0){
                                    cout << "warning:�������!�������������" << endl;
                                    string s;
                                    getline(cin,s); // ��һ�еĺ�������Ӧ�ñ������
                                    break;
                                }
                                a.push_back(f);
                                cin >> op;
                                if(op==',')
                                    continue;
                                else if(op=='<'){
                                    cout << "��С��������:";
                                    int len=a.size();           // �õ�fraction��������������
                                    Fraction b[len];            // ��vectorת��Ϊfractor���飬Ȼ��Ϳ��Ե����Լ�������ʵ�ֵ����򷽷���
                                    for(int i=0;i<len;i++){
                                        b[i]=a[i];
                                    }
                                    sortFraction(b,len,1);      // ������������flag����Ϊ1��˳������
                                    for(int i=0;i<len;i++){     // ������
                                        cout << b[i] << " ";
                                    }
                                    cout << endl;
                                    break;
                                }else if(op=='>'){
                                    cout << "�Ӵ�С����:";
                                    int len=a.size();
                                    Fraction b[len];
                                    for(int i=0;i<len;i++){
                                        b[i]=a[i];
                                    }
                                    sortFraction(b,len,2);      // ������������flag����Ϊ2����������
                                    for(int i=0;i<len;i++){
                                        cout << b[i] << " ";
                                    }
                                    cout << endl;
                                    break;
                                }else{
                                    cout << "warning:�������!" << endl;
                                    string s;
                                    getline(cin,s); // ��һ�еĺ�������Ӧ�ñ������
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