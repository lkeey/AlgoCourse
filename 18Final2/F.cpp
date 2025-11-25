#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long long MOD = 1000000009;

// Fast modular exponentiation
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

// Function to compute prime factorization
map<long long, int> primeFactorize(long long n) {
    map<long long, int> factors;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

int main() {
    long long k, d, m;
    cin >> k >> d >> m;
    
    // If m is not divisible by d, there's no solution
    if (m % d != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Normalize: we want k numbers with GCD=1 and LCM=m/d
    long long normalized_m = m / d;
    
    // Get prime factorization of normalized_m
    map<long long, int> prime_factors = primeFactorize(normalized_m);
    
    long long result = 1;
    
    // For each prime factor, calculate its contribution
    for (auto& factor : prime_factors) {
        long long prime = factor.first;
        int exponent = factor.second;
        
        // For a prime p with exponent a, the number of valid k-tuples is:
        // (a+1)^k - 2*a^k + (a-1)^k
        long long term1 = power(exponent + 1, k, MOD);
        long long term2 = (2 * power(exponent, k, MOD)) % MOD;
        long long term3 = (exponent - 1 >= 0) ? power(exponent - 1, k, MOD) : 0;
        
        long long contribution = (term1 - term2 + term3 + 2 * MOD) % MOD;
        result = (result * contribution) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}