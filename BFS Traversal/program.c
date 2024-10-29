#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};


struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}


void enqueue(struct Queue* queue, struct Node* item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}


struct Node* dequeue(struct Queue* queue) {
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}


void bfsTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue(1000);  
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);

       
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }

        
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }

    free(queue->array);
    free(queue);
}


int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("BFS traversal of the binary tree: ");
    bfsTraversal(root);

    return 0;
}
