// Stack header file
#ifndef STACK_H
#define STACK_H

#include <cstdio>
#include <cstdlib>

class Stack {
private:
    struct Node {
        char data;   // Data of type character
        Node* next;  // Pointer to the next node
    };
    Node* top;  // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr;  // Initialize top as nullptr (empty stack)
    }

    // Function declarations
    void push(char value);
    void pop();
    char peek();
    bool isEmpty();
};

void Stack::push(char value) {
    Node* newNode = new Node;  // Create a new node
    newNode->data = value;     // Assign value to the new node
    newNode->next = top;       // Link new node to the previous top node
    top = newNode;             // Update top to the new node
}

void Stack::pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop element.\n");
        return;
    }
    Node* temp = top;         // Temporary pointer to the top node
    top = top->next;          // Move the top pointer to the next node
    delete temp;              // Delete the popped node
}

char Stack::peek() {
    if (isEmpty()) {
        printf("Stack is empty. No elements to peek.\n");
        return '\0';
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;  // Stack is empty if top is nullptr
}

#endif // STACK_H
