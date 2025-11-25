#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check for divisors from 5 to sqrt(n)
    // All primes > 3 are of the form 6k ± 1
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    long long n;
    cin >> n;
    
    if (isPrime(n)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}