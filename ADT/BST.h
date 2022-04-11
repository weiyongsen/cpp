#include "Dictionary.h"
#include "BSTNode.h"
template <typename Key,typename E>
class BST:public Dictionary<Key,E>{
private:
	BSTNode<Key,E>* root;
	int nodecount;
	
	void clearhelp(BSTNode<Key,E>*);
	BSTNode<Key,E>* inserthelp(BSTNode<Key,E>*, const Key&, const E&);
	BSTNode<Key,E>* deletemin(BSTNode<Key,E>*);
	BSTNode<Key,E>* getmin(BSTNode<Key,E>*);
	BSTNode<Key,E>* removehelp(BSTNode<Key,E>*, const Key&);
	E findhelp(BSTNode<Key,E>*, const Key&) const;
	void printhelp(BSTNode<Key,E>*, int) const;
public:
	BST(){
		root=NULL;
		nodecount=0;
	}
	~BST(){
		clearhelp(root);
	}
	void clear(){
		clearhelp(root);
		root=NULL;
		nodecount=0;
	}
	void insert(const Key&k,const E&e){
		root=inserthelp(root,k,e);
		nodecount++;
	}
	E remove(const Key& k){
		E temp=findhelp(root,k);
		if(temp!=NULL){
			root=removehelp(root,k);
			nodecount--;
		}
		return temp;
	}
	E removeAny(){
		if(root!=NULL){
			E temp=root->element();
			root=removehelp(root,root->key());
			nodecount--;
			return temp;
		}
		else
			return NULL;
	}
	E find(const Key& k) const{
		return findhelp(root,k);
	}
	int size(){
		return nodecount;
	}
	void print(){
		if(root==NULL)
			cout << "The BST is empty.\n";
		else
			printhelp(root,0);
	}
};

template <typename Key,typename E>
E BST<Key,E>::findhelp(BSTNode<Key,E>* root,const Key&k) const{
	if(root==NULL)
		return NULL;	//empty tree
	if(k<root->key())
		return findhelp(root->left(),k);
	else if(k>root->key())
		return findhelp(root->right(),k);
	else
		return root->element();
}

template <typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::inserthelp(BSTNode<Key,E>* root,const Key& k,const E& it){
	if(root==NULL)
		return new BSTNode<Key,E> (k,it,NULL,NULL);
	if(k<root->key())
		root->setLeft(inserthelp(root->left(),k,it));
	else
		root->setRight(inserthelp(root->right(),k,it));
	return root;
}

template <typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::deletemin(BSTNode<Key,E>* rt){
	if(rt->left()==NULL)
		return rt->right();
	else{
		rt->setLeft(deletemin(rt->right()));
		return rt;
	}
}

template <typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::getmin(BSTNode<Key,E>* rt){
	if(rt->left()==NULL)
		return rt;
	else
		return getmin(rt->left());			
}
//删除该点，并将该节点右子树中的最小值移动到这里，再删除右子树中的最小值 
template <typename Key,typename E>
BSTNode<Key,E>* remomvehelp(BSTNode<Key,E>* rt,const Key& k){
	if(rt==NULL)
		return NULL;
	else if(k<rt->key())
		rt->setLeft(removehelp(rt->left()),k);
	else if(k>rt->right())
		rt->setRight(removehelp(rt->right()),k);
	else{
		BSTNode<Key,E>* temp=rt;
		if(rt->left()==NULL){
			rt=rt->right();
			delete temp;
		}
		else if(rt->right()==NULL){
			rt=rt->left();
			delete temp;
		}
		else{
			BSTNode<Key,E>* temp=getmin(rt->right());
			rt->setElement(temp->element());
			rt->setKey(temp->key());
			rt->setRight(delemin(rt->right()));
			delete temp;
		}
	}
	return rt;
}

template <typename Key,typename E>
void BST<Key,E>::clearhelp(BSTNode<Key,E>* rt){
	if(rt==NULL)
		return;
	clearhelp(rt->left());
	clearhelp(rt->right());
	delete rt;
}

template <typename Key,typename E>
void BST<Key,E>::printhelp(BSTNode<Key,E>* rt, int level) const{
	if(rt==NULL)
		return ;
	printhelp(rt->left(),level+1);
	for(int i=0;i<level;i++)
		cout << " ";	//每一行的缩进都显示树中响应节点的深度 
	cout << rt->key() << endl;
	printhelp(rt->right(),level+1);
}

