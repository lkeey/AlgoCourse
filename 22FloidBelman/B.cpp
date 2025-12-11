#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    vector<vector<int>> dist = graph;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] && dist[k][j]) {
                    dist[i][j] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dist[i][i]) {
            cout << 1 << endl;
            return 0;
        }
    }
    
    cout << 0 << endl;
    
    return 0;
}