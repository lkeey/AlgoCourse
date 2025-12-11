#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, long long>>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    
    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            long long w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    if (dist[n] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        int cur = n;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}