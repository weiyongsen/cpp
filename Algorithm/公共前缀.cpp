#include <bits/stdc++.h>
using namespace std;
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() <= 0) return "";
        if (strs.size() == 1) return strs[0];
        if (strs[0].size() == 0) return "";
        vector<string>::iterator i;
        int k;
        int f=0;
        int minlength=strs[0].length();
        for(k=1;k<=minlength;){
            if(f)
                break;
            for(i=strs.begin();i<strs.end()-1;i++){
            	
                if((*i).compare(0,k,*(i+1),0,k)){
                    f=1;
                    break;
                }
				if(i==strs.end()-2)
                    k++;
            }
        }
        return strs.at(0).substr(0,k-1);
    
    }
int main(){
	vector<string> strs;
//	strs.push_back("ab");
//	strs.push_back("a");
	strs.push_back("flower");
	strs.push_back("flower");
	strs.push_back("flower");
	strs.push_back("flower");
	cout << longestCommonPrefix(strs);
            
}
