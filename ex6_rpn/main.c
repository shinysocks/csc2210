/*
 * Noah Dinan
 * CSC2210
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"

double evaluateRPN(char input[]);

int main() {
    char input[256];
    printf("Enter an RPN expression : ");
    fgets(input, sizeof(input), stdin);
    double result = evaluateRPN(input);
    printf("Result : %.2f\n", result);
    return 0;
}

double evaluateRPN(char input[]) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            push(input[i] - '0');
        } else if (input[i] == '+') {
            push(pop() + pop());
        } else if (input[i] == '-') {
            const double v = pop();
            push(pop() - v);
        } else if (input[i] == '*') {
            push(pop() * pop());
        } else if (input[i] == '/') {
            const double v = pop();
            if (v == 0) {
                printf("illegal division by zero");
                exit(1);
            }
        }
    }
    return pop();
}
 
