#include <iostream>
#include <algorithm>
using namespace std;
#define Swap(a,b){int temp=a; a=b; b=temp; } 
int data[]={1,2,3,4,5,6,7,8,9,10,32,15,18,33};
int num=0;
int perm(int begin,int end)
{
	int i;
	if (begin==end)
	{
		cout << data[0]<< data[1]<< data[2] << endl;
		num++;
	}
		
	else
		for (i=begin;i<=end;i++)
		{
			Swap(data[begin],data[i]);
			perm(begin+1,end);
			Swap(data[begin],data[i]);
		}
}
int main()
{
	perm(0,2);
	cout <<num << endl;
	return 0;
}
