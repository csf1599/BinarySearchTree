#ifndef BTT
#define BTT
#include<iostream>
#include<string>
#include<cstring>

template <class Type>
struct nodeType {
	Type info;
	nodeType<Type>* lLink;
	nodeType<Type>* rLink;
};
template <class Type>
class binaryTreeType {
protected:
	nodeType<Type>* root;
public:
	binaryTreeType();
	virtual bool search(const Type& searchItem) const = 0;
	virtual void insert(const Type& insertItem) = 0;
	virtual void deleteNode(const Type& deleteItem) = 0;
};

#endif
