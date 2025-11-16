#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> moves = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
    
    for (int i = 0; i <= 9; i++) {
        if (i != 0 && i != 8) {
            dp[1][i] = 1;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int prev : moves[j]) {
                dp[i][j] += dp[i-1][prev];
            }
        }
    }
    
    long long result = 0;
    for (int i = 0; i <= 9; i++) {
        result += dp[n][i];
    }
    
    cout << result << endl;
    
    return 0;
}