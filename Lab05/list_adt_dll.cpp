//Program to implement list ADT doubly linked list  #include <stdio.h>
#include <stdlib.h>

class listADT {
    struct node {
        int data;
        struct node *next;
        struct node *prev;
    } *head, *tail;

public:
    listADT();
    void insertbeg(int val);
    void insertend(int val);
    void insertpos(int pos, int val);
    void display();
    void displayrev();
    int search(int val);
    int delbeg();
    int delend();
    int delpos(int pos);
};

listADT::listADT() {
    head = tail = NULL;
}

int main() {
    listADT mylist;
    int choice, pos, val;

    while (1) {
        printf("\nMENU\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Delete at beginning\n");
        printf("7. Delete at end\n");
        printf("8. Delete at position\n");
        printf("9. Display in reverse\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                mylist.insertbeg(val);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                mylist.insertend(val);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                mylist.insertpos(pos, val);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &val);
                pos = mylist.search(val);
                if (pos != -1)
                    printf("Index is %d of element %d\n", pos, val);
                else
                    printf("Value is not present in list\n");
                break;
            case 5:
                mylist.display();
                break;
            case 6:
                val = mylist.delbeg();
                if (val != -1)
                    printf("Value deleted is %d\n", val);
                break;
            case 7:
                val = mylist.delend();
                if (val != -1)
                    printf("Value deleted is %d\n", val);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                val = mylist.delpos(pos);
                if (val != -1)
                    printf("Value deleted is %d\n", val);
                break;
            case 9:
                mylist.displayrev();
                break;
            case 10:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Insert at beginning
void listADT::insertbeg(int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    else
        tail = newnode;
    head = newnode;
}

// Display list
void listADT::display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at end
void listADT::insertend(int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = tail;
    if (tail != NULL)
        tail->next = newnode;
    else
        head = newnode;
    tail = newnode;
}

// Delete from beginning
int listADT::delbeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    struct node *temp = head;
    int data = temp->data;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    free(temp);
    return data;
}

// Delete from end
int listADT::delend() {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    struct node *temp = tail;
    int data = tail->data;
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;
    free(temp);
    return data;
}

// Search for an element
int listADT::search(int val) {
    struct node *temp = head;
    int index = 1;
    while (temp != NULL) {
        if (temp->data == val)
            return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

// Insert at a specific position
void listADT::insertpos(int pos, int val) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertbeg(val);
        return;
    }
    struct node *temp = head;
    while (--pos > 1 && temp != NULL)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid range\n");
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    else
        tail = newnode;
    temp->next = newnode;
}

// Display list in reverse
void listADT::displayrev() {
    struct node *temp = tail;
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Delete at a specific position
int listADT::delpos(int pos) {
    if (pos < 1 || head == NULL)
        return -1;
    struct node *temp = head;
    while (--pos > 0 && temp != NULL)
        temp = temp->next;
    if (temp == NULL)
        return -1;
    int data = temp->data;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;
    free(temp);
    return data;
}
