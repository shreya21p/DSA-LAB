//Program to implememnt stack ADT using array
#include <cstdlib>
#include <cstdio>

class Stack {
private:
    char stack[5];  
    int top;        

public:
    Stack() {
        top = -1;  
    }

   
    void push(char value);
    void pop();
    void peek();
    bool isEmpty();
    bool isFull();
};

int main() {
    Stack stack;
    char value;
    int choice;

    while (true) {
        
        printf("\nStack Operations Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  
                if (stack.isFull()) {
                    printf("Stack is full. Cannot push new element.\n");
                } else {
                    printf("Enter character to push: ");
                    scanf(" %c", &value);  
                    stack.push(value);
                }
                break;
            case 2:  
                if (stack.isEmpty()) {
                    printf("Stack is empty. Cannot pop element.\n");
                } else {
                    stack.pop();
                }
                break;
            case 3: 
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
    stack[++top] = value;  
    printf("Pushed '%c' onto stack.\n", value);
}
//Function to pop from stack
void Stack::pop() {
    char poppedValue = stack[top--];  
    printf("Popped '%c' from stack.\n", poppedValue);
}
//Function to peek from stack
void Stack::peek() {
    if (isEmpty()) {
        printf("Stack is empty. No elements to peek.\n");
    } else {
        printf("Top element is '%c'.\n", stack[top]);
    }
}
//Function to check if stack is empty
bool Stack::isEmpty() {
    return top == -1;  
}
//Function to check if stack is full
bool Stack::isFull() {
    return top == 4;  
}
