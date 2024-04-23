#include "binaryExpressionTree.h"
#include <string>
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
//
//pop expression tree from stack and store in root
//
//if stack is not empty
//
//error set root back to null

void binaryExpressionTree::buildExpressionTree(string postfix) {
    stack<nodeType<string>*> nodeStack;

    char* expression = new char[postfix.length() + 1];
    strcpy(expression, postfix.c_str());

    char* token = strtok(expression, " ");
    do {
        if (isdigit(token[0])) {
            string tokenStr(token);
            nodeType<string>* newNode = new nodeType<string>;
            newNode->info = tokenStr;
            newNode->lLink = newNode->rLink = nullptr;
            nodeStack.push(newNode);
        }
        else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            string tokenStr(token);
            nodeType<string>* newNode = new nodeType<string>;
            newNode->info = tokenStr;
            if (!nodeStack.empty()) {
                newNode->rLink = nodeStack.top();
                nodeStack.pop();
            }
            else {
                cout << "Error - Stack is empty" << endl;
                return; 
            }
            if (!nodeStack.empty()) {
                newNode->lLink = nodeStack.top();
                nodeStack.pop();
            }
            else {
                cout << "Error - Stack is empty" << endl;
                return;
            }
            nodeStack.push(newNode);
        }
        else {
            cout << "Invalid token type: " << token << endl;
            return;
        }
        token = strtok(nullptr, " ");
    } while (token != nullptr);

    if (nodeStack.empty()) {
        cout << "Error - Stack is empty" << endl;
        root = nullptr; 
        return;
    }

    root = nodeStack.top();
    nodeStack.pop();

    if (!nodeStack.empty()) {
        cout << "Error - Stack is not empty" << endl;
        root = nullptr;
    }
}

void binaryExpressionTree::deleteNode(const string& string) {
    cout << "What am I doing";
}
void binaryExpressionTree::insert(const string& string) {
    cout << "I dont know";
}
bool binaryExpressionTree::search(const string& string) const {
    cout << "Still lost";
    return true;
}

//(p is a pointer to a node
//    x is the left operand of an expression
//    y is the right operand of an expression
//    op is the operator
//    The function, evaluate(p) is recursive)
//    if p is a leaf then
//        return the value stored at p(value is stored as a string, convert to double using stod()
//            before returning)
//    else
//        op is the info field of p
//        x = evaluate(left(p))
//        y = evaluate(right(p))
//        Evaluate the expression x op y and return the result


double binaryExpressionTree::evaluateExpressionTree(nodeType<string>* p) {
    if (p->lLink == nullptr && p->rLink == nullptr) {
        return stod(p->info);
    }
    else {
        double x = evaluateExpressionTree(p->lLink);
        double y = evaluateExpressionTree(p->rLink);
        double result = 0.0;
        if (p->info == "+") {
            result = x + y;
        }
        else if (p->info == "-") {
            result = x - y; 
        }
        else if (p->info == "*") {
            result = x * y;
        }
        else if (p->info == "/") {
            result = x / y;
        }
        return result;
    }
}
double binaryExpressionTree::evaluateExpressionTree() {
    return evaluateExpressionTree(root);
}
