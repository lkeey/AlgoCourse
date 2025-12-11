#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int main() {
    int n;
    cin >> n;
    
    vector<vector<long long>> dist(n, vector<long long>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (i != j && dist[i][j] == 0) {
                dist[i][j] = INF;
            }
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    long long max_dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] < INF) {
                max_dist = max(max_dist, dist[i][j]);
            }
        }
    }
    
    cout << max_dist << endl;
    
    return 0;
}