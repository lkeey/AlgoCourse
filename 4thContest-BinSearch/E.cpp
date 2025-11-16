#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 

using namespace std;

int main() {
    long long n, a, ans=0;
    vector<int> nums;

    cin >> n;

    for (int i=0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    for (int k = n - 1; k >= 2; --k) {
        int i = 0; 
        int j = k - 1; 

        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                ans += (j - i);
                j--; 
            } else {
                i++; 
            }
        }
    }

    cout << ans;

    return 0;
}