#include <bits/stdc++.h>
using namespace std;
struct City {
	string name;	//城市名称 
	int x,y;		//城市的x，y坐标 
	City*l, *r;		//城市的左右子节点 
};
typedef City* ptcity;
ptcity insert(ptcity Root,string n,int X,int Y) {	//实现插入功能 
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
ptcity getmin(ptcity rt){		//得到子树的最小值 
	if(rt->l==NULL)
		return rt;
	else
		return getmin(rt->l);
}
ptcity removemin(ptcity bst){	//删除子树的最小值 ，并返回最小值节点的右子树 
	if(bst->l==NULL)
		return bst->r;
	else{
		bst->l=removemin(bst->l);
		return bst;
	}
}
ptcity remove(ptcity bst,string n)	//实现删除功能 
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
ptcity search(ptcity T, string key) {	//寻找这个名字的城市对应的节点 ，实现检索功能 
	if (T == NULL || T->name == key)
		return T;
	if (T->name.compare(key)>=0)
		return search(T->l, key);
	else
		return search(T->r, key);
}
void inorder(ptcity bst) {		//中序输出BST 
	if (bst) {		
		inorder(bst->l);
		cout << "cityname:"<<bst->name<<"\tcity.x:"<<bst->x<<"\tcity.y:"<<bst->y<<endl;
		inorder(bst->r);
	}
}

void printa(ptcity bst, char a){		//打印以字符a开头的城市记录 
	if (bst) {		
		printa(bst->l,a);
		if(bst->name.at(0)==a)	
			cout << "cityname:"<<bst->name<<"\tcity.x:"<<bst->x<<"\tcity.y:"<<bst->y<<endl;		
		printa(bst->r,a);
	}
} 
void printd(ptcity bst,int p,int q,int dis){ //p,q为横纵坐标，dis为指定距离 ，打印据p,q距离小于dis的城市 
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
	ptcity city=NULL;   //定义city树
	ptcity find=NULL;   //定义检索到的结果节点
	char first='\0';
	char n='a';    		//switch判断变量
	int dis=0;     		//到定点距离
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
		cout << "1.输入1进行城市数据的写入（名称，x坐标，y坐标）" << endl; 
		cout << "2.输入2进行数据的删除（城市名称）" << endl;
		cout << "3.输入3进行数据的检索（城市名称）" << endl;
		cout << "4.输入4打印出以首字母排序的所有城市" << endl; 
		cout << "5.输入5打印出所有以指定字母开头的城市" << endl;
		cout << "6.输入6打印出与指定点距离在给定值范围的所有城市记录" << endl;
		cout << "7.输入其他数字退出程序" << endl << endl;
		cout << "请输入您对应功能的数字:";
		cin >> n;
		switch(n){
			case'1':	cout << "请输入城市名称，x坐标，y坐标：" ;
					cin >> name >> x >> y;
					city=insert(city,name,x,y);
					cout << endl;
					break;
			case'2':	cout << "请输入城市名称进行删除：" ;
					cin >> name;
					city=remove(city,name);
					cout << "删除成功" <<endl;
					break;
			case'3': cout << "请输入城市名称进行检索:";
					cin >> name;
					find=search(city,name);
					cout << "城市x坐标："<< find->x<<"\t城市y坐标" << find->y << endl;
					cout << endl;
					break;
			case'4': cout << "按首字母升序打印："	<<endl;
					inorder(city);
					cout << endl;
					break;
			case'5': cout << "请输入首字母：" ;
					cin >> first;
					printa(city,first);
					cout << endl;
					break;
			case'6': cout << "请输入指定点的x，y坐标与指定距离：" ;
					cin >> x >> y >> dis;
					printd(city,x,y,dis);
					cout << endl;
					break;
			default:cout << "退出" << endl;
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

