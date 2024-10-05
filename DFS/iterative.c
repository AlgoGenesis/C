#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

// Stack structure
typedef struct Stack {
    int items[MAX_NODES];
    int top;
} Stack;

// Function to initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push item to stack
void push(Stack *s, int item) {
    if (s->top < MAX_NODES - 1) {
        s->items[++(s->top)] = item;
    }
}

// Function to pop item from stack
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1; // Error value
}

// Function to perform DFS
void DFS(int graph[MAX_NODES][MAX_NODES], int n, int start) {
    Stack stack;
    initStack(&stack);
    int visited[MAX_NODES] = {0}; // Initialize visited array

    // Push the starting node onto the stack
    push(&stack, start);

    while (!isEmpty(&stack)) {
        int node = pop(&stack);

        // If the node has not been visited
        if (!visited[node]) {
            visited[node] = 1; // Mark it as visited
            printf("%c ", 'A' + node); // Print the visited node

            // Push all adjacent unvisited nodes onto the stack
            for (int i = n - 1; i >= 0; i--) {
                if (graph[node][i] && !visited[i]) {
                    push(&stack, i);
                }
            }
        }
    }
}

int main() {
    int n = 7; // Number of vertices
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 1, 0, 0, 0}, // A
        {1, 0, 0, 0, 1, 1, 0}, // B
        {1, 0, 0, 0, 0, 0, 0}, // C
        {1, 0, 0, 0, 0, 0, 1}, // D
        {0, 1, 0, 0, 0, 0, 0}, // E
        {0, 1, 0, 0, 0, 0, 0}, // F
        {0, 0, 0, 1, 0, 0, 0}  // G
    };

    printf("Depth First Search starting from vertex A:\n");
    DFS(graph, n, 0); // Start DFS from vertex A (0)

    return 0;
}
