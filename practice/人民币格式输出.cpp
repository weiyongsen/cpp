// ����Ҹ�ʽ���
#include <iostream>
#include <string>
using namespace std;
void RMBformat(string &s);
int main()
{
	string input;
	cout << "����nnn.nn��ʽ�����������Ŀ��";
	cin >> input ;
	RMBformat (input);
	cout << "��ʽ����������";
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
