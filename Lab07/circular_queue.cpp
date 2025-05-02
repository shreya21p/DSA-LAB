//Implementation of circular queue using array
#include <stdio.h>
#define SIZE 5
class CircularQueue {
private:
    int queue[SIZE];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    void enqueue();
    void dequeue();
    void peek();
    void display();
};
int main() {
    CircularQueue cq;
    int choice;
    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            cq.enqueue();
        } 
        else if (choice == 2) {
            cq.dequeue();
        } 
        else if (choice == 3) {
            cq.peek();
        } 
        else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } 
        else {
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}

// Function to insert an element into the circular queue
void CircularQueue::enqueue() {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow! Cannot enqueue.\n");
        return;
    }
    int value;
    printf("Enter integer to enqueue: ");
    scanf("%d", &value);
    if (front == -1) front = 0;  
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d enqueued to circular queue.\n", value);
}
// Function to remove an element from the circular queue
void CircularQueue::dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from circular queue.\n", queue[front]);
    if (front == rear) {  // If only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}
// Function to display the front element of the circular queue
void CircularQueue::peek() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}
//Function to display all elements in the circular queue
void CircularQueue::display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (true) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE; 
    }
    printf("\n");
}
