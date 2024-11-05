#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 1000000

typedef struct {
    int node;
    int cost;
} Edge;

typedef struct {
    Edge edges[MAX_NODES];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

void push(PriorityQueue* pq, int node, int cost) {
    pq->edges[pq->size].node = node;
    pq->edges[pq->size].cost = cost;
    pq->size++;
    for (int i = pq->size - 1; i > 0; i--) {
        if (pq->edges[i].cost < pq->edges[i - 1].cost) {
            Edge temp = pq->edges[i];
            pq->edges[i] = pq->edges[i - 1];
            pq->edges[i - 1] = temp;
        } else break;
    }
}

Edge pop(PriorityQueue* pq) {
    Edge top = pq->edges[0];
    for (int i = 1; i < pq->size; i++) {
        pq->edges[i - 1] = pq->edges[i];
    }
    pq->size--;
    return top;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int cost[MAX_NODES];

void uniformCostSearch(int start, int goal, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        cost[i] = INF;
        visited[i] = 0;
    }
    PriorityQueue pq;
    initQueue(&pq);
    push(&pq, start, 0);
    cost[start] = 0;

    while (!isEmpty(&pq)) {
        Edge current = pop(&pq);
        int node = current.node;
        if (visited[node]) continue;
        visited[node] = 1;
        if (node == goal) {
            printf("Minimum cost from node %d to node %d is: %d\n", start, goal, cost[goal]);
            return;
        }
        for (int neighbor = 0; neighbor < numNodes; neighbor++) {
            if (graph[node][neighbor] != 0 && !visited[neighbor]) {
                int newCost = cost[node] + graph[node][neighbor];
                if (newCost < cost[neighbor]) {
                    cost[neighbor] = newCost;
                    push(&pq, neighbor, newCost);
                }
            }
        }
    }
    printf("No path found from node %d to node %d\n", start, goal);
}

int main() {
    int numNodes, numEdges;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &numNodes, &numEdges);

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (start node, end node, cost):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        graph[u][v] = c;
    }

    int start, goal;
    printf("Enter start and goal nodes: ");
    scanf("%d %d", &start, &goal);

    uniformCostSearch(start, goal, numNodes);

    return 0;
}
