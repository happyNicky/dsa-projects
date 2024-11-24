#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head=nullptr;

void displayList(node* head);
void insertAtTheEnd(node* head, node* newNode);
void insertAtTheBiggining(node *head, int data);
void insertAtnthPosition(node* head, int data, int position);
void deleteNodeAtnthPosition(node *&head, int position);
void reverseNode(node *&head);
void recursiveReverseDisplay(node *&head);
void recursiveDisplay(node* head);
int main()
{

node *first= new node();
node *second= new node();
node *third= new node();
node *fourth= new node();
node *fivth= new node();


first->data=1;
second->data=2;
third->data=3;
fourth->data=4;
fivth->data=5;

first->next=second;
second->next=third;
third->next=fourth;
fourth->next=fivth;
fivth->next=nullptr;

node* newNode= new node();
newNode->data=99;



head=first;

// displayList(head);
// cout<<endl;
// insertAtTheEnd(head,newNode);
// cout<<endl;
// insertAtTheBiggining(head,newNode->data);
// cout<<endl;

// insertAtnthPosition(head,newNode->data,3);
// cout<<"deleting at any point "<<endl;

// deleteNodeAtnthPosition(head,1);
// displayList(head);
// reverseNode(head);
//cout<<endl;
displayList(head);

recursiveReverseDisplay(head);
cout<<endl;
displayList(head);


}
void displayList(node* head)
{

    if(head==nullptr)
    {
        cout<<"the list is empty"<<endl;

    }
    else
    {
        node* current= head;

cout<<"[";
        while(current!=nullptr)
        {
          cout<<current->data<<" ";
          current=current->next;
        }
        cout<<"]";
    }
}

void insertAtTheEnd(node* head,node* newNode)
{

newNode->next=nullptr;
  if(head==nullptr)
  {
    head=newNode;
  }
  else{
    node* current;
    current=head;
    while(current->next!=nullptr)
    {
        current=current->next;
    }
    current->next=newNode;
    
   displayList(head);
  }

}
void insertAtTheBiggining(node *head, int data)
{
   
     node* temp=new node();
     temp->data=data;
     temp->next=head;
     head=temp;
    displayList(head);
}

void insertAtnthPosition(node* head, int data, int position)
{
     if(head==nullptr)
     {
      cout<<"the list is empty"<<endl;
     }
     else
     {
      node* temp=head;
      node* newNode= new node();
      for(int i=1;i<position-1;i++)
      {
           temp=temp->next;
      }
      newNode->data=data;
      newNode->next=temp->next;
      temp->next=newNode;
      
     }
     displayList(head);
}
void deleteNodeAtnthPosition(node  *&head, int position)
{
    node* temp=head;
if(position==1)  {
    head=temp->next;
    delete temp;
  }
  else{
  
    for(int i=1;i<position-1;i++)
    {
     temp=temp->next;
    }
    node* temp1=temp->next;
    temp->next=temp->next->next;
    delete temp1;
   
  }
   displayList(head);
}
void reverseNode(node *&head)
{
  node* current;
  node* prev;
  node* nextp;
  current=head; 
  prev =nullptr;
  while(current!=nullptr)
  {
    nextp=current->next;
    current->next=prev;
    prev=current;
    current=nextp;
  }
  head=prev;
  displayList(head);
}
void recursiveReverseDisplay(node *&head1)
{    

    if(head1->next=NULL)
    {  head=head1;
       return;
    }
    
    recursiveReverseDisplay(head1->next);
    node* q= head1->next;
    q->next=head1;
    head1->next=NULL;
      
}

void recursiveDisplay(node* head)
{

  if(head==nullptr)
     return;

    cout<<head->data<<" ";
    recursiveDisplay(head->next);
}