#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode* next = nullptr;
};

struct Queue {
    QueueNode* front = nullptr;
    QueueNode* rear = nullptr;
};

// Returns true if the queue is empty, false otherwise
bool isEmpty(const Queue* q) {
    return q->front==nullptr;
}

// Adds a new value to the end of the queue
void enqueue(Queue* q, int value) {

    QueueNode* newNode = new QueueNode{value};

    if (q->front == nullptr) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


// Removes the front value from the queue, stores it in value, and returns true if successful, or false if the queue is empty
bool dequeue(Queue* q, int &value) {
    if (q->front != nullptr) {
        value = q->front->data;

        QueueNode* front1 = q->front;

        q->front = q->front->next;
        cout << "(Removed " << value << " from queue)" << endl;

        delete front1;

        if (q->front == nullptr) q->rear = nullptr;

        return true;
    } else {
        cout << "Cannot dequeue. The queue is empty." << endl;
        return false;
    }
}

// Displays the queue contents from front to back
void displayQueue(const Queue* q) {
    if (q->front == nullptr) {
        cout << "(Empty)" << endl;
        return;
    }

    QueueNode* i = q->front;

    while(i != nullptr) {
        (i->next==nullptr) ? cout << i->data : cout << i->data << " -> ";
        i = i->next;
    }

    cout << endl;
}

// Frees all alocated memory in the queue
void freeQueue(Queue* q) {
    while(q->front != nullptr) {
        QueueNode* i = q->front;

        q->front = q->front->next;

        delete i;
    }

    q->rear = nullptr;

    cout << "Deleted all elements from queue." << endl;
}

int main() {

    Queue myQueue;
    int value = 0;
    char choice = ' ';

    while(choice != 't') {
        cout << "*** Current items in queue: ";
        displayQueue(&myQueue);
        cout << "Options: (e)nqueue, (d)equeue, (f)ree, (t)erminate: ";
        cin >> choice;
        if (choice == 'e') {
            cout << "Enter the value: ";
            cin >> value;
            enqueue(&myQueue, value);
        } else if (choice == 'd') dequeue(&myQueue, value);
        else if (choice == 'f') freeQueue(&myQueue);
        else if (choice == 't') {
            cout << "Exiting program..." << endl;
        } else cout << "Invalid option! Try again." << endl;
    }

    freeQueue(&myQueue);
    return 0;
}