#include <iostream>

using namespace std;

int ledder(int remain, int level) {
    if (remain - (level + 1) >= 0) {
        return ledder(remain - (level + 1), level + 1);
    }
    return level;
}

int main() {

    int n;

    cin >> n;

    cout << ledder(n, 0);

    return 0;
}