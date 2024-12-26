#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype> 

using namespace std;
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
string infixToPostfix(const string& expression) {
    string result;
    stack<char> stack;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            result += token + " ";
        } else if (token == "(") {
            stack.push('(');
        } else if (token == ")") {
            while (!stack.empty() && stack.top() != '(') {
                result += stack.top();
                result += " ";
                stack.pop();
            }
            stack.pop(); 
        } else {
            while (!stack.empty() && precedence(token[0]) <= precedence(stack.top())) {
                result += stack.top();
                result += " ";
                stack.pop();
            }
            stack.push(token[0]);
        }
    }

    while (!stack.empty()) {
        result += stack.top();
        result += " ";
        stack.pop();
    }

    return result;
}

int main() {
    string expression = "3 + 5 * ( 2 ^ 3 - 4 ) ^ ( 2 + 3 * 2 ) - 1";
    cout << "Infix Expression: " << expression << endl;
    cout << "Postfix Expression: " << infixToPostfix(expression) << endl;
    return 0;
}
