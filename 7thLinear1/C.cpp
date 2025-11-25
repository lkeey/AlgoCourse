#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int su = 0;
    for (int i = 0; i <= k; i++)
        su += nums[i];

    if (su == m) {
        cout << 1;
        return 0;
    }

    for (int i = k + 1; i < n; i++) {
        su += nums[i];
        su -= nums[i - k - 1];
        if (su == m) {
            cout << i - k;
            return 0;
        }
    }

    cout << 0;
    return 0;
}
