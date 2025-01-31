#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[100]; 
    int size; 

public:
    Stack(int s) 
    { 
        top = -1;
        size = s;
    }

    void push(int value) 
    {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack\n";
    }

    void pop() 
    {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    void peek() 
    {
        if (isEmpty()) {
            cout << "Stack is empty, nothing at the top.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the stack: ";
    cin >> size;
    
    Stack s(size);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is Not Empty\n");
                break;
            case 5:
                cout << (s.isFull() ? "Stack is Full\n" : "Stack is Not Full\n");
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
