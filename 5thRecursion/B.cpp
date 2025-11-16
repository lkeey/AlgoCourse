#include <iostream>

using namespace std;

int gcd(long long a, long long b) {

    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);

}

int main() {

    long long a, b;

    cin >> a >> b;
    
    long long result = gcd(a, b);
    long long lcm = a * b / result;
    cout << lcm - result;

    return 0;
}