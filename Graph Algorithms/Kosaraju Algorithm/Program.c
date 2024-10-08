// C Program to implement the
// kosaraju's Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the max size of graph
#define MAX 100

typedef struct
{
    int V;

    // Adjacency matrix
    int adj[MAX][MAX];
} Graph;

Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph->adj[i][j] = 0;
    return graph;
}
void addEdge(Graph *graph, int u, int v)
{
    graph->adj[u][v] = 1;
}

// DFS to fill the stack based on
// finishing times
void dfs(int v, bool visited[], int stack[], int *index, Graph *graph)
{
    visited[v] = true;
    for (int i = 1; i < graph->V; i++)
    {
        if (graph->adj[v][i] && !visited[i])
            dfs(i, visited, stack, index, graph);
    }
    // Insert an element in stack during
    // backtracking
    stack[(*index)++] = v;
}

// DFS on the transposed graph
void dfsT(int v, bool visited[], Graph *graph)
{
    visited[v] = true;
    printf("%d ", v);
    for (int i = 1; i < graph->V; i++)
    {
        if (graph->adj[v][i] && !visited[i])
            dfsT(i, visited, graph);
    }
}

// Function to transpose the graph
//(reverse edges)
Graph *transposeGraph(Graph *graph)
{
    Graph *transposed = createGraph(graph->V);
    for (int i = 1; i < graph->V; i++)
    {
        for (int j = 1; j < graph->V; j++)
        {
            transposed->adj[i][j] =
                graph->adj[j][i];
        }
    }
    return transposed;
}

// Function to find SCCs using
// Kosaraju's Algorithm
void kosaraju(Graph *graph)
{
    bool visited[MAX] = {false};
    int stack[MAX], index = 0;

    // Step 1: Perform DFS on original
    // graph and fill stack
    for (int i = 1; i < graph->V; i++)
    {
        if (!visited[i])
            dfs(i, visited, stack,
                &index, graph);
    }

    // Step 2: Transpose the graph
    Graph *transposed = transposeGraph(graph);

    // Step 3: Process all vertices in
    // order defined by stack
    for (int i = 0; i < graph->V; i++)
    {
        visited[i] = false;
    }

    while (index > 0)
    {
        int v = stack[--index];
        if (!visited[v])
        {
            dfsT(v, visited, transposed);
            printf("\n");
        }
    }

    free(transposed);
}

int main()
{

    // Create a graph with 8 vertices
    Graph *graph = createGraph(8);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 5);

    // Find and print SCCs
    kosaraju(graph);

    free(graph);
    return 0;
}
