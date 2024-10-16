#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a graph edge
struct Edge
{
    int src, dest;
};

// Structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

// Structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;
};

// Structure to represent a graph
struct Graph
{
    int V;
    struct AdjList *array;
};

// Function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Utility function to shuffle adjacency list
void shuffle(int *array, int size)
{
    if (size > 1)
    {
        for (int i = size - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

// Function to generate a randomized spanning tree using BFS
void randomizedSpanningTree(struct Graph *graph, int startVertex)
{
    int *visited = (int *)calloc(graph->V, sizeof(int));
    int *queue = (int *)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    // Start BFS from the startVertex
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Randomized Spanning Tree Edges:\n");

    while (front != rear)
    {
        int current = queue[front++];
        struct AdjListNode *temp = graph->array[current].head;

        // Create an array of adjacent vertices
        int neighbors[graph->V];
        int count = 0;
        while (temp)
        {
            neighbors[count++] = temp->dest;
            temp = temp->next;
        }

        // Shuffle the neighbors to introduce randomness
        shuffle(neighbors, count);

        // Process neighbors
        for (int i = 0; i < count; ++i)
        {
            if (!visited[neighbors[i]])
            {
                printf("%d - %d\n", current, neighbors[i]);
                visited[neighbors[i]] = 1;
                queue[rear++] = neighbors[i];
            }
        }
    }

    free(visited);
    free(queue);
}

// Driver code
int main()
{
    srand(time(NULL));

    int V = 5;
    struct Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Generate Randomized Spanning Tree starting from vertex 0
    randomizedSpanningTree(graph, 0);

    return 0;
}
