//Program to implement merge operations 
#include <stdio.h>
#include "list.h"

int main() {
    LinkedList list1, list2, mergedList;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert into List1\n");
        printf("2. Insert into List2\n");
        printf("3. Merge List1 and List2 into List3\n");
        printf("4. Display Lists\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for List1: ");
                scanf("%d", &value);
                list1.insertAscending(value);
                break;
            case 2:
                printf("Enter value for List2: ");
                scanf("%d", &value);
                list2.insertAscending(value);
                break;
            case 3:
                mergedList = LinkedList::mergeSorted(list1, list2);
                printf("Lists Merged!\n");
                break;
            case 4:
                printf("List1: ");
                list1.display();
                printf("List2: ");
                list2.display();
                printf("Merged List: ");
                mergedList.display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
