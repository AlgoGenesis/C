#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
     int items[MAX_SIZE];
     int top;
} Stack;

typedef struct {
     Stack* inStack;
     Stack* outStack;
} Queue;

// Stack operations
void initStack(Stack* s) {
     s->top = -1;
}

bool isEmpty(Stack* s) {
     return s->top == -1;
}

bool isFull(Stack* s) {
     return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int value) {
     if (!isFull(s)) {
          s->items[++s->top] = value;
     }
}

int pop(Stack* s) {
     if (!isEmpty(s)) {
          return s->items[s->top--];
     }
     return -1;  // Error value
}

Queue* createQueue() {
     Queue* q = (Queue*)malloc(sizeof(Queue));
     q->inStack = (Stack*)malloc(sizeof(Stack));
     q->outStack = (Stack*)malloc(sizeof(Stack));
     initStack(q->inStack);
     initStack(q->outStack);
     return q;
}

void enqueue(Queue* q, int value) {
     push(q->inStack, value);
}

int dequeue(Queue* q) {
     if (isEmpty(q->outStack)) {
          // Transfer elements from inStack to outStack
          while (!isEmpty(q->inStack)) {
                push(q->outStack, pop(q->inStack));
          }
     }
     return pop(q->outStack);
}

bool isQueueEmpty(Queue* q) {
     return isEmpty(q->inStack) && isEmpty(q->outStack);
}

void destroyQueue(Queue* q) {
     free(q->inStack);
     free(q->outStack);
     free(q);
}


int main() {
     Queue* q = createQueue();
     
     enqueue(q, 1);
     enqueue(q, 2);
     enqueue(q, 3);
     
     printf("%d\n", dequeue(q));  // Output: 1
     printf("%d\n", dequeue(q));  // Output: 2
     
     enqueue(q, 4);
     
     printf("%d\n", dequeue(q));  // Output: 3
     printf("%d\n", dequeue(q));  // Output: 4
     
     destroyQueue(q);
     // Additional test cases
     enqueue(q, 5);
     enqueue(q, 6);

     printf("%d\n", dequeue(q));  // Output: 5
     printf("%d\n", dequeue(q));  // Output: 6

     // Check if queue is empty
     if (isQueueEmpty(q)) {
         printf("Queue is empty\n");
     } else {
         printf("Queue is not empty\n");
     }

     destroyQueue(q);
     return 0;
}