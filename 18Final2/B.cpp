#include <iostream>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long combination(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;
    
    // C(n, k) = n! / (k! * (n-k)!)
    long long numerator = 1;
    long long denominator = 1;
    
    // To avoid overflow, we calculate it in a smarter way
    for (int i = 0; i < min(k, n - k); i++) {
        numerator *= (n - i);
        denominator *= (i + 1);
    }
    
    return numerator / denominator;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    if (k > n) {
        cout << 0 << endl;
        return 0;
    }
    
    long long row_ways = combination(n, k);
    long long col_ways = combination(n, k);
    long long arrangement_ways = factorial(k);
    
    long long result = row_ways * col_ways * arrangement_ways;
    
    cout << result << endl;
    
    return 0;
}