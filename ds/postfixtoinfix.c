#include <stdio.h>

#define MAX 100

void push(char stack[][MAX], int* top, char* expr) {
    if (*top < MAX - 1) {
        (*top)++;
        int i = 0;
        while (expr[i] != '\0') {
            stack[*top][i] = expr[i];
            i++;
        }
        stack[*top][i] = '\0';
    } else {
        printf("Stack overflow\n");
    }
}

void pop(char stack[][MAX], int* top, char* expr) {
    if (*top >= 0) {
        int i = 0;
        while (stack[*top][i] != '\0') {
            expr[i] = stack[*top][i];
            i++;
        }
        expr[i] = '\0';
        (*top)--;
    } else {
        printf("Stack underflow\n");
    }
}

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

void postfixToInfix(char* postfix, char* infix) {
    char stack[MAX][MAX];
    int top = -1;
    char* i = postfix;
    char operand1[MAX], operand2[MAX], expr[MAX];

    while (*i != '\0') {
        if (isOperand(*i)) {
            char operand[2] = {*i, '\0'};
            push(stack, &top, operand);
        } 
        else { 
            pop(stack, &top, operand2);
            pop(stack, &top, operand1);

            int j = 0;
            expr[j++] = '(';
            int k = 0;
            while (operand1[k] != '\0') {
                expr[j++] = operand1[k++];
            }
            expr[j++] = *i;
            k = 0;
            while (operand2[k] != '\0') {
                expr[j++] = operand2[k++];
            }
            expr[j++] = ')';
            expr[j] = '\0';

            push(stack, &top, expr);
        }
        i++;
    }
    pop(stack, &top, infix);
}

int main() {
    char postfix[] = "ab+c*df-/";
    char infix[MAX];

    postfixToInfix(postfix, infix);

    printf("Postfix expression: %s\n", postfix);
    printf("Infix expression: %s\n", infix);

    return 0;
}
