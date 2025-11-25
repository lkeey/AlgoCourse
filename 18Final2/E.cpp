#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Number of grid squares the line intersects
    // Formula: (n-1) + (m-1) - gcd(n-1, m-1)
    long long result = n + m - 2 - gcd(n - 1, m - 1);
    
    cout << result << endl;
    
    return 0;
}