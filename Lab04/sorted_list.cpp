//Program to implement merges in a list ADT
#include <cstdio>
#include <cstdlib>

class List {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

    void printReverse(Node* node);

public:
    List() {
        head = NULL;
    }

    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int pos, int value);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    bool search(int value);
    void display();
    void displayReverse();
    void reverseLink();
};

int main() {
    List list;
    int choice, value, pos;
    while (true) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Display Reverse\n");
        printf("10. Reverse Links\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                list.insertBeginning(value);
                list.display();
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                list.insertEnd(value);
                list.display();
                break;
            case 3:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &value);
                list.insertPosition(pos, value);
                list.display();
                break;
            case 4:
                list.deleteBeginning();
                list.display();
                break;
            case 5:
                list.deleteEnd();
                list.display();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                list.deletePosition(pos);
                list.display();
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (list.search(value))
                    printf("Element found in the list.\n");
                else
                    printf("Element not found.\n");
                break;
            case 8:
                list.display();
                break;
            case 9:
                list.displayReverse();
                break;
            case 10:
                list.reverseLink();
                list.display();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void List::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void List::insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void List::insertPosition(int pos, int value) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void List::deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

void List::deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void List::deletePosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("List is empty or invalid position.\n");
        return;
    }
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of bounds.\n");
    } else {
        Node* delNode = temp->next;
        temp->next = delNode->next;
        free(delNode);
    }
}

bool List::search(int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
} 

void List::display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void List::displayReverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printReverse(head);
    printf("NULL\n");
}

void List::printReverse(Node* node) {
    if (node == NULL) return;
    printReverse(node->next);
    printf("%d -> ", node->data);
}

void List::reverseLink() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
