//Program to implement stack
#include <cstdlib>
#include <cstdio>

class Stack {
private:
    struct Node {
        char data;   
        Node* next;  
    };
    Node* top; 
public:
    Stack() {
        top = nullptr;  
    }

    // Function declarations
    void push(char value);
    void pop();
    void peek();
    bool isEmpty();
};

int main() {
    Stack stack;
    char value;
    int choice;

    while (true) {
        // Display the menu
        printf("\nStack Operations Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push operation
                printf("Enter character to push: ");
                scanf(" %c", &value);  // Take character input
                stack.push(value);
                break;
            case 2:  // Pop operation
                if (stack.isEmpty()) {
                    printf("Stack is empty. Cannot pop element.\n");
                } else {
                    stack.pop();
                }
                break;
            case 3:  // Peek operation
                stack.peek();
                break;
            case 4:  // Exit
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function definitions
//Function to push to stack
void Stack::push(char value) {
    Node* newNode = new Node;  
    newNode->data = value;    
    newNode->next = top;       
    top = newNode;            
    printf("Pushed '%c' onto stack.\n", value);
}
//Function to pop from stack
void Stack::pop() {
    Node* temp = top;        
    top = top->next;          
    printf("Popped '%c' from stack.\n", temp->data);
    delete temp;             
}
//Function to peek stack
void Stack::peek() {
    if (isEmpty()) {
        printf("Stack is empty. No elements to peek.\n");
    } else {
        printf("Top element is '%c'.\n", top->data);
    }
}

bool Stack::isEmpty() {
    return top == nullptr;  
}
