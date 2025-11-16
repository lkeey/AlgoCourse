#include <iostream>
using namespace std;

long long mod_pow(long long base, long long exponent, long long mod) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base % mod;
    
    long long half = mod_pow(base, exponent / 2, mod);
    long long result = (half * half) % mod;
    
    // Если степень нечетная, умножаем на base
    if (exponent % 2 == 1) {
        result = (result * base) % mod;
    }
    
    return result;
}

int main() {
    long long n, m, p;
    cin >> n >> m >> p;
    
    long long result = mod_pow(n, p, m);
    cout << result;
    
    return 0;
}