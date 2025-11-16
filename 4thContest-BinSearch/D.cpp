#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 

using namespace std;

int main() {
    long long w, h, n;

    cin >> w >> h >> n;

    long long l=0, r=1;

    while ((r / w) * (r / h) < n) r *= 2;

    while (l < r) {
        long long med = (r + l) / 2;

        if ((med / w) * (med / h) >= n) {
            r = med;
        } else {
            l = med + 1;
        }
    }

    cout << l;

    return 0;
}