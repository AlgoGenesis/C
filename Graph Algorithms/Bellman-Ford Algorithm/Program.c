#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int u, v, weight;
};

const int INF = numeric_limits<int>::max();

bool bellmanFord(int n, int source, vector<Edge>& edges, vector<int>& dist) {
    dist.assign(n, INF);
    dist[source] = 0;

    // Relaxation step: iterate n-1 times
    for (int step = 1; step < n; ++step) {
        bool updated = false;
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;
            if (dist[u] != INF && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                updated = true;
            }
        }
        // Early stopping if no updates in this step
        if (!updated) break;
    }

    // Check for negative weight cycle in the nth step
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;
        if (dist[u] != INF && dist[v] > dist[u] + weight) {
            return true; // Negative cycle found
        }
    }

    return false; // No negative cycle
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist;
    if (bellmanFord(n, source, edges, dist)) {
        cout << "Negative cycle found" << endl;
    } else {
        cout << "Shortest distances from source vertex " << source << " are:" << endl;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
