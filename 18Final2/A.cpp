#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    long long g = gcd(n, m);
    long long result = n / g;
    
    cout << result << endl;
    
    return 0;
}