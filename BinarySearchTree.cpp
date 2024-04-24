#include <iostream>
#include "binaryExpressionTree.h"
#include "binaryTree.h"
#include <fstream>
#include <string>


using namespace std;

int main()
{
	fstream infile;
	ofstream ofile;
	infile.open("RpnData.txt");
	ofile.open("output.txt");
	while (!infile.eof()) {
		binaryExpressionTree tree;
		string express;
		getline(infile, express);
		tree.buildExpressionTree(express);
		cout << "info being placed into file : " << endl;
		cout << tree.evaluateExpressionTree() << endl;
		ofile << to_string(tree.evaluateExpressionTree()) << endl;
		tree.destroyTree();
	}
	ofile.close();
}


