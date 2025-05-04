//header file
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

//Creating class for linked list
class LinkedList {
private:
    //Creating a structure for node
    struct Node {
        int data;
        struct Node* next;
    };
    struct Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    struct Node* gethead() {
        return head;
    }
    void insertAscending(int value); 
    static LinkedList mergeSorted(LinkedList& list1, LinkedList& list2);
    void display();
};


//function to insert nodes in ascending order
void LinkedList :: insertAscending(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

//merging 2 linked list in another list
LinkedList  LinkedList :: mergeSorted(LinkedList& list1, LinkedList& list2) {
    LinkedList mergedList;
    struct Node* head1 = list1.gethead();
    struct Node* head2 = list2.gethead();
    struct Node** tail = &(mergedList.head);

    while (head1 && head2) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (head1->data <= head2->data) {
            newNode->data = head1->data;
            head1 = head1->next;
        } else {
            newNode->data = head2->data;
            head2 = head2->next;
        }
        newNode->next = NULL;
        *tail = newNode;
        tail = &((*tail)->next);
    }

    while (head1) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head1->data;
        newNode->next = NULL;
        *tail = newNode;
        tail = &((*tail)->next);
        head1 = head1->next;
    }

    while (head2) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head2->data;
        newNode->next = NULL;
        *tail = newNode;
        tail = &((*tail)->next);
        head2 = head2->next;
    }

    return mergedList;
}

//display function
void LinkedList :: display() {
    struct Node* current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

#endif
