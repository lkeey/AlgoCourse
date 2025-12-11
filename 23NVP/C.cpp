#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPerfectSquare(long long x) {
    if (x < 0) return false;
    long long root = sqrt(x);
    return root * root == x;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> boys(n);
    for (int i = 0; i < n; i++) {
        cin >> boys[i];
    }
    
    vector<int> girls(m);
    for (int j = 0; j < m; j++) {
        cin >> girls[j];
    }
    
    vector<vector<bool>> compatible(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPerfectSquare((long long)boys[i] * girls[j])) {
                compatible[i][j] = true;
            }
        }
    }
    
    vector<int> match(n, -1);
    vector<int> match2(m, -1);
    
    vector<bool> used;
    
    function<bool(int)> dfs = [&](int u) {
        if (used[u]) return false;
        used[u] = true;
        for (int v = 0; v < m; v++) {
            if (compatible[u][v]) {
                if (match2[v] == -1 || dfs(match2[v])) {
                    match[u] = v;
                    match2[v] = u;
                    return true;
                }
            }
        }
        return false;
    };
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        used.assign(n, false);
        if (dfs(i)) {
            result++;
        }
    }
    
    cout << result << endl;
    if (result > 0) {
        vector<int> boys_indices, girls_indices;
        for (int i = 0; i < n; i++) {
            if (match[i] != -1) {
                boys_indices.push_back(i + 1);
                girls_indices.push_back(match[i] + 1);
            }
        }
        
        for (int i = 0; i < boys_indices.size(); i++) {
            cout << boys_indices[i] << " ";
        }
        cout << endl;
        
        for (int i = 0; i < girls_indices.size(); i++) {
            cout << girls_indices[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}