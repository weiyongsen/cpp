#include <bits/stdc++.h>
using namespace std;
 
string addBinary(string a, string b) {
        string s="";
        int la=a.length()-1;
        int lb=b.length()-1;
        int flag=0;
        for(;la>=0&&lb>=0;){
            if(la<0||lb<0){
                break;
            }
            else if(a[la]=='0'&&b[lb]=='1'){
                if(flag){
                    s+="0";
                    --la;
                    --lb;
                    flag=1;
                }
                else{
                    s+="1";
                    --la;
                    --lb;
                    flag=0;
                }
            }
            else if(a[la]=='1'&&b[lb]=='0'){
                if(flag){
                    s+="0";
                    --la;
                    --lb;
                    flag=1;
                }
                else{
                    s+="1";
                    --la;
                    --lb;
                    flag=0;
                }
            }
            else if(a[la]=='0'&&b[lb]=='0'){
                if(flag){
                    s+="1";
                    --la;
                    --lb;
                    flag=0;
                }
                else{
                    s+="0";
                    --la;
                    --lb;
                    flag=0;
                }
            }
            else{
            	if(flag){
            		s+="1";
            		--la;
            		--lb;
				}
				else{
					flag=1;
	                s+="0";
	                --la;
	                --lb;
				}                
            }
        }
        if(la==lb){
        	if(flag)
        		s+="1";
            reverse(s.begin(),s.end());
            return s;
        }   
        else{
            while(la>=0){
                if(a[la]=='0'){
                    if(flag){
                        s+="1";
                        flag=0;
                        --la;
                    }
                    else{                      
                        s+="0";
                        flag=0;
                        --la;                       
                    }
                }
                else{
                    if(flag){
                        s+="0";
                        flag=1;
                        --la;
                    }
                    else{                      
                        s+="1";
                        flag=0;
                        --la;                       
                    }
                }
            }
            while(lb>=0){
                if(b[lb]=='0'){
                    if(flag){
                        s+="1";
                        flag=0;
                        --lb;
                    }
                    else{                     
                        s+="0";
                        flag=0;
                        --lb;                      
                    }
                }
                else{
                    if(flag){
                        s+="0";
                        flag=1;
                        --lb;
                    }
                    else{                     
                        s+="1";
                        flag=0;
                        --lb;
                    }
                }
            }
            if(flag)
                s+="1";
            reverse(s.begin(),s.end());

            return s;
        }
    }
    
int main(){
	string a="1111";
	string b="1111";
	string c;
	c=addBinary(a,b);
//	cout << a[0] << endl << b[0] << endl;
	cout << c; 
	return 0;
}
