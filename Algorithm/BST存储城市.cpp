#include <bits/stdc++.h>
using namespace std;
struct City {
	string name;	//�������� 
	int x,y;		//���е�x��y���� 
	City*l, *r;		//���е������ӽڵ� 
};
typedef City* ptcity;
ptcity insert(ptcity Root,string n,int X,int Y) {	//ʵ�ֲ��빦�� 
	if (Root==NULL) {
		Root = new City();
		Root->l = NULL;
		Root->r = NULL;
		Root->name = n;
		Root->x=X;
		Root->y=Y;
	}
	else if (Root->name.compare(n)>=0)Root->l = insert(Root->l, n,X,Y);
	else if (Root->name.compare(n)<0)Root->r = insert(Root->r, n,X,Y);
	return Root;
}
ptcity getmin(ptcity rt){		//�õ���������Сֵ 
	if(rt->l==NULL)
		return rt;
	else
		return getmin(rt->l);
}
ptcity removemin(ptcity bst){	//ɾ����������Сֵ ����������Сֵ�ڵ�������� 
	if(bst->l==NULL)
		return bst->r;
	else{
		bst->l=removemin(bst->l);
		return bst;
	}
}
ptcity remove(ptcity bst,string n)	//ʵ��ɾ������ 
{
    if(bst==NULL)
        return NULL;
    else if(bst->name.compare(n)>0)
        bst->l=remove (bst->l,n);
    else if(bst->name.compare(n)<0)
        bst->r=remove (bst->r,n);
    else
    {
    	ptcity temp=NULL;
        if(bst->l&&bst->r)
        {
            temp=getmin(bst->r);
            bst->name=temp->name;
			bst->x=temp->x;
			bst->y=temp->y;
			
            bst->r=removemin (bst->r);
            delete temp;
        }
        else
        {
            temp=bst;
            if(bst->l==NULL){
            	bst=bst->r;
            	delete temp;
			}             
            else{
            	bst=bst->l;
            	delete temp;
			}          
        }
    }
    return bst;
}
ptcity search(ptcity T, string key) {	//Ѱ��������ֵĳ��ж�Ӧ�Ľڵ� ��ʵ�ּ������� 
	if (T == NULL || T->name == key)
		return T;
	if (T->name.compare(key)>=0)
		return search(T->l, key);
	else
		return search(T->r, key);
}
void inorder(ptcity bst) {		//�������BST 
	if (bst) {		
		inorder(bst->l);
		cout << "cityname:"<<bst->name<<"\tcity.x:"<<bst->x<<"\tcity.y:"<<bst->y<<endl;
		inorder(bst->r);
	}
}

void printa(ptcity bst, char a){		//��ӡ���ַ�a��ͷ�ĳ��м�¼ 
	if (bst) {		
		printa(bst->l,a);
		if(bst->name.at(0)==a)	
			cout << "cityname:"<<bst->name<<"\tcity.x:"<<bst->x<<"\tcity.y:"<<bst->y<<endl;		
		printa(bst->r,a);
	}
} 
void printd(ptcity bst,int p,int q,int dis){ //p,qΪ�������꣬disΪָ������ ����ӡ��p,q����С��dis�ĳ��� 
	if (bst) {		
		printd(bst->l, p, q, dis);
		if(pow((bst->x - p),2)+pow((bst->y - q),2) <= dis)	
			cout << "cityname:"<<bst->name<<"\tcity.x:"<<bst->x<<"\tcity.y:"<<bst->y<<endl;		
		printd(bst->r, p, q, dis);
	}
} 
//int getlen(){
//	return cnt;
//}
int main() {
	int x,y;
	string name;
	ptcity city=NULL;   //����city��
	ptcity find=NULL;   //����������Ľ���ڵ�
	char first='\0';
	char n='a';    		//switch�жϱ���
	int dis=0;     		//���������
//	cin >> name >> x >> y;
//	city=insert(city,name,x,y);
//	city=insert(city,"ddd",4,4);
//	city=insert(city,"bbb",2,2);
//	city=insert(city,"aaa",1,1);
//	city=insert(city,"ccc",3,3);
//	city=insert(city,"eee",5,5);	
	while(1){				
		if(n=='\0')
			break;
		cout << "1.����1���г������ݵ�д�루���ƣ�x���꣬y���꣩" << endl; 
		cout << "2.����2�������ݵ�ɾ�����������ƣ�" << endl;
		cout << "3.����3�������ݵļ������������ƣ�" << endl;
		cout << "4.����4��ӡ��������ĸ��������г���" << endl; 
		cout << "5.����5��ӡ��������ָ����ĸ��ͷ�ĳ���" << endl;
		cout << "6.����6��ӡ����ָ��������ڸ���ֵ��Χ�����г��м�¼" << endl;
		cout << "7.�������������˳�����" << endl << endl;
		cout << "����������Ӧ���ܵ�����:";
		cin >> n;
		switch(n){
			case'1':	cout << "������������ƣ�x���꣬y���꣺" ;
					cin >> name >> x >> y;
					city=insert(city,name,x,y);
					cout << endl;
					break;
			case'2':	cout << "������������ƽ���ɾ����" ;
					cin >> name;
					city=remove(city,name);
					cout << "ɾ���ɹ�" <<endl;
					break;
			case'3': cout << "������������ƽ��м���:";
					cin >> name;
					find=search(city,name);
					cout << "����x���꣺"<< find->x<<"\t����y����" << find->y << endl;
					cout << endl;
					break;
			case'4': cout << "������ĸ�����ӡ��"	<<endl;
					inorder(city);
					cout << endl;
					break;
			case'5': cout << "����������ĸ��" ;
					cin >> first;
					printa(city,first);
					cout << endl;
					break;
			case'6': cout << "������ָ�����x��y������ָ�����룺" ;
					cin >> x >> y >> dis;
					printd(city,x,y,dis);
					cout << endl;
					break;
			default:cout << "�˳�" << endl;
					n='\0';
					break;
		}
	}
//	inorder(city);
//	ptcity find=NULL;
//	find=search(city,"ddd");
//	cout << find->x;
//	inorder(city);	
//	printa(city,'c');
//	printd(city,0,0,10);	
	return 0;
}

