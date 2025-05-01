//Program to implement list ADT using circular linked list
#include <cstdio>
#include <cstdlib>

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    CircularLinkedList();  
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int value, int pos);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    bool search(int value);
    void display();
};

int main() {
    CircularLinkedList list;
    int choice, value, pos;

    do {
        printf("\nCircular Linked List Menu\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                list.insertBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                list.insertEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                list.insertPosition(value, pos);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                list.deletePosition(pos);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (list.search(value))
                    printf("Value found in the list.\n");
                else
                    printf("Value not found.\n");
                break;
            case 8:
                list.display();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 9);

    return 0;
}

// Constructor
CircularLinkedList::CircularLinkedList() : head(nullptr) {}

// Insert at the beginning
void CircularLinkedList::insertBeginning(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Insert at the end
void CircularLinkedList::insertEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

// Insert at a specific position
void CircularLinkedList::insertPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertBeginning(value);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head && pos != 2) {
        printf("Position out of bounds!\n");
        return;
    }

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}

// Delete from the beginning
void CircularLinkedList::deleteBeginning() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    if (head->next == head) {  
        head = nullptr;
    } else {
        Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
    }
    delete temp;
}

// Delete from the end
void CircularLinkedList::deleteEnd() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    if (head->next == head) {  
        delete head;
        head = nullptr;
        return;
    }
    Node* prev = nullptr;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    delete temp;
}

// Delete at a specific position
void CircularLinkedList::deletePosition(int pos) {
    if (!head || pos < 1) {
        printf("Invalid position or empty list!\n");
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && pos > 2) {
        printf("Position out of bounds!\n");
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Search for an element
bool CircularLinkedList::search(int value) {
    if (!head) return false;
    Node* temp = head;
    do {
        if (temp->data == value)
            return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

// Display the list
void CircularLinkedList::display() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
