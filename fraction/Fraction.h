#include <bits/stdc++.h>
using namespace std;
class Fraction { 
	private:
        int numer; //分子 
        int deno; //分母 
    public: 
        Fraction(); //无参造函数 
        Fraction(int n, int d); //带参造函数 
        Fraction(const Fraction& f); //复制造函数 
        void setFraction(int n, int d); //设置分数的分子和分母 
        int getNumer(); //获取分数的分子 
        int getDeno(); //获取分数的分母 
        void RdcFrc(); //当前分数约分 
        friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //重载+运算符 
	    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //重载-运算符 
	    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //重载*运算符 
	    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //重载/运算符 
	    friend bool operator==(Fraction frac1, Fraction frac2); //重载==运算符 
	    friend bool operator>(const Fraction& frac1, const Fraction& frac2); //重载>运算符 
	    friend bool operator<(const Fraction& frac1, const Fraction& frac2); //重载<运算符 
	    friend  ostream& operator<<(ostream& out, const Fraction& frac); //重载<<运算符 
	    friend  istream& operator>>(istream& in, Fraction& frac); //重载>>运算符 
	    friend void sortFraction(Fraction f[],int num,int flag);//对分数数组排序 
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
void Fraction::setFraction(int n,int d){ // 设置数值
    numer=n;
    deno=d;
}
int Fraction::getNumer(){ //获取分数的分子 
    return numer;
}
int Fraction::getDeno(){ //获取分数的分母 
    return deno;
} 
void Fraction::RdcFrc(){ //获取约分
    if(deno==0 || numer==0){
        return ;
    }
    else{    
        int temp=0;    // 遍历的除数大小
        if(numer>deno){
            temp=sqrt(numer);
        }else{
            temp=sqrt(deno);
        }
        for(int i=2;i<=temp+1;i++){     // 每次都从2开始遍历
            if(numer%i==0 && deno%i==0){
                numer/=i;
                deno/=i;
                i=1;
            }
        }
        if(numer%deno==0){  // 如果两者是倍数关系
            numer/=deno;
            deno=1;
        }else if(deno%numer==0){
            deno/=numer;
            numer=1;
        }
    }
}

ostream& operator<<(ostream& out, const Fraction& frac){ //重载<<运算符 
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
istream& operator>>(istream& in, Fraction& frac){ //重载>>运算符
    // string s;
    // in >> setw(3) >> s;
    // if(frac.deno==0){
    //     cout << "分母不可以为0" << endl;
    // }
    // if(s[1]!='/' || !isdigit(s[0]) || !isdigit(s[2])){
    //     cout << "输入不合规范" << endl;
    // }
    // frac.numer= s[0]-'0';
    // frac.deno= s[2]-'0';
    // if(s[0]=='#'){  // 在排序功能中代表停止，可以使用分母为0来区别
    //     frac.numer=0;
    //     frac.deno=0;
    // }
    char c='0';     // 初始化读入字符
    int a=1;        // 读入的分子
    int b=1;            // 读入的分母
    // in >> a >> c >> b;
    if(in>>a){                      // 分部读取，首先读取分子
        frac.numer=a;
    }else{
        cin.clear();cin.get(c);     // 清空缓存区，取出最后读出的字符。
        if(c=='#'){
            frac.deno=20192242;     // 设定特殊值
            return in;              // 检测到输入#则退出
        }
        // cout << c;               // 输出检查
        frac.deno=0;
        return in;
    }
    in >> c;                        // 读取字符
    if(c!='/'){
        cout << "输入出错！" << endl;
        frac.numer=a;
        frac.deno=0;
    }
    if(in>>b){                      // 读取分母
        if(c=='/')
            frac.deno=b;;
    }else{
        cin.clear();cin.get();      // 清空缓存区，取出最后取出的字符（特殊字符，空格或换行）
        frac.deno=0;
    }
    return in;
}
Fraction operator+(const Fraction& frac1, const Fraction& frac2){ //重载+运算符 
    Fraction ans;
    // 利用通分计算
    ans.deno=frac1.deno * frac2.deno;
    ans.numer= frac1.numer*frac2.deno + frac2.numer*frac1.deno;
    ans.RdcFrc();
    return ans;
    
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2){ //重载-运算符 
    Fraction ans;
    // 利用通分计算
    ans.deno=frac1.deno * frac2.deno;
    ans.numer= frac1.numer*frac2.deno - frac2.numer*frac1.deno;
    ans.RdcFrc();
    return ans;
}
Fraction operator*(const Fraction& frac1, const Fraction& frac2){ //重载*运算符 
    Fraction ans;
    ans.numer=frac1.numer*frac2.numer;
    ans.deno=frac1.deno*frac2.deno;
    ans.RdcFrc();
    return ans;
}
Fraction operator/(const Fraction& frac1, const Fraction& frac2){ //重载/运算符 
    Fraction ans;
    ans.numer=frac1.numer*frac2.deno;
    ans.deno=frac1.deno*frac2.numer;
    ans.RdcFrc();
    return ans;
}
bool operator==(Fraction frac1, Fraction frac2){ //重载==运算符 
    return (frac1-frac2).numer==0;
}
bool operator>(const Fraction& frac1, const Fraction& frac2){ //重载>运算符 
    return (float(frac1.numer) / frac1.deno) > (float(frac2.numer) /frac2.deno);
}
bool operator<(const Fraction& frac1, const Fraction& frac2){ //重载<运算符 
        return (float(frac1.numer) / frac1.deno) < (float(frac2.numer) / frac2.deno);
}

void sortFraction(Fraction f[],int num,int flag){//对分数数组排序,冒泡排序实现,flag 1和2 分别代表 从小到大 和 从大到小 排序
	int i,j;
    Fraction temp;
	for(i=0;i<num-1;i++)
	{
		for(j=1;j<num-i;j++)
		{
			if((f[j-1]>f[j]) & flag==1) // flag=1标记从小到大排序
			{
				temp=f[j-1];
				f[j-1]=f[j];
				f[j]=temp;
			}
			if((f[j-1]<f[j]) && flag==2) // flag=2标记从大到小排
			{
				temp=f[j-1];
				f[j-1]=f[j];
				f[j]=temp;
			}
		}
	}
}
