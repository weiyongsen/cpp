#include "table.h"

using namespace std;
vector<string> token{
    "CONSTTK",
    "INTTK",
    "IDENFR",
    "ASSIGN",
    "INTCON",
    "COMMA",
    "IDENFR",
    "ASSIGN",
    "MINU",
    "INTCON",
    "SEMICN"
};
vector<string> ans;
void error(){
    cout << "error!" << endl;
}

void idenfr(int pos){
    if(token[pos]==table["标识符"])
        ans.emplace_back("整数");
}
void intcon(int pos){
    if(token[pos]==table["整型常量"])
        ans.emplace_back("字符");
}
bool charcon(int pos){
    if(token[pos]==table["字符常量"])
        return true;
    else
        return false;
}


bool cldy(int pos){
    int i=pos;
    if(token[i] == "INTTK"){
        idenfr(token[i+1]);
        denghao(token[i+2]);
        intcon(token[i+3]);
        i = i+4;
        while(token[i]=='comma'){
            idenfr(token[i+1]);
            denghao(token[i+2]);
            intcon(token[i+3]);
            i=i+4;
        }
    }else if(token[i]=="CHARTK"){

    }else{
        error();
    }
}

int main(){

}




