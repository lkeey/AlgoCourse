#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    
    int S;
    cin >> S;
    
    vector<int> dp(S + 1, INT_MAX);
    vector<int> prev(S + 1, -1);
    dp[0] = 0;
    
    for (int i = 1; i <= S; i++) {
        for (int j = 0; j < N; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    prev[i] = coins[j];
                }
            }
        }
    }
    
    if (dp[S] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[S] << endl;
        vector<int> result;
        int current = S;
        while (current > 0) {
            result.push_back(prev[current]);
            current -= prev[current];
        }
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}