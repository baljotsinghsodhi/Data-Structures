#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infix_to_postfix(char *infix) {
    char postfix[MAX_SIZE];
    int i = 0, j = 0;
    char next_char;
    
    printf("Postfix expression: ");
    while (infix[i] != '\0') {
        next_char = infix[i];
        if (isalnum(next_char)) {
            postfix[j++] = next_char;
            printf("%c", next_char);
        } else if (next_char == '(') {
            push(next_char);
        } else if (next_char == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
                printf("%c", postfix[j - 1]);
            }
            if (top != -1 && stack[top] == '(') pop();
        } else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(next_char)) {
                postfix[j++] = pop();
                printf("%c", postfix[j - 1]);
            }
            push(next_char);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
        printf("%c", postfix[j - 1]);
    }
    postfix[j] = '\0';
    printf("\n");
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter an infix expression (operands: a-z, A-Z, 0-9; operators: +,-,*,/,^): ");
    scanf("%s", infix);
    
    infix_to_postfix(infix);
    return 0;
}
