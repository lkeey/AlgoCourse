#include <iostream>
#include <vector>

using namespace std;

int main() {

    long long n, x, y;

    cin >> n >> x >> y;

    long long l = 0, r = min(x, y)*(n-1);

    while (l < r) {
        long long medium = l + (r-l)/2;

        if (medium/x + medium/y >= n - 1) {
            r = medium;
        } else {
            l = medium + 1;
        } 
    }

    cout << min(x, y) + l;

    return 0;
}
