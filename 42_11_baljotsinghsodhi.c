#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Error: Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluate_postfix(char *exp) {
    int i = 0, op1, op2, result;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (exp[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    // Simple integer power (assuming a small, positive exponent)
                    result = 1;
                    for (int k = 0; k < op2; k++) result *= op1;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter a POSTFIX expression (single-digit operands 0-9): ");
    scanf("%s", exp);

    int result = evaluate_postfix(exp);
    printf("Result of the expression: %d\n", result);
    return 0;
}
