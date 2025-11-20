#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) {
        // Stack overflow, but unlikely for typical expressions
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int is_matching_pair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

int check_balance(char *exp) {
    int i = 0;
    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            if (!is_matching_pair(pop(), exp[i])) return 0;
        }
        i++;
    }
    return (top == -1);
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter an expression with parentheses (e.g., [a+(b*c)]): ");
    scanf("%s", exp);

    if (check_balance(exp)) {
        printf("The expression is Balanced.\n");
    } else {
        printf("The expression is NOT Balanced.\n");
    }
    return 0;
}
