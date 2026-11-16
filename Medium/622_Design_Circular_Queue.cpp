// Problem: 622. Design Circular Queue
// Difficulty: Medium
class MyCircularQueue {
public:
    vector<int> q;
    int front;
    int rear;
    int count;
    int size;
    MyCircularQueue(int k) {
        q.resize(k);
        front = 0;
        rear = -1;
        count = 0;
        size = k;
    }
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % size;
        q[rear] = value;
        count++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;
        count--;
        return true;
    }
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return q[rear];
    }
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == size;
    }
};
