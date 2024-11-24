#include <iostream>
#include <cstdlib>
using namespace std;
// struct for single linked list
struct nodeForSingleLinkedList
{
    int data;
    nodeForSingleLinkedList* next;
};
nodeForSingleLinkedList* head=nullptr;

// struct for single linked list ends here

// methodes signiture for single linked list
void displayReverseForSingleLinkedList(nodeForSingleLinkedList* head);
void displayListForSingleLinkedList(nodeForSingleLinkedList* head);
void insertAtTheEndForSingleLinkedList(nodeForSingleLinkedList* head, nodeForSingleLinkedList* newNode);
void insertAtTheBigginingForSingleLinkedList(nodeForSingleLinkedList *head, int data);
void insertAtnthPositionForSingleLinkedList(nodeForSingleLinkedList* head, int data, int position);
void deleteNodeAtnthPositionForSingleLinkedList(nodeForSingleLinkedList *&head, int position);
void reverseNodeForSingleLinkedList(nodeForSingleLinkedList *&head);
void recursiveReverseDisplayForSingleLinkedList(nodeForSingleLinkedList *&head);
void recursiveDisplayForSingleLinkedList(nodeForSingleLinkedList* head);
int singleLinkedListMenu();
int valueToBeInserted();
// method signiture for our menu
int menu();
int main()
{   // set up for single linked list 
            nodeForSingleLinkedList *first= new nodeForSingleLinkedList();
        nodeForSingleLinkedList *second= new nodeForSingleLinkedList();
        nodeForSingleLinkedList *third= new nodeForSingleLinkedList();
        nodeForSingleLinkedList *fourth= new nodeForSingleLinkedList();
        nodeForSingleLinkedList *fivth= new nodeForSingleLinkedList();


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

            nodeForSingleLinkedList* newNode= new nodeForSingleLinkedList();
            newNode->data=99;

            head=first;

    // the set up for single linked list has finished here

    int firstMenuChoice=menu();
    if(firstMenuChoice==1)
    {
        int choiceSingleLinkedList=singleLinkedListMenu();
        if(choiceSingleLinkedList==1)
        {
            int data=valueToBeInserted();
            insertAtTheBigginingForSingleLinkedList(head,data);
        }
    }
    
}

int  menu()
{    
    cout<<"1. sigle linked list               2. double linked list \n3. single circular linked list    4. double circular linked list "<<endl;
    int firstMenuChoice;
    cout<<"enter your choice: ";
    cin>>firstMenuChoice;
    return firstMenuChoice;
}


void displayListForSingleLinkedList(nodeForSingleLinkedList* head)
{
    if(head==nullptr)
        cout<<"the list is empty"<<endl;
    else
    {
        nodeForSingleLinkedList* current= head;
cout<<"[";
        while(current!=nullptr)
        {
          cout<<current->data<<" ";
          current=current->next;
        }
        cout<<"]";
    }
}

void insertAtEndForSingleLinkedList(nodeForSingleLinkedList* head,nodeForSingleLinkedList* newNode)
{
        newNode->next=nullptr;
        if(head==nullptr)
        {
            head=newNode;
        }
        else{
            nodeForSingleLinkedList* current;
            current=head;
            while(current->next!=nullptr)
            {
                current=current->next;
            }
            current->next=newNode;
            
        displayListForSingleLinkedList(head);
        }

}
void insertFirstForSingleLinkedList(nodeForSingleLinkedList *head, int data)
{
     nodeForSingleLinkedList* temp=new nodeForSingleLinkedList();
     temp->data=data;
     temp->next=head;
     head=temp;
    displayListForSingleLinkedList(head);
}

void insertAtNthForSingleLinkedList(nodeForSingleLinkedList* head, int data, int position)
{
     if(head==nullptr)
     {
      cout<<"the list is empty"<<endl;
     }
     else
     {
      nodeForSingleLinkedList* temp=head;
      nodeForSingleLinkedList* newNode= new nodeForSingleLinkedList();
      for(int i=1;i<position-1;i++)
      {
           temp=temp->next;
      }
      newNode->data=data;
      newNode->next=temp->next;
      temp->next=newNode;
      
     }
     displayListForSingleLinkedList(head);
}

void displayReverseForSingleLinkedList(nodeForSingleLinkedList* head)
{
    if(head==nullptr)
     return; 
     displayReverseForSingleLinkedList(head->next);
      cout<< head->data <<" ";
}

int  singleLinkedListMenu()
{   
    cout<<"1. insert at the biginning  2. insert at any position /n 3. delete at the biginning 4. delete at the end /n 5. reverse display 6. insert at the end"<<endl;
    int singleLinkedListMenuChoice;
    cout<<"enter your choice: ";
    cin>> singleLinkedListMenuChoice;
    return singleLinkedListMenuChoice;
}
int valueToBeInserted()
{
    cout<<" enter the value you want to insert: ";
    int data;
    cin>>data;
    return data;
}


