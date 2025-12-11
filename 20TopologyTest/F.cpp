#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> cost;
vector<long long> dist;

void dijkstra(int start, int N) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        long long d = cur.first;
        int city = cur.second;
        
        if (d > dist[city]) continue;
        
        for (int next : graph[city]) {
            long long new_dist = d + cost[city];
            
            if (new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push({new_dist, next});
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    cost.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }
    
    int M;
    cin >> M;
    
    graph.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dist.assign(N + 1, 1e18);
    
    dijkstra(1, N);
    
    cout << (dist[N] == 1e18 ? -1 : dist[N]) << endl;
    
    return 0;
}