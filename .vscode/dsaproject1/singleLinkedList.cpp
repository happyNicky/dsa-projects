#include <iostream>
using namespace std;

struct SingleLinkedList {
    int data;
    SingleLinkedList *next;
};

SingleLinkedList *head = nullptr;

void displayList(SingleLinkedList *head);
void insertFirst(SingleLinkedList *&head,int a);
void displayList(SingleLinkedList *head)
    {

            if(head==nullptr)
            {
                cout<<"the list is Empty";
                return;

            }
            SingleLinkedList *current=head;
            cout<<"[";
            while(current!=nullptr)
            {
                cout<<current->data<<" ";

                current=current->next;
            }
            cout<<"]";
    }
    void insertFirst(SingleLinkedList *&head,int a)
    {
        SingleLinkedList *current=new SingleLinkedList;
        current->data=a;
        current->next=nullptr;

        if(head==nullptr)
          {
             head=current; 
             return;
          }
          else
          {
              current->next=head;
              head=current;
              return;
          }

    }
   
    void insertLast(SingleLinkedList *&head,int a)
    {
        SingleLinkedList *newNode=new SingleLinkedList;
        newNode->data=a;
        newNode->next=nullptr;

        if(head==nullptr)
        {
            head=newNode;

        }

            SingleLinkedList *current=head;

            while(current->next!=nullptr)
            {
                current=current->next;

            }
           current->next=newNode;

    }
    int length(SingleLinkedList *head)
    {
        int counter=1;
        while(head!=nullptr)
        {
            head=head->next;
            counter++;
        }
        return counter;
    }
 
    void insertAt(SingleLinkedList *&head,int a,int pos)
    {
               SingleLinkedList* newNode=new SingleLinkedList;
               newNode->data=a;
                SingleLinkedList* current=head;
               int count=1;
                if (pos == 1){ // Inserting at the head
                    newNode->next = head;
                    head = newNode;
                    return;
                            }
               while(count<pos-1&& current!=nullptr)
               {
                  current=current->next;
                  count++;
               }
               if(current==nullptr)
               {
                   cout<<"out of bound";
                   return;
               }
               SingleLinkedList* temp=current;
              newNode->next=current->next;
               current->next=nullptr;
               temp->next=newNode;

    }
        SingleLinkedList* reverseList(SingleLinkedList *&head)
        {
            SingleLinkedList *first;
            if(head==nullptr || head->next==nullptr)
                return head;
            first=reverseList(head->next);
            head->next->next=head;
            head->next=nullptr;

            return first;

        }

void DeleteFirst(SingleLinkedList *&head)
{

    SingleLinkedList *temp;
     temp=head;
    if(head==nullptr)
    {
        cout<<"the list is empty";
        return;
    }
    else
    {
        head=head->next;
        delete temp;

    }

}
void manu()
{
    cout<<"this one is singly Linked List ";
}



int main() {
    SingleLinkedList *first= new SingleLinkedList;
    SingleLinkedList *second=new SingleLinkedList;
    SingleLinkedList *third=new SingleLinkedList;
    SingleLinkedList *fourth=new SingleLinkedList; 
    first->data = 50;
    second->data=60;
    third->data=70;
    fourth->data=80;



    head =first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=nullptr; 


     displayList(head);
     cout<<"\n\n";
    displayList(reverseList(head));

    
  

    return 0; 
}