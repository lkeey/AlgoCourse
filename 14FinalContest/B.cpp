#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }
    
    vector<vector<double>> dp(n, vector<double>(101, -1e9));
    vector<vector<int>> prev_choice(n, vector<int>(101, 0));
    
    for (int j = 1; j <= tasks[0]; j++) {
        dp[0][j] = 0.0;
    }
    
    for (int i = 1; i < n; i++) {
        for (int curr = 1; curr <= tasks[i]; curr++) {
            for (int prev = 1; prev <= tasks[i-1]; prev++) {
                if (dp[i-1][prev] >= 0) {
                    double rating_increase = (double)curr / prev;
                    double new_rating = dp[i-1][prev] + rating_increase;
                    
                    if (new_rating > dp[i][curr]) {
                        dp[i][curr] = new_rating;
                        prev_choice[i][curr] = prev;
                    }
                }
            }
        }
    }
    
    double max_rating_val = -1e9;
    int best_last_count = 1;
    
    for (int j = 1; j <= tasks[n-1]; j++) {
        if (dp[n-1][j] > max_rating_val) {
            max_rating_val = dp[n-1][j];
            best_last_count = j;
        }
    }
    
    vector<int> result(n);
    result[n-1] = best_last_count;
    
    for (int i = n-2; i >= 0; i--) {
        result[i] = prev_choice[i+1][result[i+1]];
    }
    
    cout.precision(10);
    cout << fixed << max_rating_val << "\n";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n-1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}