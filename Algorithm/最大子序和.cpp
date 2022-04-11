#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        vector<int>::iterator i;
        for(i=nums.begin();i<nums.end()-1;i++){
            if(*i>0)
                *(i+1)+=*i;
        }
        return *(max_element(begin(nums),end(nums)));
    }
int main(){
	vector<int> nums;
	nums.push_back(-2); 
	nums.push_back(1); 
	nums.push_back(-3); 
	nums.push_back(4); 
	nums.push_back(-1); 
	nums.push_back(2); 
	nums.push_back(1);
	nums.push_back(-5); 
	nums.push_back(4);  
	cout << maxSubArray(nums) << endl;
	return 0;
}
