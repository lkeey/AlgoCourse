#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    long long x;
    cin >> x;
    
    // Count prime factors and their powers
    map<long long, int> prime_powers;
    long long temp = x;
    
    // Check for factors up to 1000 (as given in constraints)
    for (long long i = 2; i <= 1000 && i * i <= temp; i++) {
        while (temp % i == 0) {
            prime_powers[i]++;
            temp /= i;
        }
    }
    
    // If temp is still greater than 1, then it's a prime factor > 1000
    if (temp > 1) {
        prime_powers[temp]++;
    }
    
    // Calculate number of divisors
    // If x = p1^a1 * p2^a2 * ... * pk^ak, then number of divisors = (a1+1)*(a2+1)*...*(ak+1)
    long long divisors = 1;
    for (auto& pair : prime_powers) {
        divisors *= (pair.second + 1);
    }
    
    cout << divisors << endl;
    
    return 0;
}