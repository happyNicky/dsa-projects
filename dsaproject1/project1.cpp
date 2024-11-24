#include <iostream>
#include <cstdlib>

using namespace std;

//Node for Single Linked List
struct SingleNode {
    int data;
    SingleNode* next;
};

// Node for Double Linked List
struct DoubleNode {
    int data;
    DoubleNode* next;
    DoubleNode* prev;
};

// Node for Circular Linked List
struct CircularNode {
    int data;
    CircularNode* next;
};

// Head pointers
SingleNode* singleHead = nullptr;
DoubleNode* doubleHead = nullptr;
CircularNode* circularHead = nullptr;

// Function Prototypes
void singleLinkedListMenu();
void doubleLinkedListMenu();
void circularLinkedListMenu();
void insertEndForSingleLinkedList(int data);
void insertAtBeginningSingleLinkedList(int data);
void insertAtPositionSingleLinkedList(int data, int position);
void displayReverse(SingleNode* doubleHead);
void insertEndForDoubleLinkedList(int data);
void insertAtTheBiginnningOfdoubleLinkedList(int data);
void insertAtPositionOfDoublyLinkedList(int data, int position);
void deleteAtTheBeginningOfDoublyLinkedList();
void deleteAtTheEndOfDoublyLinkedList();
void deleteAtPositionOfDoublyLinkedList(int position);
void reverseDoublyLinkedList();
void insertEndForCircularLinkedList(int data);
void insertAtTheBeginningOfCircularLinkedList(int data);
void insertAtPositionOfCircularLinkedList(int data, int position);
void deleteAtTheBeginningOfCircularLinkedList();
void deleteAtTheEndOfCircularLinkedList();
void deleteAtPositionOfCircularLinkedList(int position);
void reverseCircularLinkedList(CircularNode* node);
void printCircularLinkedList();
void displaySingleLinkedList();
void displayDoubleLinkedList();
void displayCircularLinkedList();

int main() {
    while (true) {
        cout << "1. Single Linked List\n2. Double Linked List\n3. Circular Linked List\n4. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                singleLinkedListMenu();
                break;
            case 2:
                doubleLinkedListMenu();
                break;
            case 3:
                circularLinkedListMenu();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice! Please choose again.\n";
        }
    }
    return 0;
}

// Single Linked List Operations
void singleLinkedListMenu() {
    system("cls");
    while (true) {
        
        cout << "\nSingle Linked List Operations:\n";
        cout << "1. Insert at the end \n2.insert at the biginning \n3. insert at any position \n4.reverse list\n4. Display\n5. Back to Main Menu\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
             system("cls");
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            insertEndForSingleLinkedList(data);
        } 
        else if(choice==2)
        {   system("cls");
             int data;
            cout<<"Enter data to insert: ";
            cin>>data;
            insertAtBeginningSingleLinkedList(data);
        }
        else if(choice==3)
        {    system("cls");
            int data,position;
            cout<<"Enter data to insert: ";
            cin>>data;
            cout<<"Enter the position to insert: ";
            cin>>position;
          insertAtPositionSingleLinkedList(data,position);
            
        }
         else if(choice==4)
         {
             displayReverse(singleHead);
         }
        else if (choice == 5) {
            displaySingleLinkedList();
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice! Please choose again.\n";
        }
    }
}

