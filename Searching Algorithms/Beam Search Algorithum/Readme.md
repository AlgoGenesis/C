# Beam Search Algorithm in C

## Overview

This repository contains an implementation of the **Beam Search** algorithm in C. Beam Search is a heuristic search algorithm often used in areas like artificial intelligence, natural language processing, and game playing. It is an optimization of the breadth-first search where only a limited number of the best nodes (based on a heuristic) are kept for further exploration. The number of nodes retained at each level is known as the **beam width**.

## Algorithm

Beam Search expands nodes level by level:
1. It starts with the root node.
2. At each level, it selects the top **beam width** nodes based on a heuristic (in this case, node values).
3. Only the best nodes are expanded, and the process continues until there are no more nodes to expand or the desired solution is found.

### Features:
- **Heuristic-based search**: Keeps the top nodes at each level to reduce search space.
- **Beam width control**: You can adjust the beam width to explore more or fewer nodes.
- **Tree/graph search**: It works on a tree or graph structure.

## Code

The code is written in `C`. Here is the core part of the implementation:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int n_children;
    struct Node** children;
} Node;

Node* createNode(int value, int n_children) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->n_children = n_children;
    newNode->children = (Node**)malloc(n_children * sizeof(Node*));
    return newNode;
}

int compareNodes(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;
    return nodeB->value - nodeA->value;
}

void beamSearch(Node* root, int beam_width) {
    Node** beam = (Node**)malloc(beam_width * sizeof(Node*));
    int beam_size = 0;
    beam[beam_size++] = root;

    while (beam_size > 0) {
        printf("Current Beam: ");
        for (int i = 0; i < beam_size; i++) {
            printf("%d ", beam[i]->value);
        }
        printf("\n");

        Node** next_beam = (Node**)malloc(beam_width * sizeof(Node*));
        int next_beam_size = 0;

        for (int i = 0; i < beam_size; i++) {
            Node* current = beam[i];
            for (int j = 0; j < current->n_children; j++) {
                if (next_beam_size < beam_width) {
                    next_beam[next_beam_size++] = current->children[j];
                } else {
                    qsort(next_beam, next_beam_size, sizeof(Node*), compareNodes);
                    if (current->children[j]->value > next_beam[next_beam_size - 1]->value) {
                        next_beam[next_beam_size - 1] = current->children[j];
                    }
                }
            }
        }

        qsort(next_beam, next_beam_size, sizeof(Node*), compareNodes);
        beam_size = next_beam_size < beam_width ? next_beam_size : beam_width;
        for (int i = 0; i < beam_size; i++) {
            beam[i] = next_beam[i];
        }

        free(next_beam);

        if (beam_size == 0) {
            printf("Search Complete\n");
            break;
        }
    }

    free(beam);
}

int main() {
    Node* root = createNode(10, 3);
    root->children[0] = createNode(20, 2);
    root->children[1] = createNode(15, 2);
    root->children[2] = createNode(5, 2);

    root->children[0]->children[0] = createNode(30, 0);
    root->children[0]->children[1] = createNode(25, 0);
    root->children[1]->children[0] = createNode(18, 0);
    root->children[1]->children[1] = createNode(12, 0);
    root->children[2]->children[0] = createNode(6, 0);
    root->children[2]->children[1] = createNode(2, 0);

    int beam_width = 2;
    printf("Beam Search with beam width = %d:\n", beam_width);
    beamSearch(root, beam_width);

    free(root->children[0]->children);
    free(root->children[1]->children);
    free(root->children[2]->children);
    free(root->children);
    free(root);

    return 0;
}
