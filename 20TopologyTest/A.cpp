#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int n) {
    if (n == 0) return true;
    
    vector<int> color(n + 1, -1); // -1 means unvisited, 0 and 1 are colors
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if (isBipartite(graph, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}