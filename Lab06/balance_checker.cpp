//Program to check if the paranthesis are balanced
#include "Stack.h"
#include <cstdio>
#include <cstring>

bool isBalanced(const char* expression) {
    Stack stack;
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.isEmpty()) return false;
            char top = stack.peek();
            stack.pop();
            if ((ch == ')' && top != '(') || 
                (ch == ']' && top != '[') || 
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    char expression[100];
    int choice;

    while (true) {
        printf("\nMenu:\n");
        printf("1. Check Balance\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expression: ");
                scanf("%s", expression);
                if (isBalanced(expression)) {
                    printf("Balanced\n");
                } else {
                    printf("Not Balanced\n");
                }
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
