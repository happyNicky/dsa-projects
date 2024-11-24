#include <iostream>
#include <string.h>
using namespace std;

struct node{
    int data;
    node *link;
} *top=NULL;


int pop(){//similar to deleting the first element in SLL
node *temp=top;
int val=temp->data;
top=top->link;
delete temp;
temp=NULL;
return val;
}

void push(int data){//similar to adding a node at the beginning
    node* newnode = new node();
    newnode->data = data;
    newnode->link=top;
    top=newnode;
}
int main(){

 string word;
cout<<"Enter your string:";
cin>>word;
int size=word.length();
for(int i=0;i<size;i++){
   push(word[i]);
}
bool isPalindrome=true;

for(int i=0;i<size;i++){
  if(pop()!=word[i]){
    isPalindrome=false;
    break;
  }
}
if(isPalindrome)
cout<<"The string is a palindrome"<<endl;
else
cout<<"The string is not a palindrome"<<endl;
}