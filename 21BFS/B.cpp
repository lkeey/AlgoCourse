#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int N, int x1, int y1, int x2, int y2) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    
    dist[x1][y1] = 0;
    q.push({x1, y1});
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == x2 && y == y2) {
            return dist[x][y];
        }
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return -1; // Should never reach here for valid inputs
}

int main() {
    int N, x1, y1, x2, y2;
    cin >> N >> x1 >> y1 >> x2 >> y2;
    
    // Convert to 0-indexed
    x1--; y1--; x2--; y2--;
    
    int result = bfs(N, x1, y1, x2, y2);
    cout << result << endl;
    
    return 0;
}