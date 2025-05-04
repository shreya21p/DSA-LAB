//Implementation of queue using array
#include <stdio.h>
#define SIZE 5
class Queue {
private:
    int queue[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
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
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n5. Exit\n4. Display\n");
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
        else if (choice == 5) {
            printf("Exiting program.\n");
            break;
        } 
        else if (choice==4){
            q.display();
        }
        else {
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
// Function to insert an element into the queue
void Queue::enqueue() {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot enqueue.\n");
        return;
    }
    int value;
    printf("Enter integer to enqueue: ");
    scanf("%d", &value);
    if (front == -1) front = 0;  
    queue[++rear] = value;
    
    printf("%d enqueued to queue.\n", value);
}
// Function to remove an element from the queue
void Queue::dequeue() {
    if (front == -1 ) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue[front++]);
    if (front > rear) {
        front = rear = -1;
    }
}
// Function to display the front element of the queue
void Queue::peek() {
    if (front == -1 ) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}
// Function to display all elements in the queue
void Queue::display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
