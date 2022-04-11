template <typename Key,typename E>
class Dictionary{
private:
	void operator =(const Dictionary&){}
	Dictionary(const Dictionary&){}
public:
	Dictionary(){}
	virtual void clear(){}
	virtual void insert(const Key& k,const E& e)=0;
	virtual E remove(const Key& k)=0;
	virtual E removeAny()=0;
	virtual E find(const Key& k) const=0;
	virtual int size()=0;
};
