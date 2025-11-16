#include <iostream>

using namespace std;

int main() {

    int64_t x, y, n, result;

    cin >> n >> x >> y;

    for (int i=1; i<n; i++) {
        
        result = x + y;
        x = y;
        y = result;

    }

    cout << result;

}