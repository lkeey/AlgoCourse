#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> treeEdges;

void dfs(int node, int parent) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            // Add this edge to our tree
            treeEdges.push_back({min(node, neighbor), max(node, neighbor)});
            dfs(neighbor, node);
        }
        // If visited[neighbor] is true and neighbor is not the parent,
        // then this is a back edge (cycle), which we ignore for the tree
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }
    
    // Find connected components and build spanning tree
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, -1);
        }
    }
    
    // For a tree to exist, we need exactly one connected component
    if (components == 1) {
        cout << "Yes" << endl;
        cout << treeEdges.size() << endl;
        for (auto edge : treeEdges) {
            cout << edge.first << " " << edge.second << endl;
        }
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}