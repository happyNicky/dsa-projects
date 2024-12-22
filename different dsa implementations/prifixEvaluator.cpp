#include<iostream>
#include<stack>
#include<cmath>
#include<sstream>
#include<algorithm>

using namespace std;
float prifixEval(string expression);
float eval(float x,float y,char op);
int main()
{ string k="- + * 2 3 * 5 4 9";
  cout<<prifixEval(k);

}
float prifixEval(string expression)
{   stack<float> k;
    float x,y;
    reverse(expression.begin(),expression.end());
    stringstream ss(expression);
    string token;
    while(ss >> token)
    {     if (token == "*" || token == "+" || token == "-" || token == "/" || token == "^") {
                x= k.top(); k.pop();
                y= k.top(); k.pop();
              k.push( eval(x,y,token[0]));             
         }
         else 
         {   
            k.push(stoi(token));
         }
    }
    return k.top();

}

float eval(float x, float y, char op) {
    switch (op) {
        case '*':
            return x * y;
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '/':
            return x/ y;
        case '^':
            return pow(x, y);
    }
    return 0;
}
