#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next; // next node
    
    // Constructor for Node
    Node(int val) : data(val), next(nullptr) {}
};

// Base Class: Dynamic Memory Allocation
class DynamicMemoryAllocation {
private:
    Node* Head; // Head pointer attribute

public:
    // Constructor
    DynamicMemoryAllocation() {
        Head = nullptr;
    }

    // Destructor to free dynamically allocated memory
    ~DynamicMemoryAllocation() {
        Node* current = Head;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        Head = nullptr;
    }

    // Basic Linked List Implementation: append()
    void append(int data) {
        Node* newNode = new Node(data); // New node
        if (Head == nullptr) {
            Head = newNode;
            return;
        }
        Node* temp = Head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Basic Linked List Implementation: display()
    void display() {
        if (Head == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }
        Node* temp = Head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Insert at Beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data); // New node
        newNode->next = Head; // point new node to current head
        Head = newNode; // update head
    }

    // Search Operation
    bool Search(int key) {
        Node* temp = Head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << position << "." << endl;
                return true;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element " << key << " not found in the list." << endl;
        return false;
    }

    // Deletion of a Node by value
    void Delete_node(int key) {
        if (Head == nullptr) {
            cout << "List is empty. Deletion failed." << endl;
            return;
        }

        // If head node itself holds the key
        if (Head->data == key) {
            Node* temp = Head;
            Head = Head->next;
            delete temp;
            cout << "Node with value " << key << " deleted." << endl;
            return;
        }

        // Search for the key to be deleted, keep track of previous node
        Node* temp = Head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == nullptr) {
            cout << "Node with value " << key << " not found. Deletion failed." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp;
        cout << "Node with value " << key << " deleted." << endl;
    }

    // Reversing the Linked List
    void reverse() {
        Node* prev = nullptr;
        Node* current = Head;
        Node* next_node = nullptr;

        while (current != nullptr) {
            // Store next
            next_node = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead
            prev = current;
            current = next_node;
        }
        Head = prev;
        cout << "Linked list reversed successfully." << endl;
    }
};

int main() {
    DynamicMemoryAllocation list;

    cout << "--- Dynamic Memory Allocation: Linked List Operations ---" << endl;

    // 1. Basic Linked List Implementation
    cout << "\n1. Appending elements (10, 20, 30)..." << endl;
    list.append(10);
    list.append(20);
    list.append(30);
    list.display();

    // 2. Insert at Beginning & Search Operation
    cout << "\n2. Inserting at beginning (5)..." << endl;
    list.insert_at_beginning(5);
    list.display();

    cout << "\nSearching for elements..." << endl;
    list.Search(20);
    list.Search(100);

    // 3. Deletion of a Node
    cout << "\n3. Deleting node (20)..." << endl;
    list.Delete_node(20);
    list.display();
    
    cout << "Attempting to delete non-existent node (50)..." << endl;
    list.Delete_node(50); // Not found case

    // 4. Reversing the Linked List
    cout << "\n4. Reversing the list..." << endl;
    list.reverse();
    list.display();

    return 0;
}
