//Implement a queue using linked list
#include <stdio.h>
#include <stdlib.h>
class Queue {
private:
    struct Node { 
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue();
    void dequeue();
    void peek();
    void display();
};
int main() {
    Queue q;
    int choice;
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            q.enqueue();
        } 
        else if (choice == 2) {
            q.dequeue();
        } 
        else if (choice == 3) {
            q.peek();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
// Function to insert an element into the queue
void Queue::enqueue() {
    int value;
    printf("Enter integer to enqueue: ");
    scanf("%d", &value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) { 
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue.\n", value);
}
// Function to remove an element from the queue
void Queue::dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    Node* temp = front;
    printf("%d dequeued from queue.\n", temp->data);
    front = front->next;
    if (front == NULL) { 
        rear = NULL;
    }
    free(temp);
}
// Function to display the front element of the queue
void Queue::peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}
// Function to display all elements in the queue
void Queue::display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
