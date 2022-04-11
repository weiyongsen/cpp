#include <bits/stdc++.h>
using namespace std;
class Fraction { 
	private:
        int numer; //���� 
        int deno; //��ĸ 
    public: 
        Fraction(); //�޲��캯�� 
        Fraction(int n, int d); //�����캯�� 
        Fraction(const Fraction& f); //�����캯�� 
        void setFraction(int n, int d); //���÷����ķ��Ӻͷ�ĸ 
        int getNumer(); //��ȡ�����ķ��� 
        int getDeno(); //��ȡ�����ķ�ĸ 
        void RdcFrc(); //��ǰ����Լ�� 
        friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //����+����� 
	    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //����-����� 
	    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //����*����� 
	    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //����/����� 
	    friend bool operator==(Fraction frac1, Fraction frac2); //����==����� 
	    friend bool operator>(const Fraction& frac1, const Fraction& frac2); //����>����� 
	    friend bool operator<(const Fraction& frac1, const Fraction& frac2); //����<����� 
	    friend  ostream& operator<<(ostream& out, const Fraction& frac); //����<<����� 
	    friend  istream& operator>>(istream& in, Fraction& frac); //����>>����� 
	    friend void sortFraction(Fraction f[],int num,int flag);//�Է����������� 
};
Fraction::Fraction(){
    numer=1;
    deno=1;
}
Fraction::Fraction(int n,int d){
    numer=n;
    deno=d;
}
Fraction::Fraction(const Fraction& f){
    numer=f.numer;
    deno=f.deno;
}
void Fraction::setFraction(int n,int d){ // ������ֵ
    numer=n;
    deno=d;
}
int Fraction::getNumer(){ //��ȡ�����ķ��� 
    return numer;
}
int Fraction::getDeno(){ //��ȡ�����ķ�ĸ 
    return deno;
} 
void Fraction::RdcFrc(){ //��ȡԼ��
    if(deno==0 || numer==0){
        return ;
    }
    else{    
        int temp=0;    // �����ĳ�����С
        if(numer>deno){
            temp=sqrt(numer);
        }else{
            temp=sqrt(deno);
        }
        for(int i=2;i<=temp+1;i++){     // ÿ�ζ���2��ʼ����
            if(numer%i==0 && deno%i==0){
                numer/=i;
                deno/=i;
                i=1;
            }
        }
        if(numer%deno==0){  // ��������Ǳ�����ϵ
            numer/=deno;
            deno=1;
        }else if(deno%numer==0){
            deno/=numer;
            numer=1;
        }
    }
}

ostream& operator<<(ostream& out, const Fraction& frac){ //����<<����� 
    int flag=0;
    if(frac.numer*frac.deno>=0){
        flag=1;
    }else{
        flag=0;
    }
    if(flag){
        out << frac.numer << "/" << frac.deno;
    }else{
        out << "-" << abs(frac.numer) << "/" << abs(frac.deno);
    }
    return out;
}
istream& operator>>(istream& in, Fraction& frac){ //����>>�����
    // string s;
    // in >> setw(3) >> s;
    // if(frac.deno==0){
    //     cout << "��ĸ������Ϊ0" << endl;
    // }
    // if(s[1]!='/' || !isdigit(s[0]) || !isdigit(s[2])){
    //     cout << "���벻�Ϲ淶" << endl;
    // }
    // frac.numer= s[0]-'0';
    // frac.deno= s[2]-'0';
    // if(s[0]=='#'){  // ���������д���ֹͣ������ʹ�÷�ĸΪ0������
    //     frac.numer=0;
    //     frac.deno=0;
    // }
    char c='0';     // ��ʼ�������ַ�
    int a=1;        // ����ķ���
    int b=1;            // ����ķ�ĸ
    // in >> a >> c >> b;
    if(in>>a){                      // �ֲ���ȡ�����ȶ�ȡ����
        frac.numer=a;
    }else{
        cin.clear();cin.get(c);     // ��ջ�������ȡ�����������ַ���
        if(c=='#'){
            frac.deno=20192242;     // �趨����ֵ
            return in;              // ��⵽����#���˳�
        }
        // cout << c;               // ������
        frac.deno=0;
        return in;
    }
    in >> c;                        // ��ȡ�ַ�
    if(c!='/'){
        cout << "�������" << endl;
        frac.numer=a;
        frac.deno=0;
    }
    if(in>>b){                      // ��ȡ��ĸ
        if(c=='/')
            frac.deno=b;;
    }else{
        cin.clear();cin.get();      // ��ջ�������ȡ�����ȡ�����ַ��������ַ����ո���У�
        frac.deno=0;
    }
    return in;
}
Fraction operator+(const Fraction& frac1, const Fraction& frac2){ //����+����� 
    Fraction ans;
    // ����ͨ�ּ���
    ans.deno=frac1.deno * frac2.deno;
    ans.numer= frac1.numer*frac2.deno + frac2.numer*frac1.deno;
    ans.RdcFrc();
    return ans;
    
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2){ //����-����� 
    Fraction ans;
    // ����ͨ�ּ���
    ans.deno=frac1.deno * frac2.deno;
    ans.numer= frac1.numer*frac2.deno - frac2.numer*frac1.deno;
    ans.RdcFrc();
    return ans;
}
Fraction operator*(const Fraction& frac1, const Fraction& frac2){ //����*����� 
    Fraction ans;
    ans.numer=frac1.numer*frac2.numer;
    ans.deno=frac1.deno*frac2.deno;
    ans.RdcFrc();
    return ans;
}
Fraction operator/(const Fraction& frac1, const Fraction& frac2){ //����/����� 
    Fraction ans;
    ans.numer=frac1.numer*frac2.deno;
    ans.deno=frac1.deno*frac2.numer;
    ans.RdcFrc();
    return ans;
}
bool operator==(Fraction frac1, Fraction frac2){ //����==����� 
    return (frac1-frac2).numer==0;
}
bool operator>(const Fraction& frac1, const Fraction& frac2){ //����>����� 
    return (float(frac1.numer) / frac1.deno) > (float(frac2.numer) /frac2.deno);
}
bool operator<(const Fraction& frac1, const Fraction& frac2){ //����<����� 
        return (float(frac1.numer) / frac1.deno) < (float(frac2.numer) / frac2.deno);
}

void sortFraction(Fraction f[],int num,int flag){//�Է�����������,ð������ʵ��,flag 1��2 �ֱ���� ��С���� �� �Ӵ�С ����
	int i,j;
    Fraction temp;
	for(i=0;i<num-1;i++)
	{
		for(j=1;j<num-i;j++)
		{
			if((f[j-1]>f[j]) & flag==1) // flag=1��Ǵ�С��������
			{
				temp=f[j-1];
				f[j-1]=f[j];
				f[j]=temp;
			}
			if((f[j-1]<f[j]) && flag==2) // flag=2��ǴӴ�С��
			{
				temp=f[j-1];
				f[j-1]=f[j];
				f[j]=temp;
			}
		}
	}
}
