#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
} *top=NULL;

int pop(){//similar to deleting the first element in SLL
node *temp=top;
int val=temp->data;
top=top->next;
delete temp;
temp=NULL;
return val;
}

void push(int data){//similar to adding a node at the beginning
    node* newnode = new node();
    newnode->data = data;
    newnode->next=top;
    top=newnode;
}

void print(){
   
    node* temp=top;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
cout<<"Enter your decimal number: ";
int num;
cin>>num;
int remainder,quotient;
if(num==0){
    cout<<"The equivalent binary expression of "<<num<<" is: 0"<<endl;
    return 0;
}
while(num!=0){
quotient=num/2;
remainder=num%2;
push(remainder);
num=quotient;
}
cout<<"The equivalent binary expression of "<<num<<" is: ";
print();
}