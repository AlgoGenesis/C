#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS utility function to perform Depth First Search
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
        // Mark the current node as visited
        vis[node] = 1;
        
        // Recur for all the vertices adjacent to this vertex
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        // Push the current node to the stack after all its adjacent vertices are visited
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        // Create an array to mark visited nodes
        int vis[V] = {0};
        // Stack to store the topological sort
        stack<int> st;
        
        // Perform DFS for each node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        // Store the result from the stack into a vector
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {
    // Define the graph in terms of adjacency list
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6; // Number of vertices
    
    Solution obj;
    vector<int> ans = obj.topoSort(V, adj);

    // Print the topological sort
    for (auto node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
