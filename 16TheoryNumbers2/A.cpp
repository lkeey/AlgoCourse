#include <iostream>
using namespace std;

// Function to compute (base^exp) % mod using fast exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {  // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;  // Divide exp by 2
    }
    return result;
}

// Function to find modular inverse of a modulo p
// Using Fermat's Little Theorem: a^(p-2) ≡ a^(-1) (mod p)
long long modInverse(long long a, long long p) {
    return power(a, p - 2, p);
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long p, a;
        cin >> p >> a;
        cout << modInverse(a, p) << endl;
    }
    
    return 0;
}