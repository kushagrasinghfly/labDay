#include <iostream>
using namespace std;

class CircularQueue 
{
private:
    int *arr;
    int front, rear, size;

public:
    
    CircularQueue(int s) 
    {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }
    void enqueue(int value) 
    {
        if ((rear + 1) % size == front) 
        {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) front = 0; 
        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << value << " enqueued\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % size;
        }
    }

    int peek() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() 
    {
        return front == -1;
    }

    void display() 
    {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }
        int i = front;
        cout << "Queue elements: ";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() 
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); 

    q.display();

    q.dequeue();
    q.dequeue();
    
    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();
    cout << "Front element: " << q.peek() << endl;

    return 0;
}


// prog-2
#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the circular linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        head->next = head; // Circular link
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Function to find distance between two elements
int findDistance(Node* head, int key1, int key2) {
    if (!head) return -1;

    Node* temp = head;
    Node* node1 = nullptr;
    Node* node2 = nullptr;
    int index = 0, pos1 = -1, pos2 = -1;

    // Finding positions of key1 and key2
    do {
        if (temp->data == key1) pos1 = index, node1 = temp;
        if (temp->data == key2) pos2 = index, node2 = temp;
        temp = temp->next;
        index++;
    } while (temp != head);

    if (!node1 || !node2) return -1; // If any of the elements are not found

    // Calculate forward distance
    int forwardDist = 0;
    temp = node1;
    while (temp != node2) {
        temp = temp->next;
        forwardDist++;
    }

    // Calculate backward distance
    int backwardDist = 0;
    temp = node2;
    while (temp != node1) {
        temp = temp->next;
        backwardDist++;
    }

    // Return the minimum distance
    return min(forwardDist, backwardDist);
}

// Function to display the circular linked list
void display(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Driver Code
int main() {
    Node* head = nullptr;

    // Creating Circular Linked List
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    display(head);

    int key1 = 10, key2 = 40;
    int distance = findDistance(head, key1, key2);
    
    if (distance != -1)
        cout << "Minimum Distance between " << key1 << " and " << key2 << " is: " << distance << endl;
    else
        cout << "One or both elements not found in the list!" << endl;

    return 0;
}
