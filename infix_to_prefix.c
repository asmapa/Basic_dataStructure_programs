#include <stdio.h>
#include <string.h>
#include "ctype.h"

#define MAX_STACK_SIZE 100

char operatorStack[MAX_STACK_SIZE];
int top = -1;

void push(char value) {
    if (top < MAX_STACK_SIZE - 1) {
        operatorStack[++top] = value;
    }
}

char pop() {
    if (top >= 0) {
        return operatorStack[top--];
    }
}

int isEmpty() {
    return top == -1;
}

int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0; // For other characters
    }
}

void reverseString(char str[]) {
    int length = strlen(str);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void reverseParentheses(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) { // Operand
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (!isEmpty() && operatorStack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '('
        } else { // Operator
            while (!isEmpty() && getPrecedence(token) <= getPrecedence(operatorStack[top])) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

/*int priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
    return 0;
}*/


/*void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_STACK_SIZE];
    int top = -1;
    int i = 0;
    int k = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[k] = infix[i];
            k++;
            i++;
        } else if (infix[i] == '(') {
            push(infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[k] = pop();
                k++;
            }
            pop(stack, &top);
            i++;
        } else {
            while (top != -1 && stack[top] != '(' && priority(infix[i]) <= priority(stack[top])) {
                postfix[k] = pop(stack, &top);
                k++;
            }
            push(infix[i]);
            i++;
        }
    }
    while (top != -1) {
        postfix[k] = pop();
        k++;
    }
    postfix[k] = '\0';
}*/

int main() {
    char infix[100], postfix[100], prefix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Step 1: Reverse the infix expression
    reverseParentheses(infix);
    reverseString(infix);

    // Step 2: Convert the reversed infix to postfix
    infixToPostfix(infix, postfix);

    // Step 3: Reverse the postfix to get the prefix
    reverseString(postfix);

    strcpy(prefix, postfix); // The reversed postfix is the prefix

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
