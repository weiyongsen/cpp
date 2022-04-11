#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int k=0;k<numRows;k++){
            if(k==0){
                temp.push_back(1);
            }
            else if(k==1){
                temp.push_back(1);
                temp.push_back(1);
            }
            else{
                temp.push_back(1);
                for(vector<int>::iterator i=ans.at(k-1).begin();i<ans.at(k-1).end();i++){                 
                    temp.push_back(*i+*(i+1)) ;                 
                }
                temp.push_back(1);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
int main(){
	int n;
	cin >> n;
	vector<vector<int>> ans;
	ans=generate(n);
	for(vector<vector<int>>::iterator i= ans.begin();i<ans.end();i++){
		for(vector<int>::iterator j=(*i).begin();j<(*i).end();j++){
			if(j+1==(*i).end())
				cout << *j << endl;
			else
				cout << *j << " ";
		}
	}
	return 0;
}
