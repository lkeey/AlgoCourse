#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    vector<long long> factors;
    long long temp = n;
    
    // Factor out all 2s
    while (temp % 2 == 0) {
        factors.push_back(2);
        temp /= 2;
    }
    
    // Check for odd factors from 3 onwards
    for (long long i = 3; i * i <= temp; i += 2) {
        while (temp % i == 0) {
            factors.push_back(i);
            temp /= i;
        }
    }
    
    // If temp is still greater than 1, then it's a prime factor
    if (temp > 1) {
        factors.push_back(temp);
    }
    
    // Output the factors
    for (int i = 0; i < factors.size(); i++) {
        if (i > 0) {
            cout << "*";
        }
        cout << factors[i];
    }
    cout << endl;
    
    return 0;
}