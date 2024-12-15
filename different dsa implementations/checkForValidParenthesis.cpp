#include <iostream>
#include<stack>
using namespace std;
bool isValid(string s);
int main()
{  string s="(){}";
    cout<<isValid(s);
}
bool isValid(string s)
{ 
    int n=s.length()-1;
    stack<char> temp;
   for(int i=0;i<n;i++)
   { if(s[i]=='('||s[i]=='{'||s[i]=='[')
        temp.push(s[i]);
     else if(s[i]==')'||s[i]=='}'||s[i]==']')
       { char x;
        if(s[i]==')') x='(';
        else if(s[i]=='}') x='{';
        else x='[';
        if(temp.empty()==true)
            return false;
         else if(temp.top()!=x)
            return false;
         else 
           temp.pop();
       }
        
   }
   if(temp.empty())
    return false;
    return true;

}