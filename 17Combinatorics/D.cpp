#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> counts(n);
    for (int i = 0; i < n; i++) {
        cin >> counts[i];
    }
    
    long long result = 0;
    
    // Calculate sum of products taken 3 at a time
    // For each triplet (i, j, k) where i < j < k
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                result += counts[i] * counts[j] * counts[k];
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}