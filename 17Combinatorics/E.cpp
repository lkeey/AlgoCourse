#include <iostream>
#include <string>
#include <map>
using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    string word;
    cin >> word;
    
    int n = word.length();
    
    // Count frequency of each character
    map<char, int> frequency;
    for (char c : word) {
        frequency[c]++;
    }
    
    // Calculate the number of distinct permutations
    // Formula: n! / (n1! * n2! * ... * nk!)
    long long result = factorial(n);
    
    for (auto& pair : frequency) {
        result /= factorial(pair.second);
    }
    
    cout << result << endl;
    
    return 0;
}