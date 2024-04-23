#ifndef BET
#define BET
#include "binaryTree.h"
#include <stack>
using namespace std;

class binaryExpressionTree : public binaryTreeType<string>{
private:
	double evaluateExpressionTree(nodeType<string>*);
public:
	void buildExpressionTree(string);
	double evaluateExpressionTree();
	bool search(const string&) const;
	void insert(const string&);
	void deleteNode(const string&);
};
#endif
