#include "bits/stdc++.h"
using namespace std;

//11 3
//1 3 3 3 5 7 9 11 13 15 15
//1 3 6


// ·µ»Ø 1 2 -1 

int find(int *num, int n, int sig){
    int res=0,right=n-1,left=0,mid=0;
    while(left<=right){
    	mid=(right+left)/2;
        if(num[mid]>sig){
            right = mid-1;
        }else if(num[mid]<sig){
            left = mid+1;
        }else {
        	while(mid>1&&num[mid/2]==num[mid])
        		mid /=2;
        	while(mid>0&&num[mid-1]==num[mid])
        		mid--;
            return mid+1;
        }
    }
    return -1;
}

int main(){
	int n,k;
    cin >> n >> k;
    int num[n];
    int ans[k];
//     int num[11] = {1,3,3,3,5,7,9,11,13,15,15};
//     cout << find(num,11,3) << endl;
    for (int i=0;i<n;i++){
        cin >> num[i];
    }
    for (int i=0;i<k;i++){
        cin >> ans[i];
    }

    for (int i=0;i<k;i++){
        cout << find(num,n,ans[i]) << " ";
    }
    return 0;
}
