#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fast modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    long long N, M, Y;
    cin >> N >> M >> Y;
    
    vector<long long> solutions;
    
    // Check all values from 0 to M-1
    for (long long X = 0; X < M; X++) {
        if (power(X, N, M) == Y) {
            solutions.push_back(X);
        }
    }
    
    if (solutions.empty()) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < solutions.size(); i++) {
            if (i > 0) cout << " ";
            cout << solutions[i];
        }
        cout << endl;
    }
    
    return 0;
}