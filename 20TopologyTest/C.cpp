#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int x1, int y1, int x2, int y2) {
    bool visited[8][8][8][8] = {false};
    queue<int> q;
    
    q.push(x1 * 1000 + y1 * 100 + x2 * 10 + y2);
    visited[x1][y1][x2][y2] = true;
    
    int dist = 0;
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int state = q.front();
            q.pop();
            
            int cx1 = state / 1000;
            int cy1 = (state / 100) % 10;
            int cx2 = (state / 10) % 10;
            int cy2 = state % 10;
            
            if (cx1 == cx2 && cy1 == cy2) {
                return dist;
            }
            
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    int nx1 = cx1 + dx[j];
                    int ny1 = cy1 + dy[j];
                    int nx2 = cx2 + dx[k];
                    int ny2 = cy2 + dy[k];
                    
                    if (nx1 >= 0 && nx1 < 8 && ny1 >= 0 && ny1 < 8 && 
                        nx2 >= 0 && nx2 < 8 && ny2 >= 0 && ny2 < 8) {
                        if (!visited[nx1][ny1][nx2][ny2]) {
                            visited[nx1][ny1][nx2][ny2] = true;
                            q.push(nx1 * 1000 + ny1 * 100 + nx2 * 10 + ny2);
                        }
                    }
                }
            }
        }
        dist++;
    }
    
    return -1;
}

int main() {
    char c1, c2;
    int r1, r2;
    cin >> c1 >> r1 >> c2 >> r2;
    
    int x1 = c1 - 'a';
    int y1 = r1 - 1;
    int x2 = c2 - 'a';
    int y2 = r2 - 1;
    
    int result = bfs(x1, y1, x2, y2);
    cout << result << endl;
    
    return 0;
}