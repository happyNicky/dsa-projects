#include <iostream>
#include <stack>
#include <sstream> 
#include <cmath>
using namespace std;

double postFixEvaluator(string expression);
double eval(double x, double y, char op);

int main() {
    string k = "5 10 /";
    cout << postFixEvaluator(k) << endl;
    return 0;
}

double postFixEvaluator(string expression) {
    stack<double> k;
    double x = 0;
    double y = 0;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (token == "*" || token == "+" || token == "-" || token == "/" || token == "^") {
            x = k.top(); k.pop();
            y = k.top(); k.pop();
            k.push(eval(x, y, token[0])); 
        } else {
            k.push(stoi(token)); 
        }
    }
    return k.top();
}

double eval(double x, double y, char op) {
    switch (op) {
        case '*':
            return x * y;
        case '+':
            return x + y;
        case '-':
            return y - x;
        case '/':
            return y/ x;
        case '^':
            return pow(y, x);
    }
    return 0;
}
