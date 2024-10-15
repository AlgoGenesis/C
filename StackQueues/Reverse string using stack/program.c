#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100 
struct Stack {
    int top;
    char items[MAX];
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
void push(struct Stack *stack, char ch) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++(stack->top)] = ch;
}
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}
void reverseString(char str[]) {
    struct Stack stack;
    initialize(&stack);
    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX];
    printf("Enter a string (max 100 characters): ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
