#include <iostream>

using namespace std;

class Queue
{
private:
    int capacity, front, rear;
    int *ptr;

public:
    Queue(int cap);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void insert(int);
    int getFront();
    int getRear();
    void remove();
    void display();
};

Queue::Queue(int cap)
{
    if (cap < 1)
    {
        cout << "Error: Invalid queue capacity!\n";
        ptr = nullptr;
        return;
    }
    capacity = cap;
    front = rear = -1;
    ptr = new int[capacity];
}

Queue::~Queue()
{
    if (ptr != nullptr)
        delete[] ptr;
}

bool Queue::isEmpty()
{
    return front == -1;
}

bool Queue::isFull()
{
    return (rear + 1) % capacity == front;
}

void Queue::insert(int data)
{
    if (ptr == nullptr)
    {
        cout << "Error: Queue not initialized!\n";
        return;
    }
    if (isFull())
    {
        cout << "Error: Queue Overflow! Cannot insert " << data << ".\n";
        return;
    }

    if (isEmpty()) 
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % capacity; 
    }

    ptr[rear] = data;
    cout << data << " enqueued.\n";
}

int Queue::getFront()
{
    if (ptr == nullptr || isEmpty())
    {
        cout << "Error: Queue is empty!\n";
        return -1;
    }
    return ptr[front];
}

int Queue::getRear()
{
    if (ptr == nullptr || isEmpty())
    {
        cout << "Error: Queue is empty!\n";
        return -1;
    }
    return ptr[rear];
}

void Queue::remove()
{
    if (ptr == nullptr)
    {
        cout << "Error: Queue not initialized!\n";
        return;
    }
    if (isEmpty())
    {
        cout << "Error: Queue Underflow! Cannot remove element.\n";
        return;
    }

    cout << ptr[front] << " dequeued.\n";

    if (front == rear) 
    {
        front = rear = -1; 
    }
    else
    {
        front = (front + 1) % capacity; 
    }
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Queue: ";
    int i = front;
    while (true)
    {
        cout << ptr[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % capacity; 
    }
    cout << endl;
}


int main()
{
    Queue q(5);

    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);
    q.insert(50);
    q.display();

    q.remove();
    q.remove();
    q.display();

    q.insert(60);
    q.insert(70);
    q.display();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    return 0;
}
