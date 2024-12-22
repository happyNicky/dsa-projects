#include <iostream>
#include <stack>
#include <sstream> 
#include <cmath>
using namespace std;

int postFixEvaluator(string expression);
int eval(int x, int y, char op);

int main() {
    string k = "10 2 * 50 +";
    cout << postFixEvaluator(k) << endl;
    return 0;
}

int postFixEvaluator(string expression) {
    stack<int> k;
    int x = 0;
    int y = 0;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (token == "*" || token == "+" || token == "-" || token == "/" || token == "^") {
            x = k.top(); k.pop();
            y = k.top(); k.pop();
            k.push(eval(y, x, token[0])); 
        } else {
            k.push(stoi(token)); 
        }
    }
    return k.top();
}

int eval(int x, int y, char op) {
    switch (op) {
        case '*':
            return x * y;
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '/':
            return x / y;
        case '^':
            return pow(x, y);
    }
    return 0;
}
