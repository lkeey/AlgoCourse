#include <iostream>
using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate arrangements A(n, k) = n! / (n-k)!
long long arrangements(int n, int k) {
    return factorial(n) / factorial(n - k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << arrangements(n, k) << endl;
    return 0;
}