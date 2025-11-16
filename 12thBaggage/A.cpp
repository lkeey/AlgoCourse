#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> dp(N + 1, N + 1);
    dp[0] = 0;
    
    vector<int> cubes;
    for (int i = 1; i * i * i <= N; i++) {
        cubes.push_back(i * i * i);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int cube : cubes) {
            if (cube <= i) {
                dp[i] = min(dp[i], dp[i - cube] + 1);
            }
        }
    }
    
    cout << dp[N] << endl;
    return 0;
}