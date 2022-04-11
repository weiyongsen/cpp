// 人民币格式输出
#include <iostream>
#include <string>
using namespace std;
void RMBformat(string &s);
int main()
{
	string input;
	cout << "按照nnn.nn格式输入人民币数目：";
	cin >> input ;
	RMBformat (input);
	cout << "格式化输出结果：";
	cout << input << endl;
	return 0;	 
 } 
void RMBformat (string &s)
{
	int d;
	d=s.find(".");
	if(d>3)
	{
		for (int x=d-3;x>0;x-=3)
		{
			s.insert(x,",");
		}
		s.insert(0,"RMB");
	 } 
}
