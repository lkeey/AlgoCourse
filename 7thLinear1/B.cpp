#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, k, ma=0, ma_i=-1, ma_j=-1;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (nums[j] + nums[i] > ma) {
                ma = nums[j] + nums[i];
                ma_i = i;
                ma_j = j;
            }
        }
    }

    cout << ma_i + 1 << " " << ma_j + 1;
    
    return 0;
}