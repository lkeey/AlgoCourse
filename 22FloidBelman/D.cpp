#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int from, to, weight;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }
    
    vector<long long> dist(n + 1, -INF);
    dist[1] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        for (int j = 0; j < m; j++) {
            int from = edges[j].from;
            int to = edges[j].to;
            int weight = edges[j].weight;
            
            if (dist[from] > -INF && dist[to] < dist[from] + weight) {
                dist[to] = dist[from] + weight;
                updated = true;
            }
        }
        if (!updated) break;
    }
    
    vector<bool> positive_cycle(n + 1, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int from = edges[j].from;
            int to = edges[j].to;
            int weight = edges[j].weight;
            
            if (dist[from] > -INF && dist[to] < dist[from] + weight) {
                dist[to] = dist[from] + weight;
                positive_cycle[to] = true;
            } else if (positive_cycle[from]) {
                positive_cycle[to] = true;
            }
        }
    }
    
    if (positive_cycle[n]) {
        cout << ":)" << endl;
    } else if (dist[n] == -INF) {
        cout << ":(" << endl;
    } else {
        cout << dist[n] << endl;
    }
    
    return 0;
}