#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef struct {
    int v;
    struct Node *next;
} Node;

Node *tree[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int currentPos;
int segmentTree[4 * MAXN], values[MAXN]; // Segment tree to support range queries
int subtreeSize[MAXN];

// Utility function to add an edge in the adjacency list
void addEdge(int u, int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = tree[u];
    tree[u] = newNode;
}

// DFS to calculate subtree sizes and find heavy child for each node
int dfs(int v) {
    int size = 1;
    int maxSubtree = 0;
    subtreeSize[v] = 1;
    
    for (Node *node = tree[v]; node != NULL; node = node->next) {
        int u = node->v;
        if (u != parent[v]) {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            int subtreeSize = dfs(u);
            size += subtreeSize;
            if (subtreeSize > maxSubtree) {
                maxSubtree = subtreeSize;
                heavy[v] = u;
            }
        }
    }
    return size;
}

// Decomposing the tree into heavy-light chains
void decompose(int v, int h) {
    head[v] = h;
    pos[v] = currentPos++;
    if (heavy[v] != -1) {
        decompose(heavy[v], h); // Continue on the heavy path
    }
    for (Node *node = tree[v]; node != NULL; node = node->next) {
        int u = node->v;
        if (u != parent[v] && u != heavy[v]) {
            decompose(u, u); // Start a new light path
        }
    }
}

// Building the segment tree for range queries
void buildSegmentTree(int node, int start, int end) {
    if (start == end) {
        segmentTree[node] = values[start];
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(2 * node, start, mid);
        buildSegmentTree(2 * node + 1, mid + 1, end);
        segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
    }
}

// Segment tree update function
void updateSegmentTree(int node, int start, int end, int idx, int value) {
    if (start == end) {
        segmentTree[node] = value;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            updateSegmentTree(2 * node, start, mid, idx, value);
        } else {
            updateSegmentTree(2 * node + 1, mid + 1, end, idx, value);
        }
        segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
    }
}

// Segment tree query function
int querySegmentTree(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    int leftSum = querySegmentTree(2 * node, start, mid, l, r);
    int rightSum = querySegmentTree(2 * node + 1, mid + 1, end, l, r);
    return leftSum + rightSum;
}

// Querying the path from node u to v
int queryPath(int u, int v) {
    int result = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) {
            int temp = u;
            u = v;
            v = temp;
        }
        result += querySegmentTree(1, 0, currentPos - 1, pos[head[u]], pos[u]);
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }
    result += querySegmentTree(1, 0, currentPos - 1, pos[u], pos[v]);
    return result;
}

int main() {
    int n;
    scanf("%d", &n); // Number of nodes

    // Initialize variables
    memset(tree, 0, sizeof(tree));
    memset(heavy, -1, sizeof(heavy));
    currentPos = 0;

    // Read tree edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    // Initialize parent and depth
    parent[0] = -1;
    depth[0] = 0;

    // Perform DFS and decompose the tree
    dfs(0);
    decompose(0, 0);

    // Build segment tree with initial values
    buildSegmentTree(1, 0, currentPos - 1);

    // Example query and update usage
    int u, v;
    scanf("%d %d", &u, &v);
    printf("Path sum between %d and %d is %d\n", u, v, queryPath(u, v));

    return 0;
}
