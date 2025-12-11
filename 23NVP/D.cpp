#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    // dp[i][j] - длина НОВП для a[0..i-1] и b[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // prev[i][j] - индекс предыдущего элемента в НОВП
    vector<vector<int>> prev_i(n + 1, vector<int>(m + 1, -1));
    vector<vector<int>> prev_j(n + 1, vector<int>(m + 1, -1));
    
    for (int i = 1; i <= n; i++) {
        int max_len = 0;
        int max_k = 0;
        
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            prev_i[i][j] = prev_i[i-1][j];
            prev_j[i][j] = prev_j[i-1][j];
            
            if (a[i-1] == b[j-1]) {
                if (dp[i-1][j-1] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    prev_i[i][j] = i-1;
                    prev_j[i][j] = j-1;
                }
            } else if (a[i-1] > b[j-1]) {
                if (dp[i-1][j-1] > max_len) {
                    max_len = dp[i-1][j-1];
                    max_k = j-1;
                }
            }
            
            if (max_len > dp[i][j]) {
                dp[i][j] = max_len;
                prev_i[i][j] = prev_i[i-1][max_k];
                prev_j[i][j] = prev_j[i-1][max_k];
            }
        }
    }
    
    // Восстановление ответа
    int max_len = 0;
    int max_i = 0, max_j = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] > max_len) {
                max_len = dp[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    
    vector<int> result;
    int i = max_i, j = max_j;
    while (i > 0 && j > 0) {
        if (prev_i[i][j] != -1 && prev_j[i][j] != -1) {
            int prev_i_val = prev_i[i][j];
            int prev_j_val = prev_j[i][j];
            
            if (dp[i][j] > dp[prev_i_val][prev_j_val]) {
                // Это значит, что элемент был добавлен в подпоследовательность
                if (a[i-1] == b[j-1]) {
                    result.push_back(a[i-1]);
                }
            }
            
            i = prev_i_val;
            j = prev_j_val;
        } else {
            break;
        }
    }
    
    reverse(result.begin(), result.end());
    
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}