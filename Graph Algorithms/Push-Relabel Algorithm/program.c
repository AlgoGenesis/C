#include <stdio.h>
#include <string.h>
#include <limits.h>

// Number of vertices in the graph
#define V 6

// Function to push flow from one vertex to another
void push(int u, int v, int capacity[V][V], int flow[V][V], int excess[], int height[]) {
    int send = (excess[u] < (capacity[u][v] - flow[u][v])) ? excess[u] : (capacity[u][v] - flow[u][v]);
    flow[u][v] += send;
    flow[v][u] -= send;
    excess[u] -= send;
    excess[v] += send;
}

// Function to relabel the vertex with the minimum height of its adjacent vertices
void relabel(int u, int capacity[V][V], int flow[V][V], int height[], int excess[]) {
    int minHeight = INT_MAX;
    for (int v = 0; v < V; v++) {
        if (capacity[u][v] - flow[u][v] > 0) {
            minHeight = (height[v] < minHeight) ? height[v] : minHeight;
            height[u] = minHeight + 1;
        }
    }
}

// Function to initialize preflow for the source vertex
void initializePreflow(int source, int capacity[V][V], int flow[V][V], int height[], int excess[]) {
    height[source] = V;
    for (int v = 0; v < V; v++) {
        if (capacity[source][v] > 0) {
            flow[source][v] = capacity[source][v];
            flow[v][source] = -flow[source][v];
            excess[v] = capacity[source][v];
            excess[source] -= capacity[source][v];
        }
    }
}

// Main function to implement the Push-Relabel algorithm
int pushRelabel(int capacity[V][V], int source, int sink) {
    int flow[V][V];
    int height[V] = {0}, excess[V] = {0};
    memset(flow, 0, sizeof(flow));

    initializePreflow(source, capacity, flow, height, excess);

    while (1) {
        int u;
        for (u = 0; u < V; u++) {
            if (excess[u] > 0 && u != source && u != sink) {
                int pushed = 0;
                for (int v = 0; v < V; v++) {
                    if (capacity[u][v] - flow[u][v] > 0 && height[u] > height[v]) {
                        push(u, v, capacity, flow, excess, height);
                        pushed = 1;
                    }
                }
                if (!pushed) relabel(u, capacity, flow, height, excess);
            }
        }

        int finished = 1;
        for (u = 0; u < V; u++) {
            if (excess[u] > 0 && u != source && u != sink) {
                finished = 0;
                break;
            }
        }
        if (finished) break;
    }

    int maxFlow = 0;
    for (int v = 0; v < V; v++) {
        maxFlow += flow[source][v];
    }

    return maxFlow;
}

int main() {
    // Graph represented as a capacity matrix
    int capacity[V][V] = { {0, 16, 13, 0, 0, 0},
                           {0, 0, 10, 12, 0, 0},
                           {0, 4, 0, 0, 14, 0},
                           {0, 0, 9, 0, 0, 20},
                           {0, 0, 0, 7, 0, 4},
                           {0, 0, 0, 0, 0, 0} };

    int source = 0, sink = 5;

    printf("Maximum Flow: %d\n", pushRelabel(capacity, source, sink));

    return 0;
}
