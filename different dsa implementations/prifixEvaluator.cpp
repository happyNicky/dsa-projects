#include<iostream>
#include<stack>
#include<cmath>
#include<sstream>
#include<algorithm>

using namespace std;
int prifixEval(string expression);
int eval(int x,int y,char op);
int main()
{

}
int prifixEval(string expression)
{   stack<int> k;
    int x,y;
    reverse(expression.begin(),expression.end());
    stringstream ss(expression);
    string token;
    while(ss>>token)
    {     if (token == "*" || token == "+" || token == "-" || token == "/" || token == "^") {
                x=
                            
         }


    }

}
int eval(int x,int y,char op);