#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findCycle(vector<vector<int>>& graph, vector<int>& parent, vector<bool>& visited, 
               int currentNode, int parentNode, vector<int>& cyclePath) {
    visited[currentNode] = true;
    parent[currentNode] = parentNode;
    
    for (int neighbor : graph[currentNode]) {
        if (neighbor == parentNode) {
            continue;
        }
        
        if (visited[neighbor]) {
            int current = currentNode;
            
            while (current != neighbor && current != -1) {
                cyclePath.push_back(current);
                current = parent[current];
            }
            
            if (current == neighbor) {
                cyclePath.push_back(neighbor);
                reverse(cyclePath.begin(), cyclePath.end());
                return true;
            }
        } else {
            if (findCycle(graph, parent, visited, neighbor, currentNode, cyclePath)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> cyclePath;
    bool cycleFound = false;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (findCycle(graph, parent, visited, i, -1, cyclePath)) {
                cycleFound = true;
                break;
            }
        }
    }
    
    if (!cycleFound) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << cyclePath.size() << endl;
        for (int i = 0; i < cyclePath.size(); i++) {
            if (i > 0) cout << " ";
            cout << cyclePath[i];
        }
        cout << endl;
    }
    
    return 0;
}