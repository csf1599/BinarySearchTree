#include <iostream>
#include "binaryExpressionTree.h"
#include "binaryTree.h"
using namespace std;

int main()
{
    binaryExpressionTree tree;

    tree.buildExpressionTree(" 3 7 + 14 * ");

    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;
}


