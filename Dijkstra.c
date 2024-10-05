#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INF INT_MAX
#define MAX_NODES 100
#define NODE_COUNT 26

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES];
    int edge_count;
} Graph[NODE_COUNT];

typedef struct {
    int node;
    int distance;
} MinHeapNode;

typedef struct {
    MinHeapNode *nodes[MAX_NODES];
    int size;
} MinHeap;

MinHeap* createMinHeap() {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->nodes[left]->distance < minHeap->nodes[smallest]->distance) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->nodes[right]->distance < minHeap->nodes[smallest]->distance) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->nodes[smallest], &minHeap->nodes[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isEmpty(MinHeap *minHeap) {
    return minHeap->size == 0;
}

MinHeapNode* extractMin(MinHeap *minHeap) {
    if (isEmpty(minHeap)) {
        return NULL;
    }

    MinHeapNode *root = minHeap->nodes[0];
    MinHeapNode *lastNode = minHeap->nodes[minHeap->size - 1];
    minHeap->nodes[0] = lastNode;
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap *minHeap, int node, int distance) {
    int i;
    for (i = 0; i < minHeap->size; i++) {
        if (minHeap->nodes[i]->node == node) {
            break;
        }
    }

    minHeap->nodes[i]->distance = distance;

    while (i && minHeap->nodes[i]->distance < minHeap->nodes[(i - 1) / 2]->distance) {
        swapMinHeapNode(&minHeap->nodes[i], &minHeap->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

MinHeapNode* newMinHeapNode(int node, int distance) {
    MinHeapNode *minHeapNode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    minHeapNode->node = node;
    minHeapNode->distance = distance;
    return minHeapNode;
}

void addEdge(Graph graph, char src, char dest, int weight) {
    int srcIndex = src - 'A';
    int destIndex = dest - 'A';
    graph[srcIndex].edges[graph[srcIndex].edge_count].node = destIndex;
    graph[srcIndex].edges[graph[srcIndex].edge_count].weight = weight;
    graph[srcIndex].edge_count++;
}

void dijkstra(Graph graph, char src, char dest) {
    int srcIndex = src - 'A';
    int destIndex = dest - 'A';
    int shortest[NODE_COUNT];
    int prev[NODE_COUNT];
    MinHeap *minHeap = createMinHeap();

    for (int i = 0; i < NODE_COUNT; i++) {
        shortest[i] = INF;
        prev[i] = -1;
        minHeap->nodes[i] = newMinHeapNode(i, shortest[i]);
        minHeap->size++;
    }

    minHeap->nodes[srcIndex] = newMinHeapNode(srcIndex, 0);
    shortest[srcIndex] = 0;
    decreaseKey(minHeap, srcIndex, shortest[srcIndex]);

    while (!isEmpty(minHeap)) {
        MinHeapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->node;

        for (int i = 0; i < graph[u].edge_count; i++) {
            int v = graph[u].edges[i].node;
            int weight = graph[u].edges[i].weight;

            if (shortest[u] != INF && shortest[u] + weight < shortest[v]) {
                shortest[v] = shortest[u] + weight;
                prev[v] = u;
                decreaseKey(minHeap, v, shortest[v]);
            }
        }
    }

    if (shortest[destIndex] == INF) {
        printf("Path not reachable\n");
        return;
    }

    int path[MAX_NODES];
    int path_index = 0;
    for (int at = destIndex; at != -1; at = prev[at]) {
        path[path_index++] = at;
    }

    printf("Shortest Path: ");
    for (int i = path_index - 1; i >= 0; i--) {
        printf("%c ", path[i] + 'A');
    }
    printf("\nDistance: %d\n", shortest[destIndex]);
}

int main() {
    Graph graph;
    for (int i = 0; i < NODE_COUNT; i++) {
        graph[i].edge_count = 0;
    }

    addEdge(graph, 'A', 'B', 4);
    addEdge(graph, 'A', 'C', 1);
    addEdge(graph, 'B', 'C', 2);
    addEdge(graph, 'B', 'D', 5);
    addEdge(graph, 'C', 'D', 8);
    addEdge(graph, 'C', 'E', 10);
    addEdge(graph, 'D', 'E', 2);

    char start = 'A';
    char end = 'E';

    dijkstra(graph, start, end);

    return 0;
}
