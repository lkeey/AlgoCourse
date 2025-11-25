#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Create adjacency list to count degrees
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Output the degree of each vertex (number of traffic lights needed)
    for (int i = 1; i <= n; i++) {
        cout << adj[i].size();
        if (i < n) cout << " ";
    }
    cout << endl;
    
    return 0;
}