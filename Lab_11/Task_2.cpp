#include <iostream>
#include <stdexcept>

using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size) : capacity(size), front(0), rear(-1), count(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& item) {
        if (isFull()) {
            throw QueueOverflowException();
        }
        rear = (rear + 1) % capacity;
        data[rear] = item;
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw QueueUnderflowException();
        }
        T item = data[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }
};

int main() {
    try {
        Queue<int> q(3);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(4);
    }
    catch (const QueueOverflowException& e) {
        cerr << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try {
        Queue<int> q(3);
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue();
    }
    catch (const QueueUnderflowException& e) {
        cerr << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
