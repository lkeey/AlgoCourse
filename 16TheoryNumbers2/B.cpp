#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    // Create a boolean array to mark prime numbers
    // We'll use Sieve of Eratosthenes
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    // Sieve of Eratosthenes
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            // Mark all multiples of i as not prime
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Count primes in range [M, N]
    int count = 0;
    for (int i = M; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << endl;
            count++;
        }
    }
    
    // If no primes found, output "Absent"
    if (count == 0) {
        cout << "Absent" << endl;
    }
    
    return 0;
}