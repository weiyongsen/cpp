//�ڶ�С���� 
//һȺ����Ҫѡ�º������º�����ѡ�񷽷��ǣ���Nֻ��ѡ����Χ��һȦ��
//��ĳλ����˳����Ϊ1~N�š�
//�ӵ�1�ſ�ʼ������ÿ�ִ�1����3��
//������3�ĺ��Ӽ��˳�Ȧ�ӣ�
//�����ִӽ��ڵ���һֻ���ӿ�ʼͬ���ı�������˲���ѭ����
//���ʣ�µ�һֻ���Ӿ�ѡΪ������������ԭ���ڼ��ź��ӵ�ѡ������
#include <bits/stdc++.h>
using namespace std;

int main(){
	int num;
	cin >> num;
	int a[num];
	for(int i=0;i<num;i++){
		a[i]=i+1;
	}
	int len = num;
	int cnt=0;
	int cur=-1;
	while(len!=1){
		cnt++;
		if(cur==len-1)
			cur=0;
		else{
			cur++;
		}
		
		if(cnt==3){
			cnt=0;
			len--;
			
			for(int i=cur;i<len;i++){
				a[i]=a[i+1];
			}
			cur--;
		}
		
	}
	cout << a[0];
	return 0;
} 
