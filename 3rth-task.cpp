#include <iostream>                 // Allows input/output operations
using namespace std;                // Allows using standard names easily

// Structure for a node in the linked list stack
struct Node {
    int data;                       // Value stored in node
    Node* next;                     // Pointer to the next node
};

// Top pointer (points to the top of the stack)
Node* topStack = NULL;              // Initially stack is empty

// Function to check if stack is empty
bool isEmpty() {
    return topStack == NULL;        // If top is NULL ? stack is empty
}

// Function to count number of elements in the stack
int countStack() {
    int count = 0;                  // Counter starts at 0
    Node* temp = topStack;          // Start from top element

    while (temp != NULL) {          // Traverse stack
        count++;                    // Increase count
        temp = temp->next;          // Move to next node
    }

    return count;                   // Return total number
}

// Function to push (add) a new value to the top of stack
void push(int value) {
    Node* newNode = new Node;       // Create a new node
    newNode->data = value;          // Assign value to node
    newNode->next = topStack;       // New node points to old top
    topStack = newNode;             // New node becomes the new top
}

// Function to pop (remove) the top element
void pop() {
    if (isEmpty()) {                // If no elements to remove
        cout << "Stack is empty!" << endl;
        return;
    }

    Node* temp = topStack;          // Store current top
    topStack = topStack->next;      // Move top pointer to next node
    delete temp;                    // Delete old top
}

// Function to return the top value without removing it
int peek() {
    if (isEmpty()) {                // If stack is empty
        cout << "Stack is empty!" << endl;
        return -1;                  // Return error value
    }
    return topStack->data;          // Return value of top node
}

// Function to reverse the stack values
void reverseStack() {
    Node* prev = NULL;              // Pointer to previous node
    Node* curr = topStack;          // Pointer to current node
    Node* next = NULL;              // Pointer to next node

    while (curr != NULL) {          // Loop until end of stack
        next = curr->next;          // Save next node
        curr->next = prev;          // Reverse pointer direction
        prev = curr;                // Move prev forward
        curr = next;                // Move curr forward
    }

    topStack = prev;                // Last visited node becomes new top
}

// Function to display all stack values
void displayStack() {
    Node* temp = topStack;          // Start from top

    while (temp != NULL) {          // Traverse stack
        cout << temp->data << " ";  // Print value
        temp = temp->next;          // Move to next
    }
    cout << endl;                   // New line after printing
}

int main() {

    push(10);                       // Push 10
    push(20);                       // Push 20
    push(30);                       // Push 30

    cout << "Stack: ";
    displayStack();                 // Output ? 30 20 10

    cout << "Top element: " << peek() << endl;

    pop();                          // Remove top element (30)

    cout << "Stack after pop: ";
    displayStack();                 // Output ? 20 10

    cout << "Number of elements: " << countStack() << endl;

    reverseStack();                 // Reverse the stack

    cout << "Stack after reversing: ";
    displayStack();                 // Output ? 10 20

    return 0;                       // End program
}
