#include <bits/stdc++.h>
#include<tr1/unordered_set>
using namespace std;
using namespace std::tr1;
int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int rk=-1,n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            
            if(i!=0){
                occ.erase(s[i-1]);
            }
            while(i+rk<n && !occ.count(s[rk+1])){
                occ.insert(s[rk+1]);
                ++rk;
            }
            // ans=ans<rk-i+1?rk-i+1:ans;
            ans=max(ans,rk-i+1);
            
        }
        return ans;
    }

int main(){
	string s = "au";
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
	
}
