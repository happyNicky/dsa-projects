#include <iostream>
using namespace std;
struct node{
   int data;
    node* link;

}*top=NULL;//points to the first node




bool isEmpty(){
    if(top==NULL)
    return true;
    else
    return false;
}
int peek(){//returns the last/top most element in the stack
if(isEmpty()){
    cout<<"Stack Underflow";
    exit(1);
}
return top->data;

}

void push(int data){//similar to adding a node at the beginning
    node* newnode = new node();
    if(newnode==NULL){//if new node() returns null, memory is full(stack is full)
        cout<<"Stack Overflow"<<endl;
        exit(1);
    }
    newnode->data = data;
    newnode->link=top;
    top=newnode;
    cout<<"Element added successfully"<<endl;
}
void print(){
    if(isEmpty()){
        cout<<"Stack Underflow. No elements to be printed"<<endl;
        exit(1);
    }
    node* temp=top;
    cout<<"Stack elements are: ";
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}

int pop(){//similar to deleting the first element in SLL
if(isEmpty()){
    cout<<"Stack Underflow.Nothing to be deleted"<<endl;
    exit(1);
}
node *temp=top;
int val=temp->data;
top=top->link;
delete temp;
temp=NULL;
return val;
cout<<"Element "<<val<<" deleted successfully";
}


int main() {
    int choice,data;
    do{
        cout<<"\n-----Stack Menu-----"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Print the top element"<<endl;
        cout<<"4. Print all elements"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        { 
        case 1:
        
            cout<<"Enter element to add:";
            cin>>data;
            push(data);
            break;
        case 2:
            if(isEmpty())
            {
                cout<<"Stack is empty"<<endl;
                exit(1);
            }
            pop();
            cout<<"Last element deleted successfully"<<endl;
            break;
        case 3:
            if(isEmpty())
            {
                cout<<"Stack is empty"<<endl;
                exit(1);
            }
            data=peek();
            cout<<"Last element:"<<data;
            break;
        case 4:
           print();
           break;
        case 5:
          exit(0);
          
        default:
           cout<<"Invalid choice!";
        }

    }
   while(choice !=5); 

}