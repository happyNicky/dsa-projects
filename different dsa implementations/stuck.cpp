#include <iostream>
#include <stack>
using namespace std;


struct stuck
{
    int data;
    stuck* next;
};
stuck* top = nullptr;
void push(int data);
void display(stuck* top);
int pop();
bool isEmpty(stuck* top);
int topElement(stuck* top);
string reverseString(string s);
void reverseLinkedListUsingStack(stuck* &top);
int main ()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display(top);
    
    reverseLinkedListUsingStack(top);
    pop();
    cout<<endl;
    display(top);
}

void push(int data)
{
    stuck* temp = new stuck;
    temp->data = data;
    temp->next = top;
    top = temp;
}
int pop()
{
    if(top == nullptr)
    {
        cout << "stuck underflow" << endl;
        return -1;
    }
    else
    {
        stuck* temp = top;
        top = top->next;
        int data = temp->data;
        delete temp;
        return data;
    }
}
void display(stuck* top)
{
    while (top != nullptr)
    {
        cout << top->data << " ";
        top = top->next;
    }
}
bool isEmpty(stuck* top)
{
    return top == nullptr;
}
int topElement(stuck* top)
{
    return top->data;
}

string reverseString(string s)
{
    stack<char> sta;
    for(char c : s)
        sta.push(c);
    
    for(size_t i = 0; i < s.length(); i++)
    {
        s[i] = sta.top();
        sta.pop();
    }
    return s;
}

void reverseLinkedListUsingStack(stuck* &top)
 { 
    stuck* temp=top; 
    stack<stuck*> s;
    while(temp!=nullptr) 
    { s.push(temp);
     temp=temp->next; 
    } 
    temp=s.top();
    
     top = temp;
      s.pop();
       while(!s.empty()) {
         temp->next=s.top(); 
         s.pop(); 
         temp=temp->next; 
         } 
         temp->next=nullptr;
}

