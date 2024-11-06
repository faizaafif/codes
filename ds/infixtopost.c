#include <stdio.h>

#define MAX 100

void push(char* stack, int* top, char n) {
    if (*top < MAX - 1) {
        stack[++(*top)] = n;
    } else {
        printf("Stack overflow\n");
    }
}


char pop(char* stack, int* top) {
    if (*top >= 0) {
        return stack[(*top)--];
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}


int isEmpty(int* top) {
    return *top == -1;
}

char peek(char* stack, int* top) {
    if (*top >= 0) {
        return stack[*top];
    } else {
        return '\0';
    }
}

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1;
    char* i = infix;
    char* k = postfix;

    while (*i != '\0') {
        if (isOperand(*i)) {
            *k = *i;
            k++;
        }
        else if (*i == '(') {
            push(stack, &top, *i);
        }
        else if (*i == ')') {
            while (!isEmpty(&top) && peek(stack, &top) != '(') {
                *k = pop(stack, &top);
                k++;
            }
            pop(stack, &top);
        }
        else {
            while (!isEmpty(&top) && precedence(*i) <= precedence(peek(stack, &top))) {
                *k = pop(stack, &top);
                k++;
            }
            push(stack, &top, *i);
        }
        i++;
    }

    while (!isEmpty(&top)) {
        *k = pop(stack, &top);
        k++;
    }

    *k = '\0'; 
}

int main() {
    char infix[] = "((a+b)*c/(d-f))";
    char postfix[MAX];

    infixToPostfix(infix, postfix);

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
