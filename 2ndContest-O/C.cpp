#include <iostream>
using namespace std;

int main() {
    long long x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    long long dx = x2 - x1;
    long long dy = y2 - y1;
    long long dist2 = dx * dx + dy * dy;

    long long rsum = r1 + r2;
    long long rdiff = r1 - r2;
    if (rdiff < 0) rdiff = -rdiff;

    if (dist2 <= rsum * rsum && dist2 >= rdiff * rdiff) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}