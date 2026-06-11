#include <iostream>
using namespace std;

// Abstract Base Class to demonstrate Inheritance and Polymorphism
class IStack {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual int top() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void displayTop() = 0;
    virtual ~IStack() {}
};

// Derived Class representing the Stack 
class Stack : public IStack {
private:
    // Encapsulation: making data members private  
    int* arr;
    int capacity;
    int topIndex;

public:
    // Constructor
    Stack(int size = 100) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int value) override {
        if (isFull()) {
            cout << "Stack is Full! Cannot push " << value << "." << endl;
            return;
        }
        arr[++topIndex] = value;
        cout << "Pushed " << value << " to the stack." << endl;
    }

    // Pop an element from the stack
    void pop() override {
        if (isEmpty()) {
            cout << "Stack is Empty! Cannot pop." << endl;
            return;
        }
        cout << "Popped " << arr[topIndex--] << " from the stack." << endl;
    }

    // Return the top element
    int top() override {
        if (isEmpty()) {
            return -1; // Assuming -1 means error/empty in this context
        }
        return arr[topIndex];
    }

    // Display the top element without removing it
    void displayTop() override {
        if (isEmpty()) {
            cout << "Stack is Empty! No top element." << endl;
        } else {
            cout << "Top element is: " << top() << endl;
        }
    }

    // Check if the stack is empty
    bool isEmpty() override {
        return topIndex == -1;
    }

    // Check if the stack is full
    bool isFull() override {
        return topIndex == capacity - 1;
    }
};

int main() {
    cout << "=== Escalator: Stack Implementation ===" << endl;
    
    // Demonstrating Polymorphism using a base class pointer
    int stackSize;
    cout << "Enter the maximum size of the stack: ";
    cin >> stackSize;
    
    IStack* stackPtr = new Stack(stackSize);

    int choice;
    int value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Display the top element\n";
        cout << "4. Check if the stack is empty\n";
        cout << "5. Check if the stack is full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stackPtr->push(value);
                break;
            case 2:
                stackPtr->pop();
                break;
            case 3:
                stackPtr->displayTop();
                break;
            case 4:
                if (stackPtr->isEmpty()) {
                    cout << "The stack is empty." << endl;
                } else {
                    cout << "The stack is not empty." << endl;
                }
                break;
            case 5:
                if (stackPtr->isFull()) {
                    cout << "The stack is full." << endl;
                } else {
                    cout << "The stack is not full." << endl;
                }
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    delete stackPtr;
    return 0;
}
