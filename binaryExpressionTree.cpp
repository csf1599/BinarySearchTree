#include "binaryExpressionTree.h"
//Get a postfix expression(this will be an input to the evaluateExpressionTree function)
// 
//Convert the string to a character array(include <cstring>)
// 
//For each token in the expression :
// 
//If token is a number
// 
//Create a node
// 
//Convert the token from a character array to a string
// 
//Store the string in the info field
// 
//Push the new node onto the stack
// 
//else if token is an operator
// 
//Create a node and store the operator in the info field
// 
//If stack is not empty
// 
//Use top() to get a reference to the node at the top of the stack
// 
//Store the reference in the rLink field of the new node.
// 
//Use pop() to remove the node from the stack
// 
//If stack is not empty
// 
//Use top() to get a reference to the node at the top of the stack
// 
//Store the reference in the lLink field of the new node
// 
//Use pop() to remove the node from the stack
// 
//Push the new node back onto the stack
// 
//else
// 
//Error – Stack is empty
// 
//else
// 
//Error – Stack is empty
// 
//else
// 
//Error – unsupported token
// 
//Get the next token
// 
//if stack is not empty

void binaryExpressionTree::buildExpressionTree(string postfix) {
	stack<nodeType<string>*> nodeStack;

	char* expression = new char[postfix.length() + 1];

	strcpy(expression, postfix.c_str());

	char* token = strtok(expression, " ");

	while (token != nullptr) {
		if (isdigit(token[0])) {
			nodeType<string>* newNode = new nodeType<string>;
			string token_string(token);
			newNode->info = token_string;
			nodeStack.push(newNode);
		}
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {

		}
	}




}
