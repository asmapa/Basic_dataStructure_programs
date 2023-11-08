//This is code for evaluating an infix expresssion


#include <stdio.h>
#include <string.h>
#include <ctype.h> // for isdigit
#define MAX 20

// Function to perform postfix expression evaluation
int evaluatePostfix(char postfix[])
{
    int stk[MAX];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            // If it's a digit, convert it to an integer and push onto the stack
            int num = postfix[i] - '0';
            stk[++top] = num;
        }
        else if (postfix[i] == ' ')
        {
            // Skip whitespace
            continue;
        }
        else
        {
            // If it's an operator, pop the top two operands and perform the operation
            int operand2 = stk[top--];
            int operand1 = stk[top--];

            switch (postfix[i])
            {
                case '+':
                    stk[++top] = operand1 + operand2;
                    break;
                case '-':
                    stk[++top] = operand1 - operand2;
                    break;
                case '*':
                    stk[++top] = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0)
                    {
                        printf("Division by zero error.\n");
                        return -1;
                    }
                    stk[++top] = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    return -1;
            }
        }
    }

    // The result will be the top of the stack
    return stk[top];
}

int main()
{
    char postfix[MAX];

    printf("Enter the postfix expression: ");
    gets(postfix);

    int result = evaluatePostfix(postfix);

    if (result != -1)
    {
        printf("Result: %d\n", result);
    }

    return 0;
}
