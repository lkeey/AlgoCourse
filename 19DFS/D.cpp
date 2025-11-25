#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<long long> costs;

void dfs(int node, long long& minCost) {
    visited[node] = true;
    minCost = min(minCost, costs[node]);
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, minCost);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    costs.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
    }
    
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    long long totalCost = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            long long minCost = costs[i];
            dfs(i, minCost);
            totalCost += minCost;
        }
    }
    
    cout << totalCost << endl;
    
    return 0;
}