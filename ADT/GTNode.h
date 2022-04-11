
template <typename E>
class GTNode{
public:
	bool isLeaf();
	GTNode* parent();
	GTNode* leftmostChild();
	GTNode* rightSibling();
	void setValue(E&);
	void insertFirst(GTNode<E>*);
	void insertNext(GTNode<E>*);
	void removeFirst();
	void removeNext();
}; 
