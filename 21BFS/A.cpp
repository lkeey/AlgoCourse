#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(const vector<vector<int>>& adj, int start, int end, int n) {
    queue<int> q;
    vector<int> dist(n, -1);
    
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int u = 0; u < n; u++) {
            if (adj[v][u] == 1 && dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    
    return dist[end];
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    
    int start, end;
    cin >> start >> end;
    
    start--;
    end--;
    
    cout << bfs(adj, start, end, n) << endl;
    
    return 0;
}