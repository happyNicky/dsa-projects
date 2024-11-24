#include<iostream>
using namespace std;

const int MAXSIZE=10;
int top=-1;
void push(int input,int array[]);
int pop(int array[]);
void traverse(int array[]);
int main()
 {
   int array[MAXSIZE];
   push(10,array);
   traverse(array);
   int x=pop(array);
   cout<<endl;
   traverse(array);
   cout<<endl<<x;

}
void push(int input, int array[])
{
     if(top==MAXSIZE)
     cout<<"the stuck is full!"<<endl;
     else
     {  
        top=top+1;
        array[top]=input;
     }
}
void traverse(int array[])
{   cout<<"[";
   for(int i=0;i<=top;i++)
      cout<<array[i]<<" ";
     cout<<"]";
}
int pop(int array[])
{  int toBeReturened;
   if(top==-1)
     cout<<"the stack is empty"<<endl;
   else
      top--;
      return array[top+1];
}