#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (n <= 2) {
        cout << 0 << "\n";
        return 0;
    }
    
    int up = 1;
    int down = 1;
    
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            up = down + 1;
        } else if (a[i] < a[i-1]) {
            down = up + 1;
        }
    }
    
    int max_length = max(up, down);
    cout << n - max_length << "\n";
    
    return 0;
}