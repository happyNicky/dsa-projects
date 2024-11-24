#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

#define MAX 100

int stack[MAX];//since we store only numbers
char infix[MAX], postfix[MAX];//infix to store the input expression and postfix to store the whole postfix expression after conversion
int top=-1;
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
    stack[++top]=data;
}

int pop(){
    if(isEmpty())//if stack is empty
    {
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    top--;
    return stack[top+1];
}


int precedence(char symbol) {
    if (symbol == '+' || symbol == '-') return 1;
    if (symbol == '*' || symbol == '/') return 2;
    if(symbol == '^') return 3;
    return 0;
}
bool space(char c){
if(c==' '|| c=='\t')
return true;
else
return false;
}
void inToPost(){
    int i,j=0;
    char symbol; //to store the symbol of the infix expression in a variable
    char next;
    for( i=0;i<strlen(infix);i++){
        symbol=infix[i]; 
        if(!space(symbol)){
        switch(symbol){
            case '(': 
            push(symbol);//if the symbol is a left parenthesis, push it to the stack
            break;
            case ')':
            while((next=pop())!='(')//this while loop also discard the left parenthesis
            postfix[j++]=next;
            break;//pop all the operators from the stack and print them(store them in postfix array) until we find the left parenthesis
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            while(!isEmpty()&& precedence(stack[top])>= precedence(symbol))
             postfix[j++]=pop();
             push(symbol);
             break;

            default:
            postfix[j++]=symbol;
        }    
    }
    }
    while(!isEmpty())// incase we are left with some sybols after the for loop
    postfix[j++]=pop();
    postfix[j]='\0';
    cout<<endl;
    
}



void print(){
    cout<<"Postfix Expression: ";
     for(int i=0;i<strlen(postfix);i++){
        cout<<postfix[i];
    }
    cout<<endl;
}
int post_eval(){
    int i,a,b;
    for(i=0;i<strlen(postfix);i++){
     if(postfix[i]>='0'&& postfix[i]<='9')
       push(postfix[i]-'0');//to get and push an integer since we wevaluate them
       else{
         a=pop();
         b=pop();
         switch(postfix[i]){
            case '+':
            push(b+a);
            break;
            case '-':
            push(b-a);
            break;
            case '*':
            push(b*a);
            break;
            case '/':
            push(b/a);
            break;
            case '^':
            push(pow(b,a));
            break;
         }
       }


       }

         return pop();
    }


int main(){
cout<<"Enter the infix expression: ";
    gets(infix);//get string function.automatically adds /0 at the end of the string
    inToPost();
    post_eval();
    int result=post_eval();
    print();
    cout<<"Result of postfix evaluation: "<<result<<endl;

}