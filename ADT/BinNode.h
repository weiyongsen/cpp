template <typename E>
class BinNode{
public:
	virtual ~BinNode(){}
	virtual E& element()=0;
	virtual void SetElement(const E&)=0;
	virtual BinNode* left() const =0;
	virtual BinNode* right() const=0;
	virtual void SetLeft(BinNode*) =0;
	virtual void SetRight(BinNode*)=0;
	virtual void isLeaf()=0;
};
