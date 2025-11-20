#include <iostream>
using namespace std;

const long long MOD = 1000000007;

// Function to calculate modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate modular inverse using Fermat's little theorem
long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

// Function to calculate nCr mod p using Fermat's little theorem
long long nCr(long long n, long long r, long long mod) {
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    
    // Calculate nCr = n! / (r! * (n-r)!)
    long long numerator = 1;
    long long denominator = 1;
    
    // To avoid calculating large factorials, we calculate:
    // nCr = (n * (n-1) * ... * (n-r+1)) / (r * (r-1) * ... * 1)
    for (long long i = 0; i < r; i++) {
        numerator = (numerator * (n - i)) % mod;
        denominator = (denominator * (i + 1)) % mod;
    }
    
    return (numerator * modInverse(denominator, mod)) % mod;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    // The answer is C(n + 2m - 1, 2m)
    cout << nCr(n + 2 * m - 1, 2 * m, MOD) << endl;
    
    return 0;
}