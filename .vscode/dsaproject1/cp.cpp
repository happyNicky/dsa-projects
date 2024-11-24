#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head=new node();


void display(node* head);
void displayReverse(node* p);
int main()
{
    node* first=new node();
    node* second=new node();


    first->data=1;
    second->data=2;

    first->next=second;
    head=first;

    display(head);
    cout<<endl;
 cout<<"after reversing"<<endl;
    displayReverse(head);
    display(head);
}

void display(node* head)
{
    if(head==nullptr)
     return; 
     
     cout<< head->data <<" ";
     display(head->next);
}
void displayReverse(node* p)
{
     if(p->next==nullptr)
    {  head=p;
       return;
    }
    
    displayReverse(p->next);
    node* q= p->next;
    q->next=p;
    p->next=NULL;
}