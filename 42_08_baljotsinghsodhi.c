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

// Low precedence for operators to ensure right-to-left associativity for all
// when converted to postfix (a requirement for infix-to-prefix)
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

void swap_parentheses(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void infix_to_prefix(char *infix) {
    char temp_exp[MAX_SIZE];
    char post[MAX_SIZE];
    int i, j = 0;
    
    strcpy(temp_exp, infix);
    reverse_string(temp_exp);
    swap_parentheses(temp_exp);

    i = 0;
    while (temp_exp[i] != '\0') {
        char next_char = temp_exp[i];
        if (isalnum(next_char)) {
            post[j++] = next_char;
        } else if (next_char == '(') {
            push(next_char);
        } else if (next_char == ')') {
            while (top != -1 && stack[top] != '(') {
                post[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') pop();
        } else { // Operator
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(next_char)) {
                post[j++] = pop();
            }
            push(next_char);
        }
        i++;
    }

    while (top != -1) {
        post[j++] = pop();
    }
    post[j] = '\0';

    reverse_string(post);
    printf("Prefix expression: %s\n", post);
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter an infix expression (operands: a-z, A-Z, 0-9; operators: +,-,*,/,^): ");
    scanf("%s", infix);
    
    infix_to_prefix(infix);
    return 0;
}
