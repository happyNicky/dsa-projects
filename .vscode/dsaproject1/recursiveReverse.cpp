#include<iostream>
using namespace std;
struct node
{
int data;
node* next;
};

node* head = nullptr;
void recursiveReverse(node* head);
void dispaly(node* head);
int main()
{
    node* first= new node();
    node* second= new node();
    node* third= new node();
    node* fourth= new node();
    node* fifth= new node();


    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    head=first;

  dispaly(head);

}

void display(node* head)
{
    if(head==nullptr)
      return;
      cout<<head->data +" ";
      dispaly(head);
    
}
