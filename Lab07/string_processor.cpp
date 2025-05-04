//Program to manipulate string using queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the singly linked list
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to enqueue a character
void enqueue(Queue* q, char data) {
    Node* newNode = createNode(data);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue a character
char dequeue(Queue* q) {
    if (isEmpty(q)) {
        return '\0'; // Empty queue
    }
    Node* temp = q->front;
    char data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to process the input string
void processString(char* input, char* output) {
    Queue q;
    initializeQueue(&q);

    // Temporary queue to store characters
    Queue tempQueue;
    initializeQueue(&tempQueue);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+') {
            // Remove the last non-'+' character from the queue
            if (!isEmpty(&q)) {
                // Dequeue all characters except the last one
                while (q.front != q.rear) {
                    enqueue(&tempQueue, dequeue(&q));
                }
                // Discard the last character
                dequeue(&q);

                // Move characters back from tempQueue to q
                while (!isEmpty(&tempQueue)) {
                    enqueue(&q, dequeue(&tempQueue));
                }
            }
        } else {
            // Enqueue the character
            enqueue(&q, input[i]);
        }
    }

    // Construct the output string from the queue
    int index = 0;
    while (!isEmpty(&q)) {
        output[index++] = dequeue(&q);
    }
    output[index] = '\0'; // Null-terminate the string
}

int main() {
    char input[100];
    char output[100];

    // Take input from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Process the input string
    processString(input, output);

    // Print the output
    printf("Output: %s\n", output);

    return 0;
}
