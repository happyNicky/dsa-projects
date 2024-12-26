#include<iostream>
using namespace std;
struct node
{  int data;
   node* next;
};
 

struct que
{  node* front=nullptr; 
  node* rear=nullptr;
  void enque(int x)
  {  node* temp=new node;
     temp->data=x;
     temp->next=nullptr;
     if(front==nullptr)
     front=temp;
     if(rear==nullptr)
       { rear=temp;
         return;
       }
     rear->next=temp;
     rear=rear->next;
  }
  int deque()
  { if(front==nullptr)
      {
        cout<<"the list is empty"<<endl;
        return -1;
      }
      int x=front->data;
      front=front->next;
      return x;
  }
  void display()
  {    if(front!=nullptr)
      {
     node* temp=front;
     cout<<"elements of que: ";
     while(temp!=nullptr)
      {  cout<<temp->data ;
          cout<<",";
         temp=temp->next;
      }
      }
  }
  bool isEmpty()
  {  if(front==nullptr || rear==nullptr)
       return true;
      return false;
  }
  int getFront()
  {  if(front!=nullptr)
       return front->data;
     else 
     {  cout<<"the list is empty"<<endl;
        return -1;
     }
  }
  int getRear()
  { if(rear==nullptr)
    { cout<<"the list is empty"<<endl;
       return -1;
    }
     else 
     {
        return rear->data;
     }

  }
   

};
int main()
{ que k;
  k.enque(1);
  k.enque(2);
  k.enque(3);
  k.display();
  k.deque();
  cout<<endl;
  k.display();
  cout<<endl;
 
}