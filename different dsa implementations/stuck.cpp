#include <iostream>
using namespace std;
struct stuck
{
    int data;
    stuck* next;
};
stuck* top=nullptr;
void push(int data);
void display(stuck* top);
int pop();
int main ()
{  stuck* first= new stuck;
    first->data=1;
    first->next=nullptr;
    top=nullptr;
    
    display(top);
    int x= pop();
    cout<<x<<endl;
    display(top);
    
    
}
void push(int data)
{
    stuck* temp= new stuck;
    temp->data=data;
    temp->next=top;
    top=temp;
    delete temp;
}

int pop()
{  if(top==nullptr)
    {  cout<<"stuck underflow"<<endl;
       return -1;
    }
   else 
     {  stuck* temp=top;
         top=top->next;
         return temp->data;
     }

}
void display(stuck* top)
{  while ( top!=nullptr)
   { cout<<top->data<<" ";
     top=top->next;
    }

}