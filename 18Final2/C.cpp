#include <iostream>
#include <vector>

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
    int n;
    cin >> n;
    
    int half = n / 2;
    
    // Number of ways to choose half people for first group
    long long ways_to_choose = combination(n, half);
    
    // Number of ways to arrange each group in a circle
    // For a circular arrangement of k people, it's (k-1)!
    long long circle_arrangements = 1;
    if (half > 1) {
        circle_arrangements = factorial(half - 1);
    }
    
    // Total arrangements for both groups
    long long total_arrangements = ways_to_choose * circle_arrangements * circle_arrangements;
    
    // Since the two groups are indistinguishable, divide by 2
    long long result = total_arrangements / 2;
    
    cout << result << endl;
    
    return 0;
}