#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate combinations C(n, k)
long long combinations(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << combinations(n, k) << endl;
    return 0;
}