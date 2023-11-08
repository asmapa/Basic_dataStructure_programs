//infix to postfix without sing stack push and pop operatins

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    }
    return 0;  // Default precedence for non-operators
}

void infixToPostfix(char infix[], char postfix[], int size) {
    char stack[size];
    int top = -1;
    int postfixIndex = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[postfixIndex++] = token;
        } else if (token == '(') {
            stack[++top] = token;
        } else if (token == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[postfixIndex++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(token)) {
                postfix[postfixIndex++] = stack[top--];
            }
            stack[++top] = token;
        }
    }

    while (top >= 0) {
        postfix[postfixIndex++] = stack[top--];
    }

    postfix[postfixIndex] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix, sizeof(postfix));

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
