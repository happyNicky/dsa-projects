#include <iostream>
using namespace std;

struct arr {
    int size = 10;
    int que[10];
    int front = -1;
    int rear = -1; 

    void enque(int x) {
        if (rear == size - 1) {
            cout << "The queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        que[rear] = x;
    }

    int deque() {
        if (front == -1 || front > rear) {
            cout << "The queue is empty" << endl;
            return -1;
        }
        int x = que[front];
        front++;
        if (front > rear) {
            front = rear = -1; 
        }
        return x;
    }
    bool isEmpty()
    {
        if(front==-1&& rear==-1)
          return true;
          return false;
    }

    int fron() {
        if (front >= 0 && front <= rear) {
            return que[front];
        }
        cout << "The queue is empty" << endl;
        return -1;
    }

    int rar() {
        if (rear >= 0 && rear < size) {
            return que[rear];
        }
        cout << "The queue is empty" << endl;
        return -1;
    }

    void display() {
        if (front == -1) {
            cout << "The queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << que[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    arr a;
    a.enque(1);
    a.enque(2);
    a.enque(3);
    a.display();
    a.deque();
    a.display();
    a.deque();
    a.display();
    a.deque();
    a.display();

    return 0;
}
