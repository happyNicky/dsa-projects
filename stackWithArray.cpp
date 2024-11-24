#include <iostream>
#define MAX 30
using namespace std;
int stack_arr[MAX];//declared it globally since most functions use it
int top=-1;//instead of passing it to every function,best way is to declare it globally
bool isFull(){
    if(top==MAX-1)
     return true;
    else
    return false;
}
bool isEmpty(){
    if(top==-1)
    return true;
    else
    return false;
}
void push(int data){
    if(isFull()){
    cout<<"Stack Overflow"<<endl;
    return;
    }
    stack_arr[++top]=data;
}
int pop(){
    if(isEmpty())//if stack is empty
    {
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    top--;
    return stack_arr[top+1];
}
void print(){
    if(isEmpty()){
        cout<<"Stack Underflow.Nothing to be printed"<<endl;
        return;
    }
        for(int i=top;i>=0;i--){
            cout<<stack_arr[i]<<" ";//from top most to bottom
        }
    }

int main(){
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
         if(isFull()){
            cout<<"Stack Overflow";
            exit(1);
            }
            cout<<"Enter element to add:";
            cin>>data;
            push(data);
            cout<<"Element added successfully"<<endl;
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
            data=stack_arr[top];
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