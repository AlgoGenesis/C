#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char * s) {
    int stackSize = 0;
    int stackCapacity = 100; // Initial capacity for the stack
    char *stack = (char *)malloc(stackCapacity * sizeof(char));

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            // Push to stack
            if (stackSize == stackCapacity) {
                stackCapacity *= 2; // Double the stack size if needed
                stack = (char *)realloc(stack, stackCapacity * sizeof(char));
            }
            stack[stackSize++] = s[i];
        } else if (s[i] == ')') {
            // Pop from stack
            if (stackSize == 0) {
                free(stack);
                return false; // No matching opening parenthesis
            }
            stackSize--; // Pop the last opening parenthesis
        }
    }

    bool result = (stackSize == 0); // If stack is empty, valid parentheses
    free(stack);
    return result;
}

int main() {
    char *s = "(()())";
    if (isValid(s)) {
        printf("Valid parentheses\n");
    } else {
        printf("Invalid parentheses\n");
    }
    return 0;
}