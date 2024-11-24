#include<iostream>
using namespace std;
struct circularNode
{
    int data;
    circularNode* next;
};
circularNode* circularHead=nullptr;
void reverseDisplay(circularNode *current, circularNode *start = nullptr);

int main()
{
    circularNode* first= new circularNode();
    circularNode* second= new circularNode();
    circularNode* third= new circularNode();
    circularNode* fourth= new circularNode();

    first->data=1;
    second->data=2;
    third->data=3;
    fourth->data=4;

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=first;

    circularHead=first;
     reverseDisplay(circularHead);

}


void reverseDisplay(circularNode *current, circularNode *start = nullptr) {
    if (current == nullptr || (start != nullptr && current == start)) {
        return;  
    }

    if (start == nullptr) {
        start = current; 
    }

    reverseDisplay(current->next, start);  
    cout << current->data << endl;       
}