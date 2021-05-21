class MyCircularQueue {
private:
    int front;
    int rear;
    int max_size;
    vector<int> v;
public:
    MyCircularQueue(int k) {
        front = -1;
        rear = -1;
        max_size = k;
        v = vector<int>(k, 0);
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % max_size;
        }
         v[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % max_size;
        }
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        else
            return v[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        else
            return v[rear];
    }
    
    bool isEmpty() {
        if (front == -1)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if ((rear + 1) % max_size == front)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
