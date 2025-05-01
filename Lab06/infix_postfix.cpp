#include "Stack.h"
#include <cstdio>
#include <cctype>
#include <cstring>

int precedence(char op) {
    if (op == '(' || op == '[' || op == '{') return 0; // Parentheses have the lowest precedence
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3; // Exponentiation has higher precedence
    if (op == '&') return 4; // Bitwise AND
    if (op == '|') return 5; // Bitwise OR
    if (op == '<' || op == '>' || op == '=' || op == '!') return 6; // Relational and equality operators
    if (op == '?') return 7; // Ternary conditional operator
    return -1; // Default for unknown operators
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            while (!stack.isEmpty() && stack.peek() != '(' && stack.peek() != '[' && stack.peek() != '{') {
                postfix[j++] = stack.peek();
                stack.pop();
            }
            stack.pop(); // Pop the opening parenthesis
        } else {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix[j++] = stack.peek();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.isEmpty()) {
        postfix[j++] = stack.peek();
        stack.pop();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(const char* postfix) {
    Stack stack;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else {
            int val1 = stack.peek(); stack.pop();
            int val2 = stack.peek(); stack.pop();
            switch (ch) {
                case '+': stack.push(val2 + val1); break;
                case '-': stack.push(val2 - val1); break;
                case '*': stack.push(val2 * val1); break;
                case '/': stack.push(val2 / val1); break;
                case '%': stack.push(val2 % val1); break;
                case '^': stack.push(val2 ^ val1); break;
                case '&': stack.push(val2 & val1); break;
                case '|': stack.push(val2 | val1); break;
                // Add more cases for other operators if needed
            }
        }
    }
    return stack.peek();
}

int main() {
    char infix[100], postfix[100];
    int choice;

    while (true) {
        printf("\nMenu:\n");
        printf("1. Get Infix\n");
        printf("2. Convert Infix to Postfix\n");
        printf("3. Evaluate Postfix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                break;
            case 2:
                infixToPostfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;
            case 3: {
                int result = evaluatePostfix(postfix);
                printf("Result: %d\n", result);
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
