#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> graph(N + 1);
    
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back({y, 0}); 
        graph[y].push_back({x, 1});  
    }
    
    vector<int> dist(N + 1, INT_MAX);
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int cost = edge.second;
            
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                q.push(v);
            }
        }
    }
    
    if (dist[N] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[N] << endl;
    }
    
    return 0;
}