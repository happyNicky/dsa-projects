#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;


void insertAtTheBeginningOfDoublyCircularLinkedList(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    if (head == nullptr) {
        head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        Node* last = head->prev;
        new_node->next = head;
        new_node->prev = last;
        head->prev = new_node;
        last->next = new_node;
        head = new_node;
    }
}


void insertAtPositionOfDoublyCircularLinkedList(int data, int position) {
    Node* new_node = new Node();
    new_node->data = data;
    if (position == 0) {
        insertAtTheBeginningOfDoublyCircularLinkedList(data);
    } else {
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
            if (temp == head) {
                throw out_of_range("Position out of range");
            }
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;
    }
}


void deleteAtTheBeginningOfDoublyCircularLinkedList() {
    if (head == nullptr) {
        throw underflow_error("List is empty");
    }
    Node* temp = head;
    if (head->next == head) {
        head = nullptr;
    } else {
        Node* last = head->prev;
        head = head->next;
        last->next = head;
        head->prev = last;
    }
    delete temp;
}


void deleteAtTheEndOfDoublyCircularLinkedList() {
    if (head == nullptr) {
        throw underflow_error("List is empty");
    }
    Node* temp = head->prev;
    if (head->next == head) {
        head = nullptr;
    } else {
        Node* lastPrev = temp->prev;
        lastPrev->next = head;
        head->prev = lastPrev;
    }
    delete temp;
}


void deleteAtPositionOfDoublyCircularLinkedList(int position) {
    if (head == nullptr) {
        throw underflow_error("List is empty");
    }
    if (position == 0) {
        deleteAtTheBeginningOfDoublyCircularLinkedList();
    } else {
        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
            if (temp == head) {
                throw out_of_range("Position out of range");
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

void reverseDoublyCircularLinkedList() {
    if (head == nullptr || head->next == head) {
        return;
    }
    Node* current = head;
    Node* temp = nullptr;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);
    head = temp->prev;
}


void printDoublyCircularLinkedList() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}


int main() {
    insertAtTheBeginningOfDoublyCircularLinkedList(10);
    insertAtTheBeginningOfDoublyCircularLinkedList(20);
    insertAtPositionOfDoublyCircularLinkedList(15, 1);
    printDoublyCircularLinkedList();  
    deleteAtTheBeginningOfDoublyCircularLinkedList();
    printDoublyCircularLinkedList();
    deleteAtTheEndOfDoublyCircularLinkedList();
    printDoublyCircularLinkedList();  
    insertAtPositionOfDoublyCircularLinkedList(25, 1);
    insertAtPositionOfDoublyCircularLinkedList(30, 2);
    printDoublyCircularLinkedList();  
    reverseDoublyCircularLinkedList();
    printDoublyCircularLinkedList();  

    return 0;
}
