#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check for divisors from 5 to sqrt(n)
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to check if a number is T-prime
bool isTPrime(long long x) {
    // A number is T-prime if it's a square of a prime number
    // First check if x is a perfect square
    long long sqrtX = sqrt(x);
    
    // Check if sqrtX is actually the square root of x
    if (sqrtX * sqrtX != x) {
        return false;
    }
    
    // Check if the square root is a prime number
    return isPrime(sqrtX);
}

int main() {
    long long n;
    cin >> n;
    
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        if (isTPrime(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}