void insertEndForSingleLinkedList(int data) {
    SingleNode* newNode = new SingleNode();
    newNode->data = data;
    newNode->next = nullptr;

    if (singleHead == nullptr) {
        singleHead = newNode;
    } else {
        SingleNode* temp = singleHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displaySingleLinkedList() {
    if (singleHead == nullptr) {
        cout << "The list is empty\n";
    } else {
        SingleNode* temp = singleHead;
        cout << "Single Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}



// Double Linked List Operations
void doubleLinkedListMenu() {
     system("cls");
    while (true) {
        cout << "\nDouble Linked List Operations:\n";
        cout << "1. Insert at the end \n2. insert at the biginnig\n3.insert at any position \n4. delete at the biginning\n 5.delete at the end\n 6.delete at any position \n7. Display\n8.Display reverse \n9. Back to Main Menu\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
             system("cls");
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            insertEndForDoubleLinkedList(data);
        } 
        else if (choice==2)
        {  system("cls");
          int data;
            cout << "Enter data to insert: ";
            cin >> data;
           insertAtTheBiginnningOfdoubleLinkedList(data);  
        }
        else if(choice==3)
        {  system("cls");
         int data,position;
            cout << "Enter data to insert: ";
            cin >> data;
            cout<<"Enter position to insert: ";
            cin>>position;
            insertAtPositionOfDoublyLinkedList(data,position);
        }
        else if(choice==4)
        {
           deleteAtTheBeginningOfDoublyLinkedList();
        }
        else if(choice==5)
        {
          deleteAtTheEndOfDoublyLinkedList();
        }
        else if(choice==6)
        {   system("cls");
          int position;
          cout<<"Enter the position to delete: ";
          cin>>position;
          deleteAtPositionOfDoublyLinkedList(position);
        }
        else if (choice == 7) {
            displayDoubleLinkedList();
        }
        else if(choice==8)
        {
            reverseDoublyLinkedList();
        } else if (choice == 9) {
            break;
        } 
        
        else {
            cout << "Invalid choice! Please choose again.\n";
        }
    }
}

void insertEndForDoubleLinkedList(int data) {
    DoubleNode* newNode = new DoubleNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (doubleHead == nullptr) {
        doubleHead = newNode;
    } else {
        DoubleNode* temp = doubleHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayDoubleLinkedList() {
    if (doubleHead == nullptr) {
        cout << "The list is empty\n";
    } else {
        DoubleNode* temp = doubleHead;
        cout << "Double Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Circular Linked List Operations
void circularLinkedListMenu() {
     system("cls");
    while (true) {
        cout << "\nCircular Linked List Operations:\n";
       cout << "1. Insert at the end \n2. insert at the biginnig\n3.insert at any position \n4. delete at the biginning\n 5.delete at the end\n 6.delete at any position \n7. Display\n8.Display reverse \n9. Back to Main Menu\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            insertEndForCircularLinkedList(data);
        } 
        else if(choice==2)
        {   
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            insertAtTheBeginningOfCircularLinkedList(data);
        }
         else if(choice==3)
        {     
            int data,position;
            cout << "Enter data to insert: ";
            cin >> data;
            cout<<"Enter a position to insert: ";
            cin>>position;
            insertAtPositionOfCircularLinkedList(data,position);
        }
         else if(choice==4)
        {   
            deleteAtTheBeginningOfCircularLinkedList();
        }
         else if(choice==5)
        {
            deleteAtTheEndOfCircularLinkedList();
        }
         else if(choice==6)
        {    
            int position;
          cout<<"Enter a position to delete: ";
          cin>>position;
          deleteAtPositionOfCircularLinkedList(position); 
        }
        else if (choice == 7) {
            displayCircularLinkedList();
        } 
         else if(choice == 8)
        {
          reverseCircularLinkedList(circularHead);
        }
        else if (choice == 9) {
            break;
        } else {
            cout << "Invalid choice! Please choose again.\n";
        }
    }
}

void insertEndForCircularLinkedList(int data) {
    CircularNode* newNode = new CircularNode();
    newNode->data = data;

    if (circularHead == nullptr) {
        circularHead = newNode;
        newNode->next = circularHead;
    } else {
        CircularNode* temp = circularHead;
        while (temp->next != circularHead) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = circularHead;
    }
}

void displayCircularLinkedList() {
    if (circularHead == nullptr) {
        cout << "The list is empty\n";
    } else {
        CircularNode* temp = circularHead;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != circularHead);
        cout << endl;
    }
}
void insertAtBeginningSingleLinkedList(int data) {
    SingleNode* newNode = new SingleNode();
    newNode->data = data;
    newNode->next = singleHead;
    singleHead = newNode;
}
void insertAtPositionSingleLinkedList(int data, int position) {
    SingleNode* newNode = new SingleNode();
    newNode->data = data;

    if (position == 1) {
        newNode->next = singleHead;
        singleHead = newNode;
        return;
    }

    SingleNode* temp = singleHead;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void displayReverse(SingleNode* doubleHead)
{
    if(doubleHead==nullptr)
     return; 
     displayReverse(doubleHead->next);
     cout<< doubleHead->data <<" ";
}


void insertAtTheBiginnningOfdoubleLinkedList(int data) {
    DoubleNode* new_node = new DoubleNode();
    new_node->data = data;
    new_node->prev = nullptr;
    new_node->next = doubleHead;
    if (doubleHead != nullptr) {
        doubleHead->prev = new_node;
        doubleHead=new_node;
    }
    doubleHead = new_node;
}

void insertAtPositionOfDoublyLinkedList(int data, int position) {
    DoubleNode* new_node = new DoubleNode();
    new_node->data = data;
    if (position == 0) {
        insertAtTheBiginnningOfdoubleLinkedList(data);
    } else {
        DoubleNode* temp = doubleHead;
        for (int i = 0; i < position - 1; i++) {
            if (temp == nullptr) {
                throw out_of_range("Position out of range");
            }
            temp = temp->next;
        }
        new_node->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void deleteAtTheBeginningOfDoublyLinkedList() {
    if (doubleHead == nullptr) {
        throw underflow_error("List is empty");
    }
    DoubleNode* temp = doubleHead;
    doubleHead = doubleHead->next;
    if (doubleHead != nullptr) {
        doubleHead->prev = nullptr;
    }
    delete temp;
}

void deleteAtTheEndOfDoublyLinkedList() {
    if (doubleHead == nullptr) {
        throw underflow_error("List is empty");
    }
    DoubleNode* temp = doubleHead;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        doubleHead = nullptr;
    }
    delete temp;
}

void deleteAtPositionOfDoublyLinkedList(int position) {
    if (doubleHead == nullptr) {
        throw underflow_error("List is empty");
    }
    if (position == 0) {
        deleteAtTheBeginningOfDoublyLinkedList();
    } else {
        DoubleNode* temp = doubleHead;
        for (int i = 0; i < position; i++) {
            if (temp == nullptr) {
                throw out_of_range("Position out of range");
            }
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
}

void reverseDoublyLinkedList() {
    DoubleNode* temp = nullptr;
    DoubleNode* current = doubleHead;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        doubleHead = temp->prev;
    }
}

void insertAtTheBeginningOfCircularLinkedList(int data) {
    CircularNode* new_node = new CircularNode();
    new_node->data = data;
    if (circularHead == nullptr) {
        circularHead = new_node;
        new_node->next = circularHead;
    } else {
        CircularNode* temp = circularHead;
        while (temp->next != circularHead) {
            temp = temp->next;
        }
        new_node->next = circularHead;
        temp->next = new_node;
        circularHead = new_node;
    }
}

void insertAtPositionOfCircularLinkedList(int data, int position) {
    CircularNode* new_node = new CircularNode();
    new_node->data = data;
    if (position == 0) {
        insertAtTheBeginningOfCircularLinkedList(data);
    } else {
        CircularNode* temp = circularHead;
        for (int i = 0; i < position - 1; i++) {
            if (temp->next == circularHead) {
                throw out_of_range("Position out of range");
            }
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void deleteAtTheBeginningOfCircularLinkedList() {
    if (circularHead == nullptr) {
        throw underflow_error("List is empty");
    }
    if (circularHead->next == circularHead) {
        delete circularHead;
        circularHead = nullptr;
    } else {
        CircularNode* temp = circularHead;
        while (temp->next != circularHead) {
            temp = temp->next;
        }
        CircularNode* to_delete = circularHead;
        circularHead = circularHead->next;
        temp->next = circularHead;
        delete to_delete;
    }
}

void deleteAtTheEndOfCircularLinkedList() {
    if (circularHead == nullptr) {
        throw underflow_error("List is empty");
    }
    if (circularHead->next == circularHead) {
        delete circularHead;
        circularHead = nullptr;
    } else {
        CircularNode* temp = circularHead;
        while (temp->next->next != circularHead) {
            temp = temp->next;
        }
        CircularNode* to_delete = temp->next;
        temp->next = circularHead;
        delete to_delete;
    }
}

void deleteAtPositionOfCircularLinkedList(int position) {
    if (circularHead == nullptr) {
        throw underflow_error("List is empty");
    }
    if (position == 0) {
        deleteAtTheBeginningOfCircularLinkedList();
    } else {
        CircularNode* temp = circularHead;
        for (int i = 0; i < position - 1; i++) {
            if (temp->next == circularHead) {
                throw out_of_range("Position out of range");
            }
            temp = temp->next;
        }
        CircularNode* to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
    }
}

void reverseCircularLinkedList(CircularNode* node) {
       bool  isFirst = true;
    if (node == circularHead && !isFirst) {
        return;
    }
    isFirst = false;
    reverseCircularLinkedList(node->next);
    cout << node->data << " ";
    if (node == circularHead) {
        isFirst = true;
    }
}

void printCircularLinkedList() {
    if (circularHead == nullptr) {
        return;
    }
    CircularNode* temp = circularHead;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != circularHead);
    cout << endl;
}




