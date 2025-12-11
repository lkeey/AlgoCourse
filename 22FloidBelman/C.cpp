#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 30000;

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
    
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        for (int j = 0; j < m; j++) {
            int from = edges[j].from;
            int to = edges[j].to;
            int weight = edges[j].weight;
            
            if (dist[from] < INF && dist[to] > dist[from] + weight) {
                dist[to] = dist[from] + weight;
                updated = true;
            }
        }
        if (!updated) break;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}