#include <iostream>             // Allows input/output operations
using namespace std;            // Gives access to standard library names

// Structure for a node of the linked list
struct Node {
    int data;                   // Value stored in this node
    Node* next;                 // Pointer to the next node in the list
};

// Global pointer to the first node of the list
Node* head = NULL;              // Starts as empty list

// Function to add a node at the beginning
void addAtBeginning(int value) {
    Node* newNode = new Node;   // Create a new node
    newNode->data = value;      // Put the value in the new node
    newNode->next = head;       // Link new node to the former head
    head = newNode;             // New node becomes the new head
}

// Function to add a node at the end (tail)
void addAtEnd(int value) {
    Node* newNode = new Node;   // Create a new node
    newNode->data = value;      // Assign value
    newNode->next = NULL;       // Last node always points to NULL

    if (head == NULL) {         // If list is empty
        head = newNode;         // New node becomes the first node
        return;                 // Exit the function
    }

    Node* temp = head;          // Start from the head
    while (temp->next != NULL)  // Move until last node
        temp = temp->next;      

    temp->next = newNode;       // Attach new node at the end
}

// Function to add a node in the middle (after a certain value)
void addAfterValue(int target, int newValue) {
    Node* temp = head;          // Start from the head

    while (temp != NULL && temp->data != target)  
        temp = temp->next;      // Search for the target value

    if (temp == NULL) {         // If value not found
        cout << "Value not found!\n";  
        return;
    }

    Node* newNode = new Node;   // Create new node
    newNode->data = newValue;   // Assign new value
    newNode->next = temp->next; // Link new node to the rest of the list
    temp->next = newNode;       // Insert new node after target
}

// Function to display all values in the list
void displayList() {
    Node* temp = head;          // Start from first node

    while (temp != NULL) {      // Loop until end of list
        cout << temp->data << " ";  
        temp = temp->next;      
    }
    cout << endl;               // New line after printing list
}

// Function to remove node from beginning
void removeBeginning() {
    if (head == NULL) return;   // If list is empty, nothing to remove

    Node* temp = head;          // Store current head
    head = head->next;          // Move head to next node
    delete temp;                // Delete old node
}

// Function to remove node from end (tail)
void removeEnd() {
    if (head == NULL) return;   // Empty list
    if (head->next == NULL) {   // Only one node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;          // Start from head
    while (temp->next->next != NULL)  
        temp = temp->next;      // Stop at the second last node

    delete temp->next;          // Delete last node
    temp->next = NULL;          // Make new last node point to NULL
}

// Function to remove a node in middle (by value)
void removeByValue(int value) {
    if (head == NULL) return;   // Empty list
    if (head->data == value) {  // First node is the target
        removeBeginning();      
        return;
    }

    Node* temp = head;          // Start from head
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;      // Search for the node BEFORE target

    if (temp->next == NULL) {   // Value not found
        cout << "Value not found!\n";
        return;
    }

    Node* toDelete = temp->next; // Node to be deleted
    temp->next = temp->next->next; // Bypass the node
    delete toDelete;               // Free memory
}

// Function to replace a value in the list
void replaceValue(int oldVal, int newVal) {
    Node* temp = head;          // Start from head
    while (temp != NULL && temp->data != oldVal)
        temp = temp->next;      // Search for value

    if (temp == NULL) {         // If not found
        cout << "Value not found!\n";
        return;
    }

    temp->data = newVal;        // Replace value
}

// Function to count nodes in the list
int countNodes() {
    int count = 0;              // Counter variable
    Node* temp = head;          // Start from head

    while (temp != NULL) {      // Loop through list
        count++;                // Increase count
        temp = temp->next;      // Move to next node
    }
    return count;               // Return total
}

// Function to reverse the linked list
void reverseList() {
    Node* prev = NULL;          // Will become new head
    Node* curr = head;          // Start with current node
    Node* next = NULL;          // Used to save next node

    while (curr != NULL) {      // Loop until end
        next = curr->next;      // Save next node
        curr->next = prev;      // Reverse pointer
        prev = curr;            // Move prev forward
        curr = next;            // Move curr forward
    }

    head = prev;                // New head is last visited node
}

int main() {
    addAtBeginning(10);         // Add 10 at start
    addAtEnd(20);               // Add 20 at end
    addAtEnd(30);               // Add 30 at end
    addAfterValue(20, 25);      // Insert 25 after 20

    displayList();              // Show list: 10 20 25 30

    removeBeginning();          // Remove first node
    removeEnd();                // Remove last node

    displayList();              // Show updated list

    replaceValue(25, 100);      // Replace 25 with 100

    cout << "Number of nodes: " << countNodes() << endl;

    reverseList();              // Reverse the list

    displayList();              // Show reversed list

    return 0;                   // End of program
}
