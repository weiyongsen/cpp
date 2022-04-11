#include<bits/stdc++.h>
#include "BinNode.h"
using namespace std;

template<typename Key,typename E>
class BSTNode:public BinNode <E>{
private:
	Key k;
	E it;
	BSTNode* lc;
	BSTNode* rc;
public:
	BSTNode(){
		lc=rc=NULL;
	}
	BSTNode(Key K,E e, BSTNode* l=NULL,BSTNode* r=NULL){
		k=K;
		it=e;
		lc=l;
		rc=r;
	}
	~BSTNode (){}
	E& element(){
		return it;
	}
	void SetElement(const E& e){
		it=e;
	}
	Key &key(){
		return k;
	}
	void SetKey(const Key&K){
		k=K;
	}
	inline BSTNode* left() const{
		return lc;
	}
	void SetLeft(BinNode <E>* b){
		lc=(BSTNode*)b;
	} 
	inline BSTNode* right() const{
		return rc;
	}
	void SetRight(BinNode <E>* b){
		rc=(BSTNode*)b;
	}
	bool isLeaf(){
		return (lc==NULL)&&(rc==NULL);
	}
};
