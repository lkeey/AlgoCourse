#include <iostream>
using namespace std;

// Function to find the last non-zero digit of N!
int lastNonZeroDigit(long long n) {
    if (n < 5) {
        // For small values, calculate directly
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
            // Remove trailing zeros
            while (result % 10 == 0) {
                result /= 10;
            }
            // Keep only last digit to prevent overflow
            result %= 100000;
        }
        return result % 10;
    }
    
    // For larger values, use recursive approach
    // Based on the pattern of last non-zero digits
    int patterns[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
    
    if (n < 10) {
        return patterns[n];
    }
    
    // Get the last digit of n
    int lastDigit = n % 10;
    
    // Get the count of 5s in numbers 1 to n
    int count5s = 0;
    long long temp = n;
    while (temp > 0) {
        temp /= 5;
        count5s += temp;
    }
    
    // Calculate result based on recursive pattern
    int result = 1;
    
    // Handle groups of 10
    if ((n / 10) % 2 == 1) {
        result = 4;
    } else {
        result = 6;
    }
    
    // Multiply by pattern for last digit
    result = (result * patterns[lastDigit]) % 10;
    
    // Adjust for extra 2s (since we have more 2s than 5s)
    for (int i = 0; i < count5s; i++) {
        result = (result * 2) % 10;
    }
    
    return result;
}

// Simpler approach - calculate factorial while removing factors of 10
int lastNonZeroDigitSimple(long long n) {
    if (n == 0) return 1;
    
    long long result = 1;
    for (long long i = 1; i <= n; i++) {
        result *= i;
        
        // Remove factors of 10
        while (result % 10 == 0) {
            result /= 10;
        }
        
        // Keep result manageable to prevent overflow
        result %= 1000000000LL;
    }
    
    return result % 10;
}

// Most efficient approach using properties of last non-zero digits
int lastNonZeroDigitEfficient(long long n) {
    // Precomputed values for 0! to 9!
    int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
    
    if (n < 10)
        return dig[n];
    
    // Check if tens digit is odd or even
    if (((n/10)%10)%2 == 0)
        return (6 * dig[n%10] * lastNonZeroDigitEfficient(n/5)) % 10;
    else
        return (4 * dig[n%10] * lastNonZeroDigitEfficient(n/5)) % 10;
}

int main() {
    long long N;
    cin >> N;
    
    cout << lastNonZeroDigitEfficient(N) << endl;
    
    return 0;
}