#include<iostream>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};
node* head=new node();
void display(node* head);
void displayReverse(node* head);
void insertAtFirst(node *&head, int value);
void insertAtEnd(node *&head, int value);
void insertAtMiddle(node *&head, int value, int position);
int main()
{

node* first = new node();
node* second = new node();
node* third = new node();
node* fourth = new node();
node* fivth = new node();


first->data=1;
second->data=2;
third->data=3;
fourth->data=4;
fivth->data=5;

first->next= second;
second->next=third;
third->next=fourth;
fourth->next=fivth;
fivth->next=nullptr;

first->prev=nullptr;
second->prev=first;
third->prev=second;
fourth->prev=third;
fivth->prev=fourth;
head=first;

display(head);
cout<<endl;
displayReverse(head);
insertAtFirst(head,0);
cout<<endl;
display(head);
cout<<endl;
cout<<"insert at the end"<<endl;
insertAtEnd(head,6);
display(head);
cout<<endl;
cout<<"insertion at the nth position"<<endl;
insertAtMiddle(head,10,3);
display(head);


}

void display(node* head)
{
    if(head==nullptr)
    cout<<"the list is empty"<< endl;
    else
    {   cout<<"[";
        while (head != nullptr)
        {
           cout<<head->data<<" ";
           head=head->next;
        }
        cout<<"]";
        
    }
}
void displayReverse(node* head)
{
    node* temp;

    if(head==nullptr)
      cout<<"the list is empty"<<endl;
    else{
        while (head->next!=nullptr)
        {
            head=head->next;
        }
       
       
        while(head !=nullptr)
        {
            cout<<head->data<<" ";
            head=head->prev;
        }
    }
}
void insertAtFirst(node *&head, int value){
    node* temp=new node();
    temp->data=value;
            if(head==nullptr)
             {
                temp->next=nullptr;
                temp->prev=nullptr;
                head=temp;
             }
             else{
               temp->next=head;
               temp->next->prev=temp;
               temp->prev=nullptr;
               head=temp;
             }
}
void insertAtEnd(node  *&head, int value)
{
      node* temp=new node();
      temp->data=value;
       if(head==nullptr)
       {        temp->next=nullptr;
                temp->prev=nullptr;
                head=temp;
       }
       else
       {
            temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }

            node* temp1=new node();
            temp->next=temp1;
            temp1->prev=temp;
            temp1->next=nullptr;
            temp1->data=value;
       }
}
void insertAtMiddle(node *&head, int value, int position)
{   node* temp= new node;
     temp=head;
    if(head==nullptr)
      cout<<"the list is empty"<<endl;
    else 
    {
        for( int i=1;i<position;i++)
        {
            temp=temp->next;
        }

         temp->prev->next=temp;
         temp->prev= temp->prev;
         temp->next=temp->next;
         temp->next->prev=temp;
         temp->data=value;
    }
}