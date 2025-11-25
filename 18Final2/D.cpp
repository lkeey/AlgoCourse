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
    
    // For small n, use direct approach
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n <= 100) {
        // For small n, direct computation is fine
        long long result = 0;
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
    
    // For larger n, use mathematical formula
    // Sum of products taken 3 at a time = (S1^3 - 3*S1*S2 + 2*S3) / 6
    // where S1 = sum of elements, S2 = sum of squares, S3 = sum of cubes
    
    long long S1 = 0, S2 = 0, S3 = 0;
    for (int i = 0; i < n; i++) {
        S1 += counts[i];
        S2 += counts[i] * counts[i];
        S3 += counts[i] * counts[i] * counts[i];
    }
    
    long long result = (S1 * S1 * S1 - 3 * S1 * S2 + 2 * S3) / 6;
    cout << result << endl;
    
    return 0;
}