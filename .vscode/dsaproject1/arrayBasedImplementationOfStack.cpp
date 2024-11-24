#include<iostream>
using namespace std;
void push(int x,int arra[]);
int pop(int array[]);
int top=-1;
void display(int arra[]);
int main()
{
    int arra[10];
    
    push(1,arra);
  
    push(2,arra);
  
    push(3,arra);
    display(arra);
   int  x= pop(arra);
    cout<<endl;
    display(arra);
    
  


}
void push(int x, int arra[])
{   if(top==9)
   { 
    cout<<"stack overflow!"<<endl;
   }
   
  top++;
  arra[top]=x;
}
int pop(int arra[])
{    if(top==0)
      cout<<"stack underflow!"<<endl;
    int value=arra[top];
    top--;
    return value;
}
void display(int arra[])
{
    for(int i=0;i<=top;i++)
    {
        cout<<arra[i]<< " ";
    }
